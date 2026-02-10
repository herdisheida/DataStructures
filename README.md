# DataStructures

// TODO finish readme
// TODO ef ég hef tíma template-a types í data structure frá int í hva sem er

## What abstract data structures you implemented and a general summary of how they are implemented. For example, specify the growth factor of your dynamically sized array, specify what kind of self-balancing binary search tree you used, mention any data structures you used to implement other data structures. Imagine that you are documenting your library enough that other programmers can use it.

### What needs to be written in the terminal to compile and run the program. If you provide additional files for the tests, then clarify that and say how to run and verify the tests ran correctly.

### Folder structure

Each data structure is located in its own folder and each folder contains:

- a Makefile
- source files
- optional test input files in `/test_input` folder

### Compile program and run program

1. Navigate to the folder of the data structure you want to run:

```bash
cd <folder>
```

2. Compile the program using make:

```bash
make
```

3. Run the program

|                                           | What to type in Terminal |
| ----------------------------------------- | ------------------------ |
| **Enter input manually in the terminal:** | `./program`              |

### Clean compiled files

To remove compiled object files and the executable:

```bash
make clean
```

## Anything else a student wishes to say. Put it here and not in the Canvas comments!

## Time Complexities & Exceptional Cases

### Doubly Linked List

Let `n` be the current number of nodes in the list (not counting the sentinel).

The list uses a **sentinel node**. In an empty list:

- `sentinel -> next == sentinel`
- `sentinel -> prev == sentinel`

| Operation              | Time Complexity | Exceptional cases |
| ---------------------- | --------------: | ----------------- |
| Default construction   |            O(1) |                   |
| Copy construction      |            O(n) |                   |
| Assignment operator    |            O(n) |                   |
| Front                  |            O(1) |                   |
| Back                   |            O(1) |                   |
| Insert (before cursor) |            O(1) |                   |
| Erase (cursor)         |            O(1) |                   |
| Predecessor            |            O(1) |                   |
| Successor              |            O(1) |                   |
| Size                   |            O(1) |                   |

### Dynamically Sized Array

Let `n` be the current number of elements in the array.

| Operation                   |                 Time Complexity | Exceptional cases                                   |
| --------------------------- | ------------------------------: | --------------------------------------------------- |
| Default construction        |                            O(1) |                                                     |
| Copy construction           |                            O(n) |                                                     |
| Assignment operator         |                            O(n) |                                                     |
| Push back                   | Amortized O(1), worst-case O(n) | Worst case occurs when reallocation is required     |
| Pop back                    |                            O(1) | If the array is empty, operation has no effect      |
| Insert (at index)           |            O(n), best case O(1) | best case occurs when inserting at the end          |
| Erase (at index)            |            O(n), best case O(1) | best case occurs when erasing the last element      |
| Element access (read/write) |                            O(1) | assume index is valid                               |
| Resize                      |                            O(n) |                                                     |
| Reserve                     |                            O(n) | If requested capacity ≤ current capacity, no effect |
| Print                       |                            O(n) |                                                     |

### Heap

Let `n` be the current number of elements in the heap.

| Operation            | Time Complexity | Exceptional cases |
| -------------------- | --------------: | ----------------- |
| Default construction |            O(1) |                   |
| Copy construction    |            O(n) |                   |
| Assignment operator  |            O(n) |                   |
| Push                 |                 |                   |
| Pop                  |                 |                   |
| Insert               |                 |                   |
| Peak                 |                 |                   |
| Size                 |            O(1) |                   |

### HashTable

Let `n = size()` number of items in the Hash Table, `b = bucket_count`, and `α = n/b` (load factor).  
This hash table uses **separate chaining** (linked lists in buckets) and **rehashes** when `n/b >= 1.2`.

| Operation                         |           Time Complexity | Exceptional cases / notes                                                                           |
| --------------------------------- | ------------------------: | --------------------------------------------------------------------------------------------------- |
| Default construction              |                      O(b) | Allocates `b` bucket pointers and initializes                                                       |
| Copy construction                 |                  O(n + b) |                                                                                                     |
| Assignment operator               |                  O(n + b) |                                                                                                     |
| Insert                            | Expected O(1), worst O(n) | If key already exists, no effect. If rehash happens -> O(n + b) for that insertion (amortized O(1)) |
| Erase                             | Expected O(1), worst O(n) | Input guarantees key exists                                                                         |
| Element access (get/set existing) | Expected O(1), worst O(n) | Input guarantees key exists                                                                         |
| Size                              |                      O(1) |                                                                                                     |
