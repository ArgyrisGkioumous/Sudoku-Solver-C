# Data Structures: Array Operations & Search Benchmarks

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-lightgrey.svg)]()

A modular C system implementing standard array manipulation algorithms, dynamic memory allocation, and benchmarking. Built as part of the **Data Structures** curriculum at the **University of West Attica (UNIWA)**.

---

## Overview

This project demonstrates pointer-based array operations without using bracket notation (`[]`), adhering strictly to dynamic memory management principles and memory safety. 

### Key Features
- **Dynamic Allocation**: Allocates dynamic memory for integer arrays based on user input.
- **Pseudo-Random Generation**: Populates arrays with random integers within the range `[30, 500]`.
- **Search Algorithms**:
  - **Linear / Sequential Search**: Iterative search through raw memory addresses.
  - **Binary Search**: Fast lookup implemented over sorted data copies.
- **Sorting & Merging**:
  - High-performance array sorting (e.g., QuickSort / MergeSort).
  - Merging two sorted arrays of size $N$ into a single sorted array of size $2N$.
- **File I/O Persistence**: Functions to save current array states to disk and load them back into memory.
- **Performance Benchmarking (Optional Bonus)**: Empirical execution analysis comparing Linear vs. Binary search performance by measuring total element reads required to find all array entries.

---

## Technical Constraints & Principles

- **No Bracket Notation (`[]`)**: All array indexing and traversal are strictly executed using explicit pointer arithmetic (e.g., `*(arr + i)`).
- **No Global Variables**: State is passed explicitly via function arguments and references.
- **Modular Architecture**: Complete menu-driven CLI interface separating dynamic generation, algorithm execution, file handling, and benchmarking.

---

## Repository Structure

```text
.
├── src/
│   ├── main.c              # Main loop and interactive CLI menu
│   ├── array_ops.c         # Dynamic generation, search, sort, and merge logic
│   └── file_io.c           # File load and store implementations
├── include/
│   ├── array_ops.h         # Function declarations and definitions
│   └── file_io.h           # File I/O interfaces
├── Makefile                # Build automation script
└── README.md               # Project documentation
