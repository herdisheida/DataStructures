#include <cassert>
#include <iostream>
#include "hash_table.h"

using std::cout;
using std::cin;
using std::ws;

typedef HashTable<int> your_table_type;

your_table_type vecs[1000];

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

        }
        else if (op == 'i') {
            size_t index;
            int value;
            cin >> index >> value;
            // insert
        }
        else if (op == 'e') {
            size_t index;
            cin >> index;
            // erase
        }
        else if (op == 'g') {
            int index;
            cin >> index;
            // get
        }
        else if (op == 's') {
            size_t index;
            int value;
            cin >> index >> value;
            // set

        }

        else if (op == 'z') {
            // print
        }
        else {
            assert(false);
        }
    }
}
