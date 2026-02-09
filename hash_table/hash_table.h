#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <cstddef>

using std::cout;
using std::hash;
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

    // get the bucket index for a given key
    size_t get_bucket_index(int key) const {
        return hash<int>()(key) % bucket_count;
    }

    Node* find_node(int key) const {
        size_t idx = get_bucket_index(key);
        Node* curr = buckets[idx];
        while (curr) {
            if (curr -> key == key) return curr;
            curr = curr -> next;
        }
        return 0;
    }

    // initialize an empty instance
    void init(size_t bucket_count) {
        bucket_count = (bucket_count < 1 ? 1 : bucket_count);
        buckets = new Node*[bucket_count];
        for (size_t i = 0; i < bucket_count; i++) buckets[i] = 0;
        sz = 0;
    }

    // clear the nodes only (keep the bucket array)
    void clear_nodes_only() {
        for (size_t i = 0; i < bucket_count; ++i) {
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

    // insert a key-value pair to the hash table. If they key is present, then nothing is inserted
    void insert(int key, const T& value) {
        if (find_node(key)) return;

        ensure_capacity(); // if needed

        size_t idx = get_bucket_index(key);
        buckets[idx] = new Node(key, value, buckets[idx]);
        sz++;
    }

    // remove the given key from the hash table
    void erase(int key) {
        size_t idx = get_bucket_index(key);
        Node* curr = buckets[idx];
        Node* prev = 0;

        while (curr) {
            if (curr -> key == key) {
                if (prev) prev -> next = curr -> next;
                else buckets[idx] = curr -> next;  // curr was the first elem in bucket

                delete curr;
                sz--;
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
        size_t idx = get_bucket_index(key);
        buckets[idx] = new Node(key, T(), buckets[idx]);
        sz++;
        return buckets[idx] -> value;
    }


    // re-hash to new bucket count
    void rehash(size_t new_bucket_count) {
        Node** old_buckets = buckets; // keep copy of old key-value pairs
        

        // reset all
        bucket_count *= 2;
        init(new_bucket_count); // resets sz

        // re-add items to bigger capacity bucket list
        for (Node** bucket : old_buckets) {
            Node* n = bucket;
            while (n) {
                insert(n -> key, n -> value);
                n = n -> next;
            }
        
        delete[] old_buckets;
        }
    }

    // when num of items in HashTable reach 120% of the num of buckets
    void ensure_capacity() {
        if (sz >= bucket_count * 1.2) {
            rehash(bucket_count * 2);
        }
    }

    // provide the size of the hash table
    size_t size() const {
        return sz;
    }
};


#endif
