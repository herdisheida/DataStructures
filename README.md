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

|                                                | What to type in Terminal               |
| ---------------------------------------------- | -------------------------------------- |
| **Enter input manually in the terminal:**      | `./program`                            |
| **Run the program with test input.txt files:** | `./program < input_tests/test<nr>.txt` |

### Clean compiled files

To remove compiled object files and the executable:

```bash
make clean
```

## Anything else a student wishes to say. Put it here and not in the Canvas comments!
