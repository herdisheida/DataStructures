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
        // TODO refactor
        // newly inserted elemnt is set at end of arr
        // sift it up until heap property is satisfied

        // find parent of indexed element
        size_t parent = (index - 1) / 2;
        if (parent >= 0) { 
            // For Min-heap
            // If current node is smaller than its parent 
            // Swap both of them and call heapify again 
            if (data[index] < data[parent]) { 
                swap(index, parent); 
                // Recursively heapify the parent node 
                bubbleUp(parent); 
            } 
        } 
    }

    void sinkDown(size_t index) {
        // TODO refactor
        // after removing smallest element
        // the last element is put at the top of the heap-tree
        // sift it down until heap property is satisfied

        size_t curr = index;       // assume curr index is smallest
        size_t l = 2 * index + 1;  // left = 2 * index + 1
        size_t r = 2 * index + 2;  // right = 2 * index + 2

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
        reserve(sz + 1);
        data[sz] = value;

        // increase size of heap
        sz++;
        // sift up new element until heap property is satisfied
        bubbleUp(sz - 1); 
    }

    // remove the smallest element (root) from the heap
    T* pop() {
        // get last element in heap
        T lastElement = data[sz - 1];

        // replace root with last element + delete last element
        T* rootNode = data[0]; // TODO fix memory leak and return smallest by value instead of pointer
        data[0] = lastElement;

        // decrease size of heap
        sz--;

        // sift down new root element until heap property is satisfied
        sinkDown(0);
        return rootNode;
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
