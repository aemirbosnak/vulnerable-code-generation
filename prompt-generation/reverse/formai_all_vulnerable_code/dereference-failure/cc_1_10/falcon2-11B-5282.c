//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Define the Expense Tracker structure
typedef struct {
    char name[50];
    int amount;
    int id;
} ExpenseTracker;

// Function to add an expense
ExpenseTracker* addExpense(ExpenseTracker* tracker, char* name, int amount, int id) {
    ExpenseTracker* newTracker = (ExpenseTracker*) malloc(sizeof(ExpenseTracker));
    if (newTracker == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newTracker->name, name);
    newTracker->amount = amount;
    newTracker->id = id;
    tracker->amount++;
    return newTracker;
}

// Function to display all expenses
void displayExpenses(ExpenseTracker* tracker) {
    printf("Expense Tracker:\n");
    printf("Name: %s\n", tracker->name);
    printf("Amount: %d\n", tracker->amount);
    printf("ID: %d\n", tracker->id);
}

// Function to delete an expense
void deleteExpense(ExpenseTracker* tracker) {
    free(tracker);
    tracker = NULL;
}

int main() {
    // Create an instance of the Expense Tracker
    ExpenseTracker* tracker = (ExpenseTracker*) malloc(sizeof(ExpenseTracker));
    if (tracker == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    strcpy(tracker->name, "John Doe");
    tracker->amount = 0;
    tracker->id = 1;

    // Add expenses
    ExpenseTracker* expense1 = addExpense(tracker, "Expense 1", 100, 2);
    ExpenseTracker* expense2 = addExpense(tracker, "Expense 2", 200, 3);
    ExpenseTracker* expense3 = addExpense(tracker, "Expense 3", 300, 4);

    // Display all expenses
    displayExpenses(tracker);

    // Delete an expense
    deleteExpense(expense1);
    displayExpenses(tracker);

    return 0;
}