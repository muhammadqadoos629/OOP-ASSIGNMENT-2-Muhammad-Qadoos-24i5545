#  CS2012 – Introduction to Object-Oriented Programming  
## Assignment #2 – Fall 2025  

This repository contains my solutions for **OOP Assignment #2**, focusing on recursion, linked lists, queues, and stacks implemented in **C++**.  
Each program fulfills the given requirements using clear, efficient, and well-structured code written at a student-developer level.

---

##  Question 1 – Recursion

### (a) ChangeLocation  
**Function:** `void ChangeLocation(char* Array, int b1, int b2);`  
A recursive function that swaps characters between two given indices within a character array.  
**Example:**  
Input → `{C, O, M, P, U, T, E, R}`, `b1 = 3`, `b2 = 7`  
Output → `{C, O, E, P, U, T, M, R}`

### (b) PrintPattern  
**Function:** `void PrintPattern(int &n);`  
Recursively prints a numeric pattern based on the input value `n`, demonstrating nested recursion and parameter handling.

---

##  Question 2 – Singly Linked List (NASA Feature System)

Implements a **singly linked list** to manage remotely-sensed geospatial data.  
Each node stores a unique `FeatureID` and a pointer to a polymorphic `Feature` object.  

### Implemented Classes:
- **Feature (Base Class)** – contains `Name` and a pure virtual function `analyze()`.  
- **LandFeature / WaterFeature (Derived Classes)** – override `analyze()` to provide specific feature analysis.  
- **SinglyLinkedList** – supports insertion, deletion, traversal, and reversal of the list.

Demonstrates **inheritance**, **polymorphism**, and **dynamic memory management**.

---

##  Question 3 – Doubly Linked List (Library System)

A **doubly linked list** representing a simple library management system.  
Each node contains:
- `BookID`
- `Title`
- `Author`

### Core Functionalities:
- Add a book at the **beginning**, **end**, or a **specific position**.  
- Delete a book by its **BookID**.  
- Display the list **forward** (using `head`) and **backward** (using `tail`).  

Efficient traversal is achieved using both head and tail pointers.

---

##  Question 4 – Queue (Movie Ticket Booking System)

A **queue data structure** simulating a movie theater’s ticket booking process.  
Each customer record includes:
- `CustomerID`
- `CustomerName`
- `TicketsRequested`

### Implemented Operations:
- `enqueue()` → Adds a new customer to the back of the queue.  
- `dequeue()` → Removes the first customer (FIFO order).  
- `display()` → Displays the current queue.  

Implements dynamic memory handling with proper construction and destruction.

---

##  Question 5 – Stack and Algorithm Analysis

### Implemented Stacks:
1. **Array-Based Stack** – uses a dynamic array to store elements.  
2. **Linked List-Based Stack** – uses linked nodes for flexible size management.  

Both stacks are utilized to create **iterative solutions** for the recursive problems in Question 1.

### Algorithm Analysis Summary:
| Operation | Array-Based Stack | Linked List-Based Stack |
|------------|------------------|--------------------------|
| Push / Pop | O(1) (amortized for resizing) | O(1) |
| Memory Use | Contiguous, cache-efficient | Dynamic, pointer overhead |
| Flexibility | Fixed/Resizable Capacity | Fully Dynamic |

**Conclusion:**  
Both implementations achieve O(1) time complexity for basic operations. The array-based stack is generally faster due to better cache locality, while the linked list stack offers greater flexibility in size and memory usage.

---

##  Key Programming Concepts Demonstrated
- Recursion and iteration  
- Dynamic memory allocation  
- Inheritance and polymorphism  
- Singly and doubly linked lists  
- Stack and queue data structures  
- Time complexity and algorithmic analysis  

---

## ⚙️ How to Run
1. Clone the repository:  
   ```bash
   git clone https://github.com/<your-username>/OOP_Assignment2.git
