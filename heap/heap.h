#ifndef HEAP_H
#define HEAP_H

#include <cstddef>

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

    void swap(size_t i, size_t j) {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    void bubbleUp(size_t index) {
        // For min-heap: child < parent => swap
        if (index == 0) return;

        size_t parent = (index - 1) / 2;
        if (data[index] < data[parent]) {
            swap(index, parent);
            bubbleUp(parent);
        }
    }

    void sinkDown(size_t index) {
        // For min-heap: parent > child (smaller child) => swap

        size_t curr = index;       // assume curr index is smallest
        size_t l = 2 * index + 1;  // left = 2 * index + 1
        size_t r = 2 * index + 2;  // right = 2 * index + 2

        if (l >= sz) return;               // no children

        // If left child is smaller than root
        if (l < sz && data[l] < data[curr])
            curr = l;

        // If right child is smaller than smallest so far
        if (r < sz && data[r] < data[curr])
            curr = r;

        // If smallest is not root
        if (curr != index) {
            swap(index, curr);
            // Recursively heapify the affected sub-tree
            sinkDown(curr);
        }
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
        // insert new element at the end of the arr
        if (sz == cap) reserve(cap * 2);
        data[sz] = value;

        bubbleUp(sz); 
        sz++;
    }

    // remove the smallest element (root) from the heap
    T pop() {        
        T ret = data[0];
        sz--;

        if (sz > 0) {
            data[0] = data[sz];
            sinkDown(0);
        }
        return ret;
    }

    // provide access to the smallest element in the heap
    const T& peek() const {
        return data[0];  // top of heap-tree = smallest = first element in arr
    }

    // provide the size of the heap
    size_t size() const {
        return sz;
    }
};


#endif
