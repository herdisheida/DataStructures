#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>

using std::size_t;


template<typename T>
struct DynamicArray {
    list = new List<T>;
    size_t sz;

    // default constructor
    DynamicArray() : list(0), sz(0) {


    }

    // auto destructor
    ~DynamicArray() {

    }

    // copy constructor (deep copy)
    DynamicArray(const DynamicArray& other) : list(0), sz(0) {

    }

    // assignment (operator=) (deep copy)
    DynamicArray& operator=(const DynamicArray& other) {

    }

    // remove and delete all elem
    void clear() {

        sz = 0;
    }

    // return the size of the instance
    size_t size() const {
        return sz;
    }
};


#endif
