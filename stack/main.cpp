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
            stack[instance].push(value);
        }
        else if (op == '-') {
            // pop back
            cout << stack[instance].pop() << endl;
        }
        else if (op == 't') {
            // erase
            cout << stack[instance].top() << endl;
        }
        else if (op == 's') {
            // set
            cout << stack[instance].size() << endl;
        }
        else {
            assert(false);
        }
    }
}
