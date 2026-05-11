# User Guide: Grade Calculator (OOP Edition)

---

# Introduction

The Grade Calculator is a C++ console application designed to help users organize and calculate academic grades. Users can enter homework assignments, quizzes, and exams, then calculate their final grade using either a points-based method or a weighted grading method.

The application also supports extra credit, saving and loading data, deleting saved files, input validation, and user interface improvements for easier navigation.

---

# Getting Started

To build the program, use the following command in the terminal:

```bash
g++ -std=c++17 *.cpp -o GradeCalculator
```

To run the program:

For macOS or Linux:

```bash
./GradeCalculator
```

For Windows:

```bash
GradeCalculator.exe
```

After launching the program, the main menu will appear. Enter the number corresponding to the menu option you want to use.

---

# Menu Walkthrough

## 1. Set Grading Scheme

This option allows the user to customize grading category weights and letter-grade cutoffs.

The program asks for:

- Homework weight percentage
- Quiz weight percentage
- Exam weight percentage
- Minimum percentage for A
- Minimum percentage for B
- Minimum percentage for C
- Minimum percentage for D

### Requirements

- Weights must total exactly 100%
- All values must be numbers
- Percentages cannot be negative

### Example

```txt
Homework: 20
Quiz: 30
Exam: 50
```

---

## 2. Add Graded Item

This option allows the user to add a homework assignment, quiz, or exam.

The program asks for:

- Category selection
- Assignment name
- Points possible
- Points earned

### Requirements

- Points must be numeric
- Points cannot be negative

### Example

```txt
Category: Homework
Name: Chapter 15 Lab
Points possible: 100
Points earned: 92
```

---

## 3. Add Extra Credit

This option allows the user to add extra credit points.

The program asks for:

- Extra credit points

### Requirements

- Value must be numeric
- Value cannot be negative

### Example

```txt
Extra credit: 5
```

---

## 4. View All Items

This option displays all current graded items in a formatted table.

The table includes:

- Item number
- Assignment name
- Category
- Points earned
- Points possible
- Percentage earned

The program also displays the current extra credit total.

---

## 5. Remove Item

This option allows the user to remove either:

- A graded item
- Extra credit

The program displays all current items with a number beside each one. The user enters the number of the item they want to remove.

### Requirements

- Selection must exist in the list
- Extra credit removal amount cannot exceed current extra credit total

---

## 6. Calculate Grade (Points-Based)

This option calculates the overall grade using total earned points divided by total possible points.

### Formula

```txt
Percentage = (Total Earned / Total Possible) × 100
```

Extra credit is included in this calculation.

### Best Use

Use this option for classes where all assignments are based on total points.

---

## 7. Calculate Grade (Weighted)

This option calculates the final grade using category averages and grading weights.

### Formula

```txt
Final Grade =
(Homework Average × Homework Weight)
+ (Quiz Average × Quiz Weight)
+ (Exam Average × Exam Weight)
```

### Best Use

Use this option for classes where homework, quizzes, and exams are weighted differently.

---

## 8. Save Graded Items

This option saves all graded items into a text file named:

```txt
graded_items.txt
```

This allows users to reopen the program later and continue using their saved data.

---

## 9. Load Graded Items

This option loads previously saved graded items from:

```txt
graded_items.txt
```

If the file does not exist, the program displays an error message instead of crashing.

---

## 10. Delete Saved File

This option deletes the saved text file and clears all current graded items and extra credit.

The program asks for confirmation before deleting.

### Confirmation Example

```txt
Are you sure you want to delete saved data? (y/n):
```

---

## 0. Exit

This option exits the application.

Before closing, the program automatically saves graded items to the text file.

---

# Sample Session

```txt
==================================================
 GRADE CALCULATOR - MAIN MENU
==================================================
1. Set Grading Scheme
2. Add Graded Item
3. Add Extra Credit
4. View All Items
5. Remove Item
6. Calculate Grade (Points-Based)
7. Calculate Grade (Weighted)
8. Save Graded Items
9. Load Graded Items
10. Delete Saved File
0. Exit
--------------------------------------------------
Enter choice: 1

Enter weight for Homework (%): 20
Enter weight for Quizzes (%): 30
Enter weight for Exams (%): 50
Weights saved!

Enter minimum % for A: 90
Enter minimum % for B: 80
Enter minimum % for C: 70
Enter minimum % for D: 60
Cutoffs saved!

Enter choice: 2

Select category:
1. Homework
2. Quiz
3. Exam

Choice: 1

Name: Chapter 15 Lab

Points possible: 100

Points earned: 95

Item added!

Enter choice: 2

Select category:
1. Homework
2. Quiz
3. Exam

Choice: 2

Name: Quiz 1

Points possible: 50

Points earned: 45

Item added!

Enter choice: 4

#    Name                Category        Earned  Possible   Percent
--------------------------------------------------
1    Chapter 15 Lab      Homework          95.0     100.0     95.0%
2    Quiz 1              Quiz              45.0      50.0     90.0%

Extra Credit: 0.0

Enter choice: 6

Earned: 140.0 / 150.0
Extra Credit: 0.0
Total: 140.0 / 150.0
Overall: 93.3%
Letter Grade: A
```

---

# Sprint Features

## Sprint 19 — Input Validation

The program validates user input to prevent crashes from invalid or non-numeric values.

Examples:
- Rejecting letters when numbers are required
- Rejecting negative values
- Preventing invalid menu choices

---

## Sprint 20 — Save, Load, and Delete Features

The program allows users to:
- Save graded items
- Load saved graded items
- Delete saved files

This feature improves long-term usability.

---

## Sprint 21 — User Interface Improvements

The program includes:
- Colored menu output
- Headers and separators
- Formatted tables
- Clear-screen functionality

These features improve readability and user experience.

---

## Sprint 22 — Final Polish and Crash Prevention

The program safely handles:
- Empty item lists
- Missing save files
- Invalid menu selections
- Invalid numeric input

The application continues running instead of crashing.

---

# Understanding Your Results

## Points-Based Grade

The points-based calculation combines all earned points and divides them by all possible points.

This method is best for courses where every point contributes equally to the final grade.

---

## Weighted Grade

The weighted calculation first calculates averages for each category, then applies grading weights.

This method is best for courses where homework, quizzes, and exams are worth different percentages.

---

# Known Limitations

- Extra credit only affects the points-based calculation
- The grading scheme itself is not saved to the text file
- ANSI colors may not display correctly in every terminal
- Editing the save file manually may cause formatting errors during loading

---

# Troubleshooting

## Problem: Program says file cannot be opened

Cause:
- No saved file exists yet

Solution:
- Add items first
- Use the save option before attempting to load

---

## Problem: Weights do not total 100%

Cause:
- Homework, quiz, and exam percentages do not equal 100

Solution:
- Re-enter weights correctly

Example:

```txt
20 + 30 + 50 = 100
```

---

## Problem: Invalid input message appears

Cause:
- Letters or symbols were entered instead of numbers

Solution:
- Enter numeric values only when prompted

---

## Problem: Colors display incorrectly

Cause:
- Some terminals do not fully support ANSI color codes

Solution:
- The program will still function normally even if colors appear incorrectly