#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <cstddef>

using std::cout;
using std::size_t;
    

template<typename T>
struct HashTable {
    struct Node {
        T key;
        T value;
        Node* next;
        Node(T k, T v, Node* n) : key(k), value(v), next(n) {}
    };

    Node** buckets;
    size_t bucket_count;
    size_t sz;

    // default constructor

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
