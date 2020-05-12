# Bython

A basic and simple Python-like interpreter written in C.

### Workflow

1. Memory management (`memory.h`)
    - [x] `ByArena`
    - [ ] Reference count
    - [ ] Garbage collection
2. Parsing (`tok.h`)
3. AST (`ast.h`)
    - [x] `ByAST_Node`
4. Bytecode (`compile.h`)
    - [x] `ByCodeObject`
5. Execution (`execution.h`)
    - [ ] Simple execution
    - [ ] Stack-based virtual machine


- Create Bython objects (`objects.h`)
    -  [x] `ByObject_Int`
    -  [ ] `ByObject_List`
- Perform operations (`objects.h`)
    - [ ] Assignment
    - [ ] Arithmetic
- Functions
    - [ ] Define
    - [ ] Call

### What can the program do?

- [ ] Assignment
- [ ] Arithmetic
- [ ] Arithmetic with assignment
- [ ] Defining function
- [ ] Calling a function

## References

* Your Guide to the CPython Source Code ([realpython.com](https://realpython.com/cpython-source-code-guide/))
* A Python Interpreter Written in Python ([aosabook.org](http://www.aosabook.org/en/500L/a-python-interpreter-written-in-python.html#fnref2))

