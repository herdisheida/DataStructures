#include <cassert>
#include <iostream>
#include "deque.h"

using std::cout;
using std::cin;
using std::endl;
using std::ws;


typedef Deque<int> your_deque_type;

your_deque_type deques[1000];

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
            deques[instance] = deques[other];
        }
        else if (op == '+') {
            int value;
            cin >> value;
            // push
            deques[instance].push(value);
        }
        else if (op == '-') {
            // pop
            deques[instance].pop();
        }
        else if (op == 't') {
            // top
            cout << deques[instance].top() << endl;
        }
        else if (op == 's') {
            // size
            cout << deques[instance].size() << endl;
        }
        else {
            assert(false);
        }
    }
}
