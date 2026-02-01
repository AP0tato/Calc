# Calc - C++ Calculator Engine

A C++ calculator library that can evaluate mathematical expressions and equations. This project includes functionality for parsing, tokenizing, and solving arithmetic expressions and equations.

## Features

- **Expression Evaluation**: Parse and evaluate mathematical expressions with proper operator precedence
- **Equation Solving**: Split and solve linear equations
- **String Formatting**: Automatic string formatting and validation
- **Robust Parsing**: Uses standard algorithms for expression parsing (tokenization, Shunting Yard algorithm)
- **File-based I/O**: Read expressions/equations from input files and write results to output files

## Project Structure

```tree
Calc/
├── src/
│   ├── main.cpp        # Main entry point
│   ├── calc.cpp        # Calculator implementation
│   └── alg.cpp         # Algebra utilities for equation solving
├── inc/
│   ├── calc.hpp        # Calculator class definition
│   └── alg.hpp         # Algebra class definition
├── build/              # Compiled output directory
├── Makefile            # Build configuration
├── in.txt              # Sample input file
├── out.txt             # Sample output file
└── README.md           # This file
```

## Building

### Requirements

- C++17 compatible compiler (GCC, Clang, etc.)
- GNU Make

### Compilation

```bash
make
```

This will:

1. Compile all source files in `src/`
2. Generate object files in `build/src/`
3. Create the executable `build/main`

### Clean

Remove all compiled files:

```bash
make clean
```

## Usage

The calculator reads expressions/equations from `in.txt` and writes results to `out.txt`.

### Running

```bash
./build/main
```

### Input File Format

Create an `in.txt` file with mathematical expressions or equations:

```txt
2 + 3 * 4
(10 - 5) / 2
x + 5 = 10
```

Results will be written to `out.txt`.

## Classes

### Calc

Evaluates mathematical expressions with operator precedence:

- `formatString()`: Prepares input string for parsing
- `evaluateString()`: Parses and evaluates expression
- `tokenizeString()`: Breaks expression into tokens
- `parseTokens()`: Converts infix to postfix notation (Shunting Yard)

### Alg

Handles equation solving and algebraic operations:

- `splitEquation()`: Separates left and right sides of equation
- Additional algebra utilities for solving equations

## Compilation Flags

```bash
-std=c++17          # C++17 standard
-g                  # Debug symbols
-O0                 # No optimization (debug build)
-Wall -Wextra       # All warnings enabled
-pedantic           # Pedantic warnings
-I inc              # Include directory
```

## License

MIT Licence

## Author

AP0tato
