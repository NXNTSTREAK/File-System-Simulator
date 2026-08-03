# NXNT

A tiny in-memory filesystem built in C++.

NXNT is a small project that simulates a filesystem using a tree data structure.
It does not interact with your real disk. Everything exists only in memory and disappears once the program exits.

The goal of this project was to practice working with trees, recursion, and path parsing in a practical way instead of solving isolated algorithm problems.

## Overview

NXNT behaves like a very small terminal filesystem.

You can create directories and files, navigate between folders, delete them, and list their contents through a simple command-line interface.

All operations happen inside the program's memory.

Key characteristics:

- In-memory filesystem
- Tree-based structure
- Command-line interface
- No external dependencies
- Lightweight single program

---

## Example Terminal

When you run the program, you will see a prompt like:

```text
nxnt:root/$
```

You can then run filesystem-like commands.

Example session:

```text
nxnt:root/$ mkdir code
nxnt:root/$ mkdir projects
nxnt:root/$ touch todo.txt

nxnt:root/$ ls
code/    projects/    todo.txt

nxnt:root/$ cd code
nxnt:root/code/$ touch main.cpp

nxnt:root/code/$ cd ..
```

---

## Supported Commands

NXNT currently supports the following commands:

```text
mkdir <dir>      create a directory
touch <file>     create a file

cd <dir>         move into a directory
cd ..            move to parent directory

ls               list files and directories
```

---

## Installation

Compile using a C++17 compiler.

```bash
g++ -std=c++17 main.cpp -o nxnt
./nxnt
```

No external libraries or build systems are required.

---

## Design

The filesystem is implemented using a tree structure.

Each node represents either a file or a directory.

Important features of the implementation:

- Tree-based filesystem hierarchy
- Parent pointers for directory navigation
- Dynamic memory management using smart pointers
- Simple command parser
- Separate classes for filesystem components

---

## Project Structure

The project is organized into separate components.

```text
.
├── VNode.hpp          # Base class for filesystem nodes
├── Directory.hpp      # Directory implementation
├── File.hpp           # File implementation
├── FileSystem.hpp     # Filesystem operations
├── main.cpp           # Interactive CLI
└── README.md
```

---

## What's New in V2

Compared to the original version, this implementation introduces a cleaner internal design.

### Better Project Structure

Instead of keeping the entire filesystem inside a single source file, the project is now split into multiple classes with clear responsibilities.

This makes the code easier to read, maintain, and extend.

### Object-Oriented Design

Files and directories now inherit from a common `VNode` base class.

This provides a shared interface for filesystem nodes while allowing each class to handle its own behavior.

### Modern C++ Memory Management

The project now uses C++ smart pointers to manage dynamically allocated objects.

Parent-child relationships are handled automatically, removing the need for manual memory management while keeping directory navigation simple.

---

## Current Limitations

This project is intentionally minimal.

Some features are not implemented yet:

- Files do not store content
- No recursive tree visualization
- No file search
- No moving or renaming files and directories
- No filesystem persistence

All data is lost when the program exits.

---

## Future Improvements

Possible improvements include:

- Add file content support
- Implement `cat`
- Add recursive `tree` visualization
- Add search functionality
- Implement `mv` and `cp`
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
- Object-oriented programming
- Memory management in modern C++

---

## License

This project is open for experimentation and learning.

Feel free to modify it, extend it, or use it as a reference for similar projects.
