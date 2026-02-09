#include <cassert>
#include <cstddef>


using std::size_t;



template<typename T>
struct Node {
    T data{};
    Node* prev = nullptr;
    Node* next = nullptr;
};

template<typename T>
struct DoublyLinkedList {
    Node<T>* sentinel = nullptr;
    size_t sz = 0;

    // default constructor
    DoublyLinkedList() {
        sentinel = new Node<T>();
        sentinel -> next = sentinel;
        sentinel -> prev = sentinel;
    }

    // auto destructor
    ~DoublyLinkedList() {
        clear();
        delete sentinel;
        sentinel = nullptr;
    }

    // copy constructor (deep copy)
    DoublyLinkedList(const DoublyLinkedList& other) : DoublyLinkedList() {
        for (Node<T>* i = other.sentinel -> next; i != other.sentinel; i = i -> next) {
            this -> insert(sentinel, i -> data);
        }
    }

    // assignment (operator=) (deep copy)
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this == &other) return *this;
        this -> clear();
        for (Node<T>* i = other.sentinel -> next; i != other.sentinel; i = i -> next) {
            this -> insert(sentinel, i -> data);
        }
        return *this;
    }

    // remove and delete all nodes
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
        assert(sentinel != cursor);  // not allowed

        Node<T>* after = cursor->next;

        cursor -> prev -> next = cursor -> next;  // disconnect before (lhs)
        cursor -> next -> prev = cursor -> prev;  // disconnect after (rhs)

        delete cursor;
        sz--;
        return after;
    }

    // front : return the first node of the list, not a sentinel node
    Node<T>* begin_node() const {
        return sentinel -> next;
    }
    // back : return the last node of the list, a sentinel node
    Node<T>* sentinel_end_node() const {
        return sentinel;
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
    size_t size() const {
        return sz;
    }


};




int main() {

    

}