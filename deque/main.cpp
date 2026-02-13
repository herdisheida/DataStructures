#include <cassert>
#include <iostream>
#include <ostream>
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

        if (op == '+') {
            // push front or back
            char dir;
            cin >> dir; // read direction character

            if (dir == 'f') {
                int value;
                cin >> value;
                // push front
                deques[instance].push_front(value);
            }
            else if (dir == 'b') {
                int value;
                cin >> value;
                // push back
                deques[instance].push_back(value);
            }
            else {
                assert(false);
            }
        } else if (op == '-') {
            // pop front or back
            char dir;
            cin >> dir; // read direction character

            if (dir == 'f') {
                // pop front
                deques[instance].pop_front();
            }
            else if (dir == 'b') {
                // pop back
                deques[instance].pop_back();
            }
            else {
                assert(false);
            }
        }

        if (op == 'a') {
            int other;
            cin >> other;
            other--; // change to 0-based index
            // assignment
            deques[instance] = deques[other];
        }
        else if (op == 'f') {
            int value;
            cin >> value;
            // output front
            cout << deques[instance].front() << endl;
        }
        else if (op == 'b') {
            // output back
            cout << deques[instance].back() << endl;
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
