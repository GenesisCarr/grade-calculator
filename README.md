# Grade Calculator

A C++ console application that tracks graded items such as homework, quizzes, and exams, calculates both points-based and weighted final grades, and saves grade data between sessions. The program is built using object-oriented programming concepts including inheritance, polymorphism, smart pointers, file handling, and a menu-driven interface.

---

## Author

Genesis Carreon - COSC 1437

---

## Description

The Grade Calculator System is a menu-driven C++ application designed to help students organize and calculate their academic grades. Users can add homework assignments, quizzes, and exams, customize grading weights and letter-grade cutoffs, calculate final grades, and save their information to a text file for future use.

The project demonstrates important programming concepts from COSC 1437 including vectors, classes, inheritance, polymorphism, smart pointers, file I/O, exception handling, input validation, and user interface improvements.

---

## Features

- Menu-driven interface
- Add homework, quiz, and exam items
- View all graded items in a formatted table
- Remove graded items
- Add and remove extra credit
- Customize grading weights and letter-grade cutoffs
- Calculate points-based final grade
- Calculate weighted final grade
- Save graded items to a text file
- Load graded items from a text file
- Delete saved grade data
- Input validation for invalid and negative number input
- Colored console output
- Clear-screen feature for cleaner user experience
- Crash prevention for invalid user input

---

## Files

| File | Purpose |
|---|---|
| main.cpp | Driver program with menu loop, calculations, file handling, and user input |
| GradedItem.h | Base class for all graded items |
| Homework.h | Derived class for homework items |
| Quiz.h | Derived class for quiz items |
| Exam.h | Derived class for exam items |
| USER_GUIDE.md | Instructions for using the application |
| README.md | Repository documentation |

---

## How to Build

Using g++ on macOS, Linux, WSL, or MinGW:

```bash
g++ -std=c++17 *.cpp -o GradeCalculator
```

---

## How to Run

For macOS or Linux:

```bash
./GradeCalculator
```

For Windows:

```bash
GradeCalculator.exe
```

---

## Requirements

- C++17 or newer compiler
- Terminal or command prompt
- GitHub account for repository submission

---

## Course Concepts Demonstrated

### Chapter 11
- `std::vector`
- Loop-driven menu
- Modular helper functions
- Control flow structures

### Chapter 13
- File I/O using `ifstream` and `ofstream`
- Saving and loading grade data from a text file

### Chapter 14
- User-defined classes
- Getter functions
- Object storage using vectors

### Chapter 15
- Constructors
- Encapsulation
- Calculated properties using `getPercentage()`

### Chapter 16
- Menu-driven interface
- `switch` statements
- `<iomanip>` formatting
- Helper functions

### Chapter 17
- Inheritance
- Polymorphism
- Base and derived classes
- Virtual functions

### Chapter 18
- Smart pointers using `std::unique_ptr`
- `std::make_unique`
- Struct usage with `GradingScheme`

### Sprint 19
- Input validation
- Exception handling
- Prevention of invalid and negative input

### Sprint 20
- Save and load functionality
- Delete saved file functionality

### Sprint 21
- ANSI color output
- Headers and separators
- Clear-screen feature

### Sprint 22
- Crash prevention
- Extra credit handling
- Final user interface polish

---

## Sample Build and Run

Example:

```bash
g++ -std=c++17 *.cpp -o GradeCalculator
./GradeCalculator
```

---

## Repository Link

This project is submitted through a public GitHub repository for COSC 1437 Final Project submission.