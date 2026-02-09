#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstddef>

using std::cout;
using std::size_t;


template <typename T>
struct Heap {
    T* data;  // arr of heap elems
    std::size_t sz;
    std::size_t cap;

    
    void init(size_t initial_cap) {
        sz = 0;
        cap = (initial_cap <= 0 ? 1 : initial_cap);
        data = new T[cap];
    }

    void destroy() {
        delete[] data;
        data = 0;
        sz = 0;
        cap = 0;
    }

    void copy_from(const Heap& other) {
        sz = other.sz;
        cap = other.cap;
        data = new T[cap];
        for (size_t i = 0; i < sz; i++) data[i] = other.data[i];
    }

    // default constructor
    Heap() : data(0), sz(0), cap(0) {
        init(4);
    }

    // copy constructor
    Heap(const Heap& other) : data(0), sz(0), cap(0) {
        copy_from(other);
    }

    // auto destructor
    ~Heap() {
        destroy();
    }

    // assignment (operator=)
    Heap& operator=(const Heap& other) {
        if (this != &other) {
            destroy();
            copy_from(other);
        }
        return *this;
    }

    // insert an element to the heap
    void push(const T& value) {
        // TODO
    }

    // remove the smallest element from the heap
    void pop() {
        // TODO
    }

    // provide access to the smallest element in the heap
    const T& peek() const {
        // TODO
    }

    // provide the size of the heap
    size_t size() const {
        // TODO
    }
};


#endif
