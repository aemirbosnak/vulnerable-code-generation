//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <string.h>

// Define the Expense Tracker structure
typedef struct ExpenseTracker {
    char name[20];
    double amount;
    char category[20];
    struct ExpenseTracker* next;
} ExpenseTracker;

// Function to insert an expense into the tracker
void insertExpense(ExpenseTracker* head, char* name, double amount, char* category) {
    ExpenseTracker* newExpense = malloc(sizeof(ExpenseTracker));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    strcpy(newExpense->category, category);
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        head->next = newExpense;
    }
}

// Function to print the expenses
void printExpenses(ExpenseTracker* head) {
    ExpenseTracker* currentExpense = head;
    while (currentExpense) {
        printf("%s: %.2lf, Category: %s\n", currentExpense->name, currentExpense->amount, currentExpense->category);
        currentExpense = currentExpense->next;
    }
}

int main() {
    // Create an expense tracker
    ExpenseTracker* head = NULL;

    // Insert some expenses
    insertExpense(head, "Groceries", 50.0, "Food");
    insertExpense(head, "Dining out", 25.0, "Entertainment");
    insertExpense(head, "Clothes", 30.0, "Shopping");
    insertExpense(head, "Entertainment", 15.0, "Entertainment");

    // Print the expenses
    printExpenses(head);

    return 0;
}