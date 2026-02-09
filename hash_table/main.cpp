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
            int key, value;
            cin >> key >> value;
            // insert
            tables[id].insert(key, value);
        }
        else if (op == 'e') {
            int key;
            cin >> key;
            // erase
            tables[id].erase(key);

        }
        else if (op == 'g') {
            int key;
            cin >> key;
            // get
            const HashTable<int>::Node* n = tables[id].find_node(key);
            if (n) cout << n-> value << endl;
            else cout << "-" << endl;

        }
        else if (op == 's') {
            int key, value;
            cin >> key >> value;
            // set
            tables[id][key] = value;
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
