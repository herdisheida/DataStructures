#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <cstddef>

using std::cout;
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

    // delete all elem
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

    // insert an elem at the given index, other elems must retain relative order
    void insert(size_t index, int value) {
        if (sz == cap) reserve(cap * 2);

        // create an empty slot to place inserted value
        for (size_t i = sz; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        sz++;
    }

    // insert element behind the currently last element
    void push_back(int value) {
        insert(sz, value);
    }

    // remove the last element
    void pop_back() {
        sz--;
    }

    // remove elem at given index, other elems must retain relative order with no gaps between elements
    void erase(size_t index) {
        for (size_t i = index + 1; i < sz; i++) {
            data[i - 1] = data[i];
        }
        sz--;
    }

    // provide access to element at a given index for both read and write operations
    // TODO

    // sets the size of the array to the given value, if it grows then new values get default values
    // There is no requirement that this affects the capacity.
    void resize(size_t new_size) {
        if (new_size > cap) {
            size_t new_cap = cap;
            while (new_size < new_cap) new_cap *= 2;
            reserve(new_cap);
        }
        if (new_size > sz) {
            // new slot has default value = 0
            for (size_t i = sz; i < new_size; i++) data[i] = 0;
        }
        sz = new_size;
    }


    // print this instance
    void print() const {
        cout << sz << "\n";
        for (size_t i = 0; i < sz; i++) {
            if (i) cout << " ";  // space between elems
            cout << data[i];
        }
        cout << "\n";
    }
};


#endif
