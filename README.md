# **Custom Unique Pointer Implementation (`my_unique_ptr`)**  

**Educational C++ Project**  

---

## **Overview**  

This project implements a custom smart pointer class, `my_unique_ptr`, in C++. The class provides functionality similar to `std::unique_ptr`, offering memory management for dynamically allocated objects.  

The implementation supports both single objects and dynamic arrays, ensuring proper cleanup and preventing memory leaks.  

---

## **Features**  

- **Automatic Memory Management**  
  Ensures proper cleanup of dynamically allocated memory.  

- **Move Semantics**  
  Supports move constructors and move assignment to transfer ownership without duplicating resources.  

- **Array Specialization**  
  Handles dynamic arrays separately using `delete[]` to avoid undefined behavior.  

- **Operator Overloading**  
  - `operator->` for member access.  
  - `operator*` for dereferencing.  
  - `operator[]` for array indexing (for arrays only).  

- **Exception Safety**  
  Throws meaningful exceptions for invalid operations, such as accessing out-of-bound indices. 
