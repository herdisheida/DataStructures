#include <cassert>
#include <iostream>
#include "heap.h"

using std::cout;
using std::cin;
using std::ws;
using std::endl;


typedef Heap<int> your_heap_type;

your_heap_type heaps[1000];

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int id;
        cin >> id;
        id--; // change to 0-based index
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
            int key, value;
            cin >> key >> value;
            // insert

        }
        else if (op == 'e') {
            int key;
            cin >> key;
            // erase

            
        }
        else if (op == 'g') {
            int key;
            cin >> key;
            // get

            
        }
        else if (op == 's') {
            int key, value;
            cin >> key >> value;
            // set

            
        }

        else if (op == 'z') {
            // size

        }
        else {
            assert(false);
        }
    }

    return 0;
}
