#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <cstdio>
#include "GradedItem.h"
#include "Homework.h"
#include "Quiz.h"
#include "Exam.h"
#include <map>
#include <stdexcept>

/*
 * Grade Calculator (OOP Edition) — Final Project
 * Author: Genesis Carreon
 * Course: COSC 1437
 *
 * Concepts Demonstrated (Chapters 11-18 + Sprints 19-22)
 * ------------------------------------------------------
 * Ch 11 - Foundation from COSC 1436: std::vector, control flow, modular code
 * Ch 13 - File I/O: saveItems() and loadItems() use ofstream and ifstream
 * Ch 14 - User-defined class: GradedItem base class with private data and     getters
 * Ch 15 - Object refinement: constructors, encapsulation, and getPercentage()
 * Ch 16 - Menu-driven UI: switch statement, helper functions, and formatted table output
 * Ch 17 - Inheritance and polymorphism: Homework, Quiz, and Exam derive from GradedItem
 * Ch 18 - Smart pointers: std::vector<std::unique_ptr<GradedItem>> and GradingScheme struct
 *
 * Sprint 19 - Input validation prevents invalid and negative number input
 * Sprint 20 - Save, load, and delete file features using a text file
 * Sprint 21 - User interface polish with colors, headers, separators, and clear screen
 * Sprint 22 - Final polish with extra credit handling and crash prevention
 */

using namespace std;

void setColor(const string& color) {
    if (color == "red") cout << "\033[31m";
    else if (color == "green") cout << "\033[32m";
    else if (color == "yellow") cout << "\033[33m";
    else if (color == "blue") cout << "\033[34m";
    else if (color == "pink") cout << "\033[38;2;255;105;180m";
    else if (color == "cyan") cout << "\033[36m";
    else if (color == "reset") cout << "\033[0m";
}

struct GradingScheme {
    float homeworkWeight = 0.20f;
    float quizWeight = 0.30f;
    float examWeight = 0.50f;
    float cutoffA = 90.0f;
    float cutoffB = 80.0f;
    float cutoffC = 70.0f;
    float cutoffD = 60.0f;
};

// Save graded items to a file
void saveItems(const vector<unique_ptr<GradedItem>>& items, const string& filename) {
    ofstream file(filename);
    if (!file) {
        setColor("red");
        cout << "Error opening file for writing.\n";
        setColor("reset");
        return;
    }

    for (const auto& item : items) {
        file << item->getCategory() << ","
             << item->getName() << ","
             << item->getPointsEarned() << ","
             << item->getPointsPossible() << "\n";
    }

    file.close();
    setColor("green");
    cout << "Items saved successfully!\n";
    setColor("reset");
}

// Load graded items from a file
void loadItems(vector<unique_ptr<GradedItem>>& items, const string& filename) {
    items.clear();

    ifstream file(filename);
    if (!file) {
        setColor("red");
        cerr << "Error: Could not open file " << filename << " for reading.\n";
        setColor("reset");
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string category, name, earnedStr, possibleStr;
        float earned, possible;

        if (!getline(ss, category, ',') ||
            !getline(ss, name, ',') ||
            !getline(ss, earnedStr, ',') ||
            !getline(ss, possibleStr, ',')) {
            setColor("red");
            cerr << "Error: Malformed line: " << line << "\n";
            setColor("reset");
            continue;
        }

        earned = stof(earnedStr);
        possible = stof(possibleStr);

        if (category == "Homework") {
            items.push_back(make_unique<Homework>(name, earned, possible));
        } else if (category == "Quiz") {
            items.push_back(make_unique<Quiz>(name, earned, possible));
        } else if (category == "Exam") {
            items.push_back(make_unique<Exam>(name, earned, possible));
        } else {
            setColor("red");
            cerr << "Error: Unknown category " << category << " in line: " << line << "\n";
            setColor("reset");
        }
    }

    file.close();
    setColor("green");
    cout << "Items loaded successfully!\n";
    setColor("reset");
}

void deleteSavedFile(const string& filename,
                     vector<unique_ptr<GradedItem>>& items,
                     float& bonusPoints) {
    char confirm;
    cout << "Are you sure you want to delete saved data? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        if (remove(filename.c_str()) == 0) {
            setColor("green");
            cout << "Saved file deleted successfully.\n";
            setColor("reset");
        } else {
            setColor("red");
            cout << "No saved file found to delete.\n";
            setColor("reset");
        }

        items.clear();
        bonusPoints = 0.0f;
        cout << "Current graded items and extra credit cleared.\n";
    } else {
        cout << "Deletion cancelled.\n";
    }
}

float getValidNumber() {
    float value;

    while (true) {
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor("red");
            cout << "Invalid input. Please enter a number: ";
            setColor("reset");
        } else {
            return value;
        }
    }
}

float getNonNegativeNumber() {
    float value;

    while (true) {
        try {
            cin >> value;

            if (cin.fail()) {
                throw invalid_argument("Not a number");
            }

            if (value < 0) {
                throw invalid_argument("Negative number");
            }

            cin.ignore(1000, '\n');
            return value;
        }
        catch (const invalid_argument& e) {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor("red");

            if (string(e.what()) == "Not a number") {
                cout << "Invalid input. Please enter a number: ";
            } else {
                cout << "Number cannot be negative. Try again: ";
            }

            setColor("reset");
        }
    }
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(1000, '\n');
    cin.get();
}

void displayHeader(const string& title) {
    cout << "\n";
    setColor("cyan");
    cout << string(50, '=') << '\n';
    cout << " " << title << '\n';
    cout << string(50, '=') << '\n';
    setColor("reset");
}

void displaySeparator() {
    cout << string(50, '-') << '\n';
}

void displayMenu() {
    displayHeader("GRADE CALCULATOR - MAIN MENU");
    setColor("pink");
    cout << "1. Set Grading Scheme\n";
    cout << "2. Add Graded Item\n";
    cout << "3. Add Extra Credit\n";
    cout << "4. View All Items\n";
    cout << "5. Remove Item\n";
    cout << "6. Calculate Grade (Points-Based)\n";
    cout << "7. Calculate Grade (Weighted)\n";
    cout << "8. Save Graded Items\n";
    cout << "9. Load Graded Items\n";
    cout << "10. Delete Saved File\n";
    cout << "0. Exit\n";
    setColor("reset");
    displaySeparator();
}

char getLetterGrade(float percentage, const GradingScheme& scheme) {
    if (percentage >= scheme.cutoffA) return 'A';
    if (percentage >= scheme.cutoffB) return 'B';
    if (percentage >= scheme.cutoffC) return 'C';
    if (percentage >= scheme.cutoffD) return 'D';
    return 'F';
}

void setGradingScheme(GradingScheme& scheme) {
    displayHeader("SET GRADING SCHEME");

    cout << "-- Category Weights --\n";
    float hw, qz, ex;
    cout << "Enter weight for Homework (%): ";
    cin >> hw;
    cout << "Enter weight for Quizzes (%): ";
    cin >> qz;
    cout << "Enter weight for Exams (%): ";
    cin >> ex;

    float total = hw + qz + ex;
    if (total != 100.0f) {
        setColor("red");
        cout << "Weights must sum to 100%. Got " << total << "%. Try again.\n";
        setColor("reset");
        return;
    }

    scheme.homeworkWeight = hw / 100.0f;
    scheme.quizWeight = qz / 100.0f;
    scheme.examWeight = ex / 100.0f;
    setColor("green");
    cout << "Weights saved!\n";
    setColor("reset");

    cout << "\n-- Letter Grade Cutoffs --\n";
    cout << "Enter minimum % for A: ";
    cin >> scheme.cutoffA;
    cout << "Enter minimum % for B: ";
    cin >> scheme.cutoffB;
    cout << "Enter minimum % for C: ";
    cin >> scheme.cutoffC;
    cout << "Enter minimum % for D: ";
    cin >> scheme.cutoffD;
    setColor("green");
    cout << "Cutoffs saved!\n";
    setColor("reset");
}

void addGradedItem(vector<unique_ptr<GradedItem>>& items) {
    displayHeader("ADD GRADED ITEM");

    cout << "Select category:\n";
    cout << "1. Homework\n";
    cout << "2. Quiz\n";
    cout << "3. Exam\n";
    cout << "Choice: ";

    int category;
    cin >> category;
    cin.ignore();

    cout << "Name: ";
    string name;
    getline(cin, name);

    cout << "Points possible: ";
    float possible = getNonNegativeNumber();

    cout << "Points earned: ";
    float earned = getNonNegativeNumber();

    switch (category) {
        case 1:
            items.push_back(make_unique<Homework>(name, earned, possible));
            break;
        case 2:
            items.push_back(make_unique<Quiz>(name, earned, possible));
            break;
        case 3:
            items.push_back(make_unique<Exam>(name, earned, possible));
            break;
        default:
            setColor("red");
            cout << "Invalid category.\n";
            setColor("reset");
            return;
    }

    setColor("green");
    cout << "Item added!\n";
    setColor("reset");
}

void viewItems(const vector<unique_ptr<GradedItem>>& items, float bonusPoints) {
    displayHeader("ALL GRADED ITEMS");

    if (items.empty()) {
        cout << "No items entered yet.\n";
        return;
    }

    cout << left << setw(5) << "#"
         << setw(20) << "Name"
         << setw(12) << "Category"
         << right << setw(10) << "Earned"
         << setw(10) << "Possible"
         << setw(10) << "Percent" << '\n';

    displaySeparator();
    cout << fixed << setprecision(1);

    for (size_t i = 0; i < items.size(); ++i) {
        cout << left << setw(5) << (i + 1)
             << setw(20) << items[i]->getName()
             << setw(12) << items[i]->getCategory()
             << right << setw(10) << items[i]->getPointsEarned()
             << setw(10) << items[i]->getPointsPossible()
             << setw(9) << items[i]->getPercentage() << "%\n";
    }

    cout << "\n----------------------------------------\n";
    cout << "Extra Credit: " << fixed << setprecision(1) << bonusPoints << '\n';
}

void removeItem(vector<unique_ptr<GradedItem>>& items, float& bonusPoints) {
    displayHeader("REMOVE ITEM");

    if (items.empty() && bonusPoints <= 0) {
        setColor("red");
        cout << "No items or extra credit to remove.\n";
        setColor("reset");
        return;
    }

    for (size_t i = 0; i < items.size(); ++i) {
        cout << (i + 1) << ". " << items[i]->getCategory()
             << " - " << items[i]->getName() << '\n';
    }

    cout << (items.size() + 1) << ". Remove Extra Credit\n";

    cout << "Enter item number to remove (0 to cancel): ";
    int index;
    cin >> index;

    if (index == items.size() + 1) {
        if (bonusPoints <= 0) {
            setColor("red");
            cout << "No extra credit to remove.\n";
            setColor("reset");
            return;
        }

        float points;
        cout << "Current extra credit: " << bonusPoints << '\n';
        cout << "Enter amount to remove: ";
        points = getNonNegativeNumber();

        if (points < 0) {
            setColor("red");
            cout << "Invalid amount.\n";
            setColor("reset");
            return;
        }

        if (points > bonusPoints) {
            setColor("red");
            cout << "You only have " << bonusPoints << " extra credit.\n";
            setColor("reset");
            return;
        }

        bonusPoints -= points;
        setColor("green");
        cout << "Extra credit removed.\n";
        setColor("reset");
        return;
    }

    if (index == 0) {
        cout << "Cancelled.\n";
        return;
    }

    if (index < 1 || index > static_cast<int>(items.size())) {
        setColor("red");
        cout << "Invalid selection.\n";
        setColor("reset");
        return;
    }

    cout << "Removed: " << items[index - 1]->getName() << '\n';
    items.erase(items.begin() + (index - 1));
}

void addExtraCredit(float& bonusPoints) {
    displayHeader("EXTRA CREDIT");

    float points;
    cout << "Enter extra credit points to add: ";
    points = getNonNegativeNumber();

    if (points < 0) {
        setColor("red");
        cout << "Extra credit cannot be negative.\n";
        setColor("reset");
        return;
    }

    bonusPoints += points;
    cout << fixed << setprecision(1);
    setColor("green");
    cout << "Extra credit added!\n";
    cout << "Current extra credit total: " << bonusPoints << '\n';
    setColor("reset");
}

void calculatePointsBased(const vector<unique_ptr<GradedItem>>& items,
                          const GradingScheme& scheme,
                          float bonusPoints) {
    displayHeader("POINTS-BASED GRADE");

    if (items.empty()) {
        setColor("red");
        cout << "No items to calculate.\n";
        setColor("reset");
        return;
    }

    float totalEarned = 0, totalPossible = 0;

    for (const auto& item : items) {
        totalEarned += item->getPointsEarned();
        totalPossible += item->getPointsPossible();
    }

    float originalEarned = totalEarned;
    totalEarned += bonusPoints;

    float percentage = (totalPossible > 0)
        ? (totalEarned / totalPossible) * 100
        : 0;

    cout << fixed << setprecision(1);
    cout << "Earned: " << originalEarned << " / " << totalPossible << '\n';
    cout << "Extra Credit: " << bonusPoints << '\n';
    cout << "Total: " << totalEarned << " / " << totalPossible << '\n';
    cout << "Overall: " << percentage << "%\n";
    cout << "Letter Grade: " << getLetterGrade(percentage, scheme) << '\n';
}

void calculateWeighted(const vector<unique_ptr<GradedItem>>& items,
                       const GradingScheme& scheme) {
    displayHeader("WEIGHTED GRADE CALCULATION");

    if (items.empty()) {
        setColor("red");
        cout << "No items to calculate.\n";
        setColor("reset");
        return;
    }

    map<string, float> totals;
    map<string, int> counts;

    for (const auto& item : items) {
        string category = item->getCategory();
        totals[category] += item->getPercentage();
        counts[category]++;
    }

    float hwAvg = counts["Homework"] > 0 ?
        totals["Homework"] / counts["Homework"] : 0;

    float quizAvg = counts["Quiz"] > 0 ?
        totals["Quiz"] / counts["Quiz"] : 0;

    float examAvg = counts["Exam"] > 0 ?
        totals["Exam"] / counts["Exam"] : 0;

    float finalGrade =
        (hwAvg * scheme.homeworkWeight) +
        (quizAvg * scheme.quizWeight) +
        (examAvg * scheme.examWeight);

    cout << fixed << setprecision(1);

    cout << "Homework Average: " << hwAvg << "%\n";
    cout << "Quiz Average: " << quizAvg << "%\n";
    cout << "Exam Average: " << examAvg << "%\n";

    cout << "\nFinal Weighted Grade: " << finalGrade << "%\n";
    cout << "Letter Grade: "
         << getLetterGrade(finalGrade, scheme) << '\n';
}

int main() {
    GradingScheme scheme;
    vector<unique_ptr<GradedItem>> items;
    float bonusPoints = 0.0f;

    int choice = 0;
    const string filename = "graded_items.txt";

    do {
        clearScreen();
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                setGradingScheme(scheme);
                pauseScreen();
                break;
            case 2:
                addGradedItem(items);
                pauseScreen();
                break;
            case 3:
                addExtraCredit(bonusPoints);
                pauseScreen();
                break;
            case 4:
                viewItems(items, bonusPoints);
                pauseScreen();
                break;
            case 5:
                removeItem(items, bonusPoints);
                pauseScreen();
                break;
            case 6:
                calculatePointsBased(items, scheme, bonusPoints);
                pauseScreen();
                break;
            case 7:
                calculateWeighted(items, scheme);
                pauseScreen();
                break;
            case 8:
                saveItems(items, filename);
                pauseScreen();
                break;
            case 9:
                loadItems(items, filename);
                pauseScreen();
                break;
            case 10:
                deleteSavedFile(filename, items, bonusPoints);
                pauseScreen();
                break;
            case 0:
                saveItems(items, filename);
                displayHeader("GOODBYE");
                setColor("green");
                cout << "Thank you for using Grade Calculator!\n";
                setColor("reset");
                break;
            default:
                setColor("red");
                cout << "Invalid choice. Please try again.\n";
                setColor("reset");
                pauseScreen();
        }

    } while (choice != 0);

    return 0;
}
