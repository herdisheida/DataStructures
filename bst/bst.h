#ifndef BST_H
#define BST_H

#include <cstddef>

using std::size_t;


template<typename T>
struct Node {
    T data;
    Node* right;
    Node* left;

    Node() : data(), right(0), left(0) {}
};

template<typename T>
struct BST {
    Node<T>* root;
    size_t sz;

    // initialize an empty instance
    void init() {
    }

    // clear the instance and free memory
    void destroy() {
    }

    // copy from other instance (deep copy)
    void copy_from(const BST& other) {
    }

    // default constructor
    BST() : root(0), sz(0) {
        init(4);
    }

    // auto destructor
    ~BST() {
        destroy();
    }

    // copy constructor
    BST(const BST& other) : root(0), sz(0){
        copy_from(other);
    }
    
    // assignment (operator=)
    BST& operator=(const BST& other) {
        if (this != &other) {
            destroy();
            copy_from(other);
        }
        return *this;
    }




    // • Find - return the node with the given key. If such a node does not exist, returns a sentinel value.
    // • Lower Bound - return the node with the smallest key which is greater than or equal to the given key, If such a
    // node does not exist, returns a sentinel value.
    // • Upper Bound - return the node with the smallest key which is strictly greater than the given key. If such a node
    // does not exist, returns sentinel value.
    // • Insert - must insert a node with the given key-value pair, returning the newly inserted node. If the key exists
    // already, nothing is inserted and the existing node is returned.
    // • Erase - must remove the given node. If given node is sentinel value, does nothing.
    // • Front - return the node with the minimum key in the tree. If no such node exists, returns a sentinel value.
    // • Back - return the node with the maximum key in the tree. If no such node exists, returns a sentinel value.
    // • Predecessor - return the node before the given node, that is, the node with the largest key which is lower than
    // the given node’s key. If such a node does not exist, or if given node is sentinel value, returns sentinel value.
    // • Successor - return the node after the given node, that is, the node with the smallest key which is higher than the
    // given node’s key. If such a node does not exist, or if given node is sentinel value, returns sentinel value.
    // • Rank - return the index of the node within the tree’s left-to-right order, or in other words, how many nodes have
    // smaller keys than the given node.
    // • k-th Element - return the node with the given index within the tree’s left-to-right order.
    // • Element Access - provide access to reading and writing the value associated with a key, usually directly through
    // the public interface of a node instead of the tree
    // • Size - return the size of the instanc

};

#endif

