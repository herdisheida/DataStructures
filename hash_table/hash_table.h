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
            buckets[i] = 0;
            Node* current = other.buckets[i];
            Node** ptr = &buckets[i];

            while (current) {
                *ptr = new Node(current -> key, current -> value, 0);  // key, value, next
                ptr = &((*ptr) -> next);
                current = current -> next;
                sz++;
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

        rebuild(); // if needed

        size_t idx = get_bucket_index(key);
        buckets[idx] = new Node(key, value, buckets[idx]);
        sz++;
    }

    // remove the given key from the hash table
    void erase(int key) {
        Node* n = find_node(key);
    }

    // provide access to the value associated with a given key
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


    // def rebuild(self):
    //     if self.item_count >= self.bucket_count * 1.2:
    //         old_bucket_list = self.bucket_list

    //         self.bucket_count *= 2
    //         self.bucket_list = [Bucket() for _ in range(self.bucket_count)]
    //         self.item_count = 0  # reset before redistributing

    //         for bucket in old_bucket_list:
    //             node = bucket.head
    //             while node:
    //                 self.insert(node.key, node.data)
    //                 node = node.next

    // when num of items in HashTable reach 120% of the num of buckets
    // double the bucket_count and redistribute all key-value pairs
    void rebuild() {

    }

    // provide the size of the hash table
    size_t size() const {
        return sz;
    }
};


#endif
