#ifndef DEQUE_H
#define DEQUE_H

#include <cstddef>

using std::size_t;


template<typename T>
struct Deque {
    T* data;
    size_t sz;
    size_t cap;
    size_t head; // index of first elem


    // return the index of the x-th elem
    size_t idx(size_t x) const {
        return (head + x) % cap;
    }

    // initialize an empty instance
    void init(size_t initial_cap) {
        sz = 0;
        cap = (initial_cap == 0 ? 1 : initial_cap);
        data = new T[cap];
        head = 0;
    }

    // clear the instance and free memory
    void destroy() {
        delete[] data;
        data = 0;
        sz = 0;
        cap = 0;
        head = 0;
    }

    // copy from other instance (deep copy)
    void copy_from(const Deque& other) {
        sz = other.sz;
        cap = other.cap;
        head = 0;
        data = new T[cap];
        for (size_t i = 0; i < sz; i++) data[i] = other.data[other.idx(i)];
    }

    // ensures there is at least the given amount of slots for values
    void reserve(size_t new_cap) {
        if (new_cap <= cap) return;

        // copy old data to new data 
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < sz; i++) {
            new_data[i] = data[idx(i)];
        }

        // delete old and set new values
        delete[] data;
        data = new_data;
        cap = new_cap;
        head = 0;
    }

    // default constructor
    Deque() : data(0), sz(0), cap(0) { init(4); }
    // auto destructor
    ~Deque() { destroy(); }
    // copy constructor
    Deque(const Deque& other) : data(0), sz(0), cap(0){ copy_from(other); }
    
    // assignment (operator=)
    Deque& operator=(const Deque& other) {
        if (this != &other) {
            destroy();
            copy_from(other);
        }
        return *this;
    }

    // insert an element to the front of the deque
    void push_front(const T& value) {
        if (sz == cap) reserve(cap * 2);
        head = (head == 0 ? cap - 1 : head - 1);
        data[head] = value;
        sz++;
    }

    // insert an element to the back of the deque
    void push_back(const T& value) {
        if (sz == cap) reserve(cap * 2);
        data[idx(sz)] = value;
        sz++;
    }

    // remove the front element off of the deque
    void pop_front() {
        if (sz > 0) {
            head = (head + 1) % cap;
            sz--;
        }
    }

    // remove the back element off of the deque
    void pop_back() {
        if (sz > 0) sz--;
    }

    // provide access to the front element of the deque
    const T& front() const { return data[head]; }
    // provide access to the back element of the deque
    const T& back() const { return data[idx(sz - 1)]; }

    // provide the size of the Deque
    size_t size() const {
        return sz;
    }
};

#endif

