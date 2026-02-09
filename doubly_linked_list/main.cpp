#include <cassert>
#include <cstddef>
#include <iostream>

using std::cout;
using std::cin;

using std::size_t;


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
    T value{};
    Node* prev = nullptr;
    Node* next = nullptr;
};

template<typename T>
struct DoublyLinkedList {
    Node<T>* sentinel = nullptr;
    size_t sz = 0;

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