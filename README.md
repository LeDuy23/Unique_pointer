Custom Unique Pointer Implementation (my_unique_ptr)

This project implements a custom smart pointer my_unique_ptr in C++ to provide functionality similar to std::unique_ptr. It supports both single objects and dynamic arrays with proper memory management and move semantics.

Features

Automatic Memory Management: Ensures proper cleanup of dynamically allocated memory.
Move Semantics: Supports move constructors and move assignment, preventing resource duplication.
Array Specialization: Handles dynamic arrays separately using delete[].
Operator Overloading:
operator-> for member access.
operator* for dereferencing.
operator[] for array indexing (for arrays only).
Exception Safety: Throws meaningful exceptions for invalid operations.
 
