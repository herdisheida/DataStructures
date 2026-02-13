#ifndef STACK_H
#define STACK_H

#include <cstddef>

using std::size_t;


template<typename T>
struct Stack {
    T* data;
    size_t sz;
    size_t cap;

    // initialize an empty instance
    void init(size_t initial_cap) {
        sz = 0;
        cap = (initial_cap == 0 ? 1 : initial_cap);
        data = new T[cap];
    }

    // clear the instance and free memory
    void destroy() {
        delete[] data;
        data = 0;
        sz = 0;
        cap = 0;
    }

    // copy from other instance (deep copy)
    void copy_from(const Stack& other) {
        sz = other.sz;
        cap = other.cap;
        data = new T[cap];
        for (size_t i = 0; i < sz; i++) data[i] = other.data[i];
    }

    // ensures there is at least the given amount of slots for values
    void reserve(size_t new_cap) {
        if (new_cap <= cap) return;

        // copy old data to new data 
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < sz; i++) {
            new_data[i] = data[i];
        }

        // delete old and set new values
        delete[] data;
        data = new_data;
        cap = new_cap;
    }

    // default constructor
    Stack() : data(0), sz(0), cap(0) { init(4); }
    // auto destructor
    ~Stack() { destroy(); }
    // copy constructor
    Stack(const Stack& other) : data(0), sz(0), cap(0){ copy_from(other); }
    
    // assignment (operator=)
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            destroy();
            copy_from(other);
        }
        return *this;
    }

    // insert an element on top of the stack.
    void push(const T& value) {
        if (sz == cap) reserve(cap * 2);
        data[sz] = value;
        sz++;
    }

    // remove the top element off of the stack.
    void pop() {
        if (sz > 0) sz--;
    }

    // provide access to the top element of the stack.
    T& top() const {
        return data[sz - 1];
    }

    // provide the size of the stack
    size_t size() const {
        return sz;
    }

};



#endif

