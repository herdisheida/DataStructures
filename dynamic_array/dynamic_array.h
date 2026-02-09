#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>

using std::size_t;
    

template<typename T>
struct DynamicArray {
    T* data;
    size_t sz;   // elem count used
    size_t cap;  // capacity (space in array)


    // initialize an empty instance
    void init_empty(size_t initial_cap) {
        sz = 0;
        cap = (initial_cap <= 0 ? 1 : initial_cap);
        data = new T[cap];
    }

    // delete all elem, but keep the capacity
    void clear() {
        delete[] data;
        data = 0;
        sz = 0;
        cap = 0;
    }

    // copy from other instance (deep copy)
    void copy_from(const DynamicArray& other) {
        sz = other.sz;
        cap = other.cap;
        data = new T[cap];
        for (size_t i = 0; i < sz; i++) data[i] = other.data[i];
    }

    // default constructor
    DynamicArray() : data(0), sz(0), cap(0) {
        init_empty(4);
    }

    // auto destructor
    ~DynamicArray() {
        clear();
    }

    // copy constructor (deep copy)
    DynamicArray(const DynamicArray& other) : data(0), sz(0), cap(0) {
        copy_from(other);
    }

    // assignment (operator=) (deep copy)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            clear();
            copy_from(other);
        }
        return *this;
    }


    // return the size of the instance
    size_t size() const {
        return sz;
    }
};


#endif
