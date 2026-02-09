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





    // insert before cursor, return newly inserted node
    Node<T>* insert(Node<T>* cursor, const T& value) {
        Node<T>* new_node = new Node<T>();
        new_node -> value = value;

        new_node -> next = cursor;
        new_node -> prev = cursor -> prev;

        cursor -> prev -> next = new_node;
        cursor -> prev = new_node;

        sz++;
        return new_node;
    }
    

    // erase the cursor node, returning the node after the erased node
    Node<T>* erase(Node<T>* cursor) {
        assert(sentinel != cursor);  // not allowed

        Node<T>* after = cursor->next;

        cursor -> prev -> next = cursor -> next;  // disconnect before (lhs)
        cursor -> next -> prev = cursor -> prev;  // disconnect after (rhs)

        delete cursor;
        sz--;
        return after;
    }


    // return the first node of the list, not a sentinel node
    Node<T>* front(Node<T>* cursor) const {
        return sentinel -> next;
    }
    // return the last node of the list, a sentinel node
    Node<T>* back(Node<T>* cursor) const {
        return sentinel -> prev;
    }


    // return the node before the cursor node
    Node<T>* predecessor(Node<T>* cursor) const {
        return cursor -> prev;
    }

    // return the node after the cursor node
    Node<T>* successor(Node<T>* cursor) const {
        return cursor -> next;
    }

    // return the size of the instance
    Node<T>* size(Node<T>* cursor) const {
        return sz;
    }


};




void sentinel_end_node() {

}

void begin_node() {

}



void size() {

}





int main() {

    

}