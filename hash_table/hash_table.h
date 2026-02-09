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
            Node* cur = buckets[i];
            while (cur) {
                Node* nxt = cur->next;
                delete cur;
                cur = nxt;
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
    // insert()

    // remove the given key from the hash table
    // erase()

    // provide access to the value associated with a given key
    // element access(key)

    // provide the size of the hash table
    // size()
};


#endif
