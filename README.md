# DataStructures

**Herdis Heida J. Gudjohnsen**

## Table of Contents

- [Implemented Abstract Data Structures](#implemented-abstract-data-structures)
- [Folder structure](#folder-structure)
- [Compile program and run program](#compile-program-and-run-program)
- [Time Complexities & Exceptional Cases](#time-complexities--exceptional-cases)

## Implemented Abstract Data Structures

- [Doubly Linked List](/doubly_linked_list/): A linked list where each node has a pointer to both the next and previous node. It uses a sentinel node to simplify edge cases.
- [Dynamically Sized Array](/dynamic_array/): An array that resizes itself when capacity is reached. The growth factor is 2 (capacity doubles when resizing).
- [Stack](/stack/): A last-in-first-out (LIFO) data structure implemented using a dynamically sized array.
- [Heap](/heap/): A binary heap implemented using a dynamically sized array. It maintains the min heap property.
- [Hash Table](/hash_table/): A hash table using separate chaining for collision resolution. It rehashes when the load factor exceeds 1.2.

## Folder structure

Each data structure is located in its own folder and each folder contains:

- a Makefile
- source files (`.cpp` and `.h` files)
- assignment information (`.pdf` files)

## Compile and run program

1. Go into the folder you want to run:

```bash
cd <folder>
```

2. Compile:

```bash
make
```

3. Run:

```bash
./program
```

#### Clean

Remove .o files and the executable:

```bash
make clean
```

## Time Complexities & Exceptional Cases

### Doubly Linked List

Let `n` be the current number of nodes in the list (not counting the sentinel).

The list uses a **sentinel node**. In an empty list:

- `sentinel -> next == sentinel`
- `sentinel -> prev == sentinel`

| Operation                              | Time Complexity | Exceptional cases                                                |
| -------------------------------------- | --------------: | ---------------------------------------------------------------- |
| Default construction                   |            O(1) |                                                                  |
| Copy construction                      |            O(n) |                                                                  |
| Assignment `operator=`                 |            O(n) |                                                                  |
| `begin_node()`                         |            O(1) | Invalid if list is empty (front would be sentinel)               |
| `sentinel_end_node()`                  |            O(1) |                                                                  |
| `insert(cursor, data)` (before cursor) |            O(1) | Invalid if cursor is not a node belonging to this list           |
| `erase(cursor)`                        |            O(1) | Invalid if cursor is sentinel, not in this list or if list empty |
| `predecessor()`                        |            O(1) | Invalid if cursor not in list                                    |
| `successor()`                          |            O(1) | Invalid if cursor not in list                                    |
| `size()`                               |            O(1) |                                                                  |

### Dynamically Sized Array

Let `n` be the current number of elements in the array.

| Operation                   |            Time Complexity | Exceptional cases                                                            |
| --------------------------- | -------------------------: | ---------------------------------------------------------------------------- |
| Default construction        |                       O(1) |                                                                              |
| Copy construction           |                       O(n) |                                                                              |
| Assignment `operator=`      |                       O(n) |                                                                              |
| `push_back(value)`          | Amortized O(1), worst O(n) | Worst case when resizing                                                     |
| `pop_back()`                |                       O(1) | If the array is empty, no effect                                             |
| `insert(index, value)`      |            O(n), best O(1) | best case when inserting at the end, worst when resizing or index very small |
| `erase(index)`              |            O(n), best O(1) | best case when erasing the last element, worst when index is very small      |
| Element access (read/write) |                       O(1) | Invalid if index is out of bounds                                            |
| `resize(new_size)`          |                       O(n) | If new_size < capacity && new_size < size, no effect O(1)                    |
| `reserve(new_cap)`          |                       O(n) | If new_cap ≤ current capacity, no effect                                     |
| `print()`                   |                       O(n) | -                                                                            |

### Stack

Let `n` be the current number of elements in the stack.

| Operation              |            Time Complexity | Exceptional cases                |
| ---------------------- | -------------------------: | -------------------------------- |
| Default construction   |                       O(1) |                                  |
| Copy construction      |                       O(n) |                                  |
| Assignment `operator=` |                       O(n) |                                  |
| `push()`               | Amortized O(1), worst O(n) | Worst case when resizing         |
| `pop()`                |                       O(1) | If the array is empty, no effect |
| `top()`                |                       O(1) | Invalid if empty                 |
| `size()`               |                       O(1) |                                  |

### Heap

Let `n` be the current number of elements in the heap.

| Operation              |                           Time Complexity | Exceptional cases                                                                            |
| ---------------------- | ----------------------------------------: | -------------------------------------------------------------------------------------------- |
| Default construction   |                                      O(1) |                                                                                              |
| Copy construction      |                                      O(n) |                                                                                              |
| Assignment `operator=` |                                      O(n) |                                                                                              |
| `push()`               | Amortized O(log n), best O(1), worst O(n) | Worst when resizing. Heapify step is O(log n). Best case when inserted elem doesn’t move up. |
| `pop()`                |                       O(log n), best O(1) | Invalid if empty. Best case if moved last element already satisfies heap property.           |
| `peak()`               |                                      O(1) | Invalid if empty                                                                             |
| `size()`               |                                      O(1) |                                                                                              |

### HashTable

Let `n = size()` number of items in the Hash Table, `b = bucket_count`, and `α = n/b` (load factor).  
This hash table uses **separate chaining** (linked lists in buckets) and **rehashes** when `n/b >= 1.2`.

- Worst case time complexities occur when all keys hash to the same bucket (bad hash function) and thus all operations become O(n) due to traversing a single linked list of length n.

| Operation                         |           Time Complexity | Exceptional cases / notes                     |
| --------------------------------- | ------------------------: | --------------------------------------------- |
| Default construction              |                      O(b) | Initializes `b` bucket pointer array          |
| Copy construction                 |                  O(n + b) | Copies all nodes + bucket array               |
| Assignment `operator=`            |                  O(n + b) | Clears + copies                               |
| `insert(key, value)`              | Expected O(1), worst O(n) | If key exists, no effect. If rehash, O(n + b) |
| `erase(key)`                      | Expected O(1), worst O(n) | If key doesn't exist, no effect               |
| Element access (get/set existing) | Expected O(1), worst O(n) | If key doesn't exist, no effect               |
| `size()`                          |                      O(1) |                                               |
