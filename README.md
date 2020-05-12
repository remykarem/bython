# Bython

A basic and simple Python-like interpreter written in C.

### Workflow

1. Memory management (`memory.h`)
    - [ ] Arena
    - [ ] Reference count
    - [ ] Garbage collection
2. Parsing (`tok.h`)
3. AST (`ast.h`)
4. Bytecode (`compile.h`)
5. Execution (`execution.h`)
    - [ ] Simple execution
    - [ ] Stack-based virtual machine

### What can the program do?

- Create Bython objects (`objects.h`)
    -  [ ] int
    -  [ ] list
- Perform operations (`objects.h`)
    - [ ] Assignment
    - [ ] Arithmetic
- Functions
    - [ ] Define
    - [ ] Call

## References

* Your Guide to the CPython Source Code ([realpython.com](https://realpython.com/cpython-source-code-guide/))
* A Python Interpreter Written in Python ([aosabook.org](http://www.aosabook.org/en/500L/a-python-interpreter-written-in-python.html#fnref2))