# Data Structures: Sudoku Solver & File Parser

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-lightgrey.svg)]()

A robust C program designed to parse, validate, and solve Sudoku puzzles loaded dynamically from external text files. Built as part of the **Data Structures** curriculum at the **University of West Attica (UNIWA)**.

---

## Overview

This application accepts a formatted text file representing a $9 \times 9$ Sudoku grid, allocates dynamic 2D array memory, validates the input according to standard Sudoku rules, and computes the solution using a recursive backtracking algorithm.

### Key Features
- **Dynamic Memory Management**: Allocates and frees $9 \times 9$ 2D matrices dynamically using standard C memory routines.
- **CLI Parameter Parsing**: Reads puzzle input paths directly via command-line arguments (`argc`, `argv`).
- **Strict File Format Validation**:
  - Verifies exact layout ($9 \times 9$ character grid with newlines).
  - Validates character set constraints (accepting digits `'0'`–`'9'`, where `'0'` indicates empty cells).
- **Detailed Error Reporting**: Identifies structural file issues or specific rule violations (e.g., reporting exact row/column/sub-grid duplicate conflicts).
- **Backtracking Solver Algorithm**: Solves valid board states efficiently and renders the final solution via terminal/TUI output (optional `ncurses` support).

---

## Technical Constraints & Principles

- **Dynamic Allocation Only**: No static arrays are used for grid storage.
- **Localized Messages**: All UI and validation warning messages are generated in Greek.
- **Clean Documentation**: Function-level header blocks detailing algorithm behaviors and state transformations.

---

## Repository Structure

```text
.
├── src/
│   ├── main.c              # Command line argument parser and main entry point
│   ├── sudoku_io.c         # File loading, character parsing, and validation logic
│   └── sudoku_solver.c     # Grid validity checking and recursive solver algorithms
├── include/
│   ├── sudoku_io.h         # File handling and validation declarations
│   └── sudoku_solver.h     # Core puzzle solver interfaces
├── samples/
│   ├── valid_board.txt     # Sample valid 9x9 Sudoku grid file
│   └── invalid_board.txt   # Sample board file for testing error reporting
├── Makefile                # Compilation script
└── README.md               # Project documentation
