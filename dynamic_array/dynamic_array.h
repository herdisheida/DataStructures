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

    // insert element behind the currently last element
    void push_back(int value) {
    }

    // remove the last element.
    T pop_back() {
        return data[--sz];
    }

    // insert an elem at the given index, other elems must retain relative order
    void insert(size_t index, int value) {
    }

    // remove elem at given index, other elems must retain relative order with no gaps between elements
    T erase(size_t index) {
    }

    // provide access to element at a given index for both read and write operations
    // TODO

    // sets the size of the array to the given value, if it grows then new values get default values
    // There is no requirement that this affects the capacity.
    void resize(size_t new_size) {
        // if new size is smaller.= capacity doesnt change
        // is new size is larger than cap -> double capacity until it is large enough
    }

    // ensures there is at least the given amount of slots for values. This should never affect the elements in the data structure
    void reserve(size_t new_cap) {
        if (new_cap < cap) return;

        // copy old data to new data 
        T new_data = new T[new_cap];
        for (size_t i = 0; i < sz; i++) {
            new_data[i] = data[i];
        }

        // delete old and set new values
        delete[] data;
        data = new_data;
        cap = new_cap;
    }
};


#endif
