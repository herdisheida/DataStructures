#include <cassert>
#include <iostream>
#include "stack.h"

using std::cout;
using std::cin;
using std::endl;
using std::ws;


typedef Stack<int> your_stack_type;

your_stack_type stack[1000];

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
            stack[instance] = stack[other];
        }
        else if (op == '+') {
            int value;
            cin >> value;
            // push back
            stack[instance].push_back(value);
        }
        else if (op == '-') {
            // pop back
            stack[instance].pop_back();
        }
        else if (op == 'i') {
            size_t index;
            int value;
            cin >> index >> value;
            // insert
            stack[instance].insert(index, value);
        }
        else if (op == 'e') {
            size_t index;
            cin >> index;
            // erase
            stack[instance].erase(index);
        }
        else if (op == 'g') {
            int index;
            cin >> index;
            // get
            cout << stack[instance][index] << endl;
        }
        else if (op == 's') {
            size_t index;
            int value;
            cin >> index >> value;
            // set
            stack[instance][index] = value;
        }
        else if (op == 'r') {
            size_t sz;
            cin >> sz;
            // resize
            stack[instance].resize(sz);
        }
        else if (op == 'p') {
            // print
            stack[instance].print();
        }
        else {
            assert(false);
        }
    }
}
