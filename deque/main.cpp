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

        if (op == 'a') {
            int other;
            cin >> other;
            other--;
            deques[instance] = deques[other];
        }
        else if (op == '+') {
            char dir; // front or back
            int value;
            cin >> dir >> value;
            if (dir == 'f') deques[instance].push_front(value);
            else if (dir == 'b') deques[instance].push_back(value);
            else assert(false);
        }
        else if (op == '-') {
            char dir; // front or back
            cin >> dir;
            if (dir == 'f') deques[instance].pop_front();
            else if (dir == 'b') deques[instance].pop_back();
            else assert(false);
        }
        else if (op == 'f') {
            cout << deques[instance].front() << endl;
        }
        else if (op == 'b') {
            cout << deques[instance].back() << endl;
        }
        else if (op == 's') {
            cout << deques[instance].size() << endl;
        }
        else {
            assert(false);
        }
    }
    return 0;
}
