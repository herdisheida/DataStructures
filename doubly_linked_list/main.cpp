#include <cassert>
#include <cstddef>
#include <iostream>

using std::cout;
using std::cin;


// TODO : 
// You must implement the: 
    // default constructor
    // copy constructor
    // assignment (operator=)
    // front
    // back
    // insert
    // erase
    // size
    // successor
    // predecessor



template<typename T>
struct Node {
    T value;
    Node* prev;
    Node* next;
};

template<typename T>
struct DoublyLinkedList {
    Node<T>* sentinel;
    size_t size;

    // constructor
    DoublyLinkedList() {
        sentinel = new Node<T>();
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
    }

    
};




void sentinel_end_node() {

}

void begin_node() {

}

void insert() {

}

void erase() {

}

void successor() {

}

void predecessor() {

}

void size() {

}





int main() {

    

}