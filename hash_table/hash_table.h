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

    
};


#endif
