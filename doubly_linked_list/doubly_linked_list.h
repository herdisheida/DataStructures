#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <cstddef>

using std::size_t;


template<typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node() : data(), prev(0), next(0) {}
};

template<typename T>
struct DoublyLinkedList {
    Node<T>* sentinel;
    size_t sz;

    // default constructor
    DoublyLinkedList() : sentinel(0), sz(0) {
        sentinel = new Node<T>();
        sentinel -> next = sentinel;
        sentinel -> prev = sentinel;
    }

    // auto destructor
    ~DoublyLinkedList() {
        clear();
        delete sentinel;
        sentinel = 0;
    }

    // copy constructor
    DoublyLinkedList(const DoublyLinkedList& other) : sentinel(0), sz(0) {
        for (Node<T>* i = other.sentinel -> next; i != other.sentinel; i = i -> next) {
            this -> insert(sentinel, i -> data);  // append
        }
    }

    // assignment (operator=)
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this == &other) return *this;
        this -> clear();
        for (Node<T>* i = other.sentinel -> next; i != other.sentinel; i = i -> next) {
            this -> insert(sentinel, i -> data);  // append
        }
        return *this;
    }

    // clear the list, leave sentinel node only
    void clear() {
        Node<T>* cur = sentinel -> next;
        while (cur != sentinel) {
            Node<T>* nxt = cur -> next;
            delete cur;
            cur = nxt;
        }
        sentinel -> next = sentinel;
        sentinel -> prev = sentinel;
        sz = 0;
    }

    // insert before cursor, return newly inserted node
    Node<T>* insert(Node<T>* cursor, const T& data) {
        Node<T>* new_node = new Node<T>();
        new_node -> data = data;

        new_node -> next = cursor;
        new_node -> prev = cursor -> prev;

        cursor -> prev -> next = new_node;
        cursor -> prev = new_node;

        sz++;
        return new_node;
    }
    
    // erase the cursor node, returning the node after the erased node
    Node<T>* erase(Node<T>* cursor) {
        Node<T>* after = cursor->next;

        cursor -> prev -> next = cursor -> next;  // disconnect before (lhs)
        cursor -> next -> prev = cursor -> prev;  // disconnect after (rhs)

        delete cursor;
        sz--;
        return after;
    }

    // front : return the first node of the list, not a sentinel node
    Node<T>* begin_node() {
        return sentinel -> next;
    }
    // back : return the last node of the list, a sentinel node
    Node<T>* sentinel_end_node() {
        return sentinel;
    }

    // return the node before the cursor node
    Node<T>* predecessor(Node<T>* cursor) {
        return cursor -> prev;
    }

    // return the node after the cursor node
    Node<T>* successor(Node<T>* cursor) {
        return cursor -> next;
    }

    // return the size of the instance
    size_t size() const {
        return sz;
    }
};


#endif
