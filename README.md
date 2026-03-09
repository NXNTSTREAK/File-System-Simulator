# NXNT

A tiny in-memory filesystem built in C++.

NXNT is a small project that simulates a filesystem using a tree data structure.  
It does not interact with your real disk. Everything exists only in memory and disappears once the program exits.

The goal of this project was to practice working with **trees, recursion, and path parsing** in a practical way instead of solving isolated algorithm problems.

---

## Overview

NXNT behaves like a very small terminal filesystem.

You can create directories and files, navigate between folders, move items, delete them, and visualize the structure using a tree view.

All operations happen inside the program’s memory.

Key characteristics:

- In-memory filesystem
- Tree-based structure
- Simple command interface
- No external dependencies
- Lightweight single program

---

## Example Terminal

When you run the program, you will see a prompt like:

```
nxnt:root/$
```

You can then run filesystem-like commands.

Example session:

```
nxnt:root/$ mkdir code projects
nxnt:root/$ touch todo.txt
nxnt:root/$ ls

code/  projects/  todo.txt

nxnt:root/$ cd code
nxnt:root/code/$ touch main.cpp
nxnt:root/code/$ cd ..
nxnt:root/$ tree
```

Output:

```
root
├── code
│   └── main.cpp
├── projects
└── todo.txt
```

---

## Supported Commands

NXNT currently supports the following commands:

```
mkdir <dir>        create a directory
touch <file>       create a file
rm <file>          delete a file
rm -r <dir>        delete a directory recursively

cd <dir>           move into a directory
cd ..              move to parent directory
cd /               go to root directory

ls                 list files and directories
tree               display the filesystem structure
pwd                print current directory

mv <src> <dest>    rename or move a file/directory
where <name>       search for a file in the filesystem

echo <text>        print text

history            show previously used commands
clear              clear the terminal
whoami             show current user
help               list available commands
exit               quit the program
```

---

## Installation

Compile using a C++ compiler.

```
g++ main.cpp -o nxnt
./nxnt
```

No external libraries or build systems are required.

---

## Design

The filesystem is implemented using a **tree structure**.

Each node represents either a file or a directory.

Important features of the implementation:

- Parent pointers for navigation
- Recursive traversal for operations like `tree` and `where`
- Path parsing for directory navigation
- Alphabetically sorted children
- Memory managed dynamically

---

## Current Limitations

This project is intentionally minimal.

Some features are not implemented yet:

- Files do not store content
- No `cat` command
- Limited `mv` functionality
- No tab completion
- Filesystem state is not saved to disk

All data is lost when the program exits.

---

## Future Improvements

Possible improvements include:

- Add file content support
- Implement `cat` command
- Add copy (`cp`) functionality
- Save and load filesystem state
- Improve command parsing
- Add tab completion

---

## Purpose

This project was built as a learning exercise to better understand:

- Tree data structures
- Recursive algorithms
- Filesystem concepts
- Command parsing
- Memory management in C++

---

## License

This project is open for experimentation and learning.

Feel free to modify it, extend it, or use it as a reference for similar projects.