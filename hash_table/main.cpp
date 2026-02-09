#include <cassert>
#include <iostream>
#include "hash_table.h"

using std::cout;
using std::cin;
using std::ws;
using std::endl;


typedef HashTable<int> your_table_type;

your_table_type tables[1000];

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
            tables[id] = tables[other];
        }
        else if (op == 'i') {
            size_t index;
            int value;
            cin >> index >> value;
            // insert
            tables[id].insert(k, v);
        }
        else if (op == 'e') {
            size_t index;
            cin >> index;
            // erase
            tables[id].erase(k);

        }
        else if (op == 'g') {
            int index;
            cin >> index;
            // get
            const HashTable::Node* n = tables[id].find(k);
            if (n) cout << n-> value << endl;
            else cout << "-" << endl;

        }
        else if (op == 's') {
            size_t index;
            int value;
            cin >> index >> value;
            // set
            tables[id][k] = v;
        }

        else if (op == 'z') {
            // size
            cout << tables[id].size() << endl;
        }
        else {
            assert(false);
        }
    }

    return 0;
}
