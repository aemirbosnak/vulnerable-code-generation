//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
struct Expense {
    char description[50];
    double amount;
    char category[50];
    char account[50];
    char date[50];
};

// Define the structure of the expense tracker
struct ExpenseTracker {
    int numExpenses;
    struct Expense expenses[MAX_EXPENSES];
};

// Create a new expense tracker
struct ExpenseTracker* createExpenseTracker() {
    struct ExpenseTracker* tracker = malloc(sizeof(struct ExpenseTracker));
    tracker->numExpenses = 0;
    return tracker;
}

// Add an expense to the expense tracker
void addExpense(struct ExpenseTracker* tracker, char* description, double amount, char* category, char* account, char* date) {
    if (tracker->numExpenses < MAX_EXPENSES) {
        strcpy(tracker->expenses[tracker->numExpenses].description, description);
        tracker->expenses[tracker->numExpenses].amount = amount;
        strcpy(tracker->expenses[tracker->numExpenses].category, category);
        strcpy(tracker->expenses[tracker->numExpenses].account, account);
        strcpy(tracker->expenses[tracker->numExpenses].date, date);
        tracker->numExpenses++;
    } else {
        printf("Error: The expense tracker is full.\n");
    }
}

// Print the expenses in the expense tracker
void printExpenses(struct ExpenseTracker* tracker) {
    for (int i = 0; i < tracker->numExpenses; i++) {
        printf("%s\t%.2f\t%s\t%s\t%s\n", tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].category, tracker->expenses[i].account, tracker->expenses[i].date);
    }
}

// Destroy the expense tracker
void destroyExpenseTracker(struct ExpenseTracker* tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create a new expense tracker
    struct ExpenseTracker* tracker = createExpenseTracker();

    // Add some expenses to the expense tracker
    addExpense(tracker, "Groceries", 100.00, "Food", "Checking", "2023-03-08");
    addExpense(tracker, "Gas", 50.00, "Transportation", "Credit Card", "2023-03-10");
    addExpense(tracker, "Rent", 1200.00, "Housing", "Checking", "2023-03-15");

    // Print the expenses in the expense tracker
    printExpenses(tracker);

    // Destroy the expense tracker
    destroyExpenseTracker(tracker);

    return 0;
}