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
            heaps[id] = heaps[other];
        }
        else if (op == '+') {
            int value;
            cin >> value;
            // push
            heaps[id].push(value);
        }
        else if (op == '-') {
            // pop
            heaps[id].pop();
        }
        else if (op == 'p') {
            // peek
            cout << heaps[id].peek() << endl;
        }
        else if (op == 's') {
            // size
            cout << heaps[id].size() << endl;
        }
        else {
            assert(false);
        }
    }

    return 0;
}
