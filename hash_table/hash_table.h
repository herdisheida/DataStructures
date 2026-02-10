#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <cstddef>

using std::cout;
using std::size_t;
    


template <typename T>
struct HashTable {
    struct Node {
        int key;
        T value;
        Node* next;
        Node(int k, const T& v, Node* n) : key(k), value(v), next(n) {}
    };

    Node** buckets;
    size_t bucket_count;
    size_t sz;


    // hash function for keys
    size_t _hash_key(int key) const {
        unsigned int x = (unsigned int) key;
        return (size_t) (x * 2654435761u);
    }

    // get the bucket index for a given key
    size_t _get_bucket_index(int key) const {
        if (bucket_count == 0) return 0;  // avoid division by zero
        return _hash_key(key) % bucket_count;

    }

    Node* find_node(int key) const {
        size_t idx = _get_bucket_index(key);
        Node* curr = buckets[idx];
        while (curr) {
            if (curr -> key == key) return curr;
            curr = curr -> next;
        }
        return 0;
    }

    // initialize an empty instance
    void init(size_t new_bucket_count) {
        this -> bucket_count = new_bucket_count < 1 ? 8 : new_bucket_count;

        buckets = new Node*[this -> bucket_count];
        for (size_t i = 0; i < this -> bucket_count; i++) buckets[i] = 0;
        sz = 0;
    }

    // clear the nodes only (keep the bucket array)
    void clear_nodes_only() {
        for (size_t i = 0; i < bucket_count; i++) {
            Node* curr = buckets[i];
            while (curr) {
                Node* nxt = curr -> next;
                delete curr;
                curr = nxt;
            }
            buckets[i] = 0;
        }
        sz = 0;
    }

    // clear the instance and free memory
    void destroy() {
        if (!buckets) return;
        clear_nodes_only();
        delete[] buckets;
        buckets = 0;
        bucket_count = 0;
        sz = 0;
    }

    // copy from other instance (deep copy)
    void copy_from(const HashTable& other) {
        bucket_count = other.bucket_count;
        sz = other.sz;
        buckets = new Node*[bucket_count];

        for (size_t i = 0; i < bucket_count; i++) {
            Node* curr = other.buckets[i];  // curr node in other bucket list
            Node* tail = 0;
            buckets[i] = 0;

            while (curr) {
                Node* n = new Node(curr -> key, curr -> value, 0);

                // add n to the end of this bucket list
                if (!buckets[i]) {
                    buckets[i] = n;
                    tail = n;
                } else {
                    tail->next = n;
                    tail = n;
                }
                curr = curr->next;
            }
        }
    }

    // when num of items in HashTable reach 120% of the num of buckets
    void ensure_capacity() {
        if (sz * 10 >= bucket_count * 12) {
            rehash(bucket_count * 2);
        }
    }

    // default constructor
    HashTable() : buckets(0), bucket_count(0), sz(0) {
        init(8);
    }

    // copy constructor
    HashTable(const HashTable& other) : buckets(0), bucket_count(0), sz(0) {
        copy_from(other);
    }

    // auto destructor
    ~HashTable() {
        destroy();
    }

    // assignment (operator=)
    HashTable& operator=(const HashTable& other) {
        if (this != &other) {
            destroy();
            copy_from(other);
        }
        return *this;
    }

    void _raw_insert(int key, const T& value) {
        size_t idx = _get_bucket_index(key);
        buckets[idx] = new Node(key, value, buckets[idx]);
        sz++;
    }

    // insert a key-value pair to the hash table
    void insert(int key, const T& value) {
        if (find_node(key)) return;  // key already exists
        ensure_capacity(); // if needed
        _raw_insert(key, value);
    }

    // remove the given key from the hash table
    void erase(int key) {
        if (!buckets) return;
        if (!find_node(key)) return;  // key doesn't exist

        size_t idx = _get_bucket_index(key);
        Node* curr = buckets[idx];
        Node* prev = 0;

        while (curr) {
            if (curr -> key == key) {
                if (prev) prev -> next = curr -> next;
                else buckets[idx] = curr -> next;  // curr was the first elem in bucket

                delete curr;
                sz--;
                return;
            }
            prev = curr;
            curr = curr -> next;
        }
    }

    // get ref to value by key
    // if no key add new value with key
    T& operator[](int key) {
        Node* n = find_node(key);

        // return value
        if (n) return n -> value;

        // set new value
        ensure_capacity();
        size_t idx = _get_bucket_index(key);
        buckets[idx] = new Node(key, T(), buckets[idx]);
        sz++;
        return buckets[idx] -> value;
    }


    // re-hash to new bucket count
    void rehash(size_t new_bucket_count) {
        Node** old_buckets = buckets; // keep copy of old key-value pairs
        size_t old_bucket_count = bucket_count;

        // new empty hash table
        buckets = 0;
        init(new_bucket_count);  // initalizes bucket_count, buckets and sz

        // re-hash items to new table and delete old nodes
        for (size_t i = 0; i < old_bucket_count; i++) {
            Node* n = old_buckets[i];
            while (n) {                
                _raw_insert(n -> key, n -> value);

                Node* nxt = n -> next;
                delete n;  // free old node
                n = nxt;
            }
        }
        delete[] old_buckets;
    }

    // provide the size of the hash table
    size_t size() const {
        return sz;
    }
};


#endif
