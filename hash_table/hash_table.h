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

    // default constructor
    HashTable(size_t bucket_count = 8) : buckets(0), bucket_count(bucket_count), sz(0) {
        bucket_count = (bucket_count < 1 ? 1 : bucket_count);
        buckets = new Node*[bucket_count];
        for (std::size_t i = 0; i < bucket_count; i++) buckets[i] = 0;
        sz = 0;
    }

    // copy constructor

    // assignment (operator=)


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
