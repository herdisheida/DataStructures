#include <cassert>
#include <iostream>
#include "dynamic_array.h"

using std::cout;
using std::cin;
using std::ws;


typedef DynamicArray<int> your_array_type;

your_array_type vecs[1000];

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int instance;
        cin >> instance;
        instance--; // change to 0-based index
        // consume whitespace before reading character, otherwise we get a space
        cin >> ws;
        char op;
        cin >> op; // read operation character

        if (op == 'a') {
            int other;
            cin >> other;
            other--; // change to 0-based index
            // assignment
            vecs[instance] = vecs[other];
        }
        else if (op == '+') {
            int value;
            cin >> value;
            // push back
            vecs[instance].push_back(value);
        }
        else if (op == '-') {
            // pop back
            vecs[instance].pop_back();
        }
        else if (op == 'i') {
            int index, value;
            cin >> index >> value;
            // insert
            vecs[instance].insert(index, value);
        }
        else if (op == 'e') {
            int index;
            cin >> index;
            // erase
            vecs[instance].erase(index);
        }
        else if (op == 'g') {
            int index;
            cin >> index;
            // get
            vecs[instance][index];
        }
        else if (op == 's') {
            int index, value;
            cin >> index >> value;
            // set
            vecs[instance][index] = value;
        }
        else if (op == 'r') {
            int sz;
            cin >> sz;
            // resize
            vecs[instance].resize(sz);
        }
        else if (op == 'p') {
            // print
            vecs[instance].print();
        }
        else {
            assert(false);
        }
    }
}
