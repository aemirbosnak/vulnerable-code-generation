//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a futuristic expense tracker structure
typedef struct ExpenseTracker {
    char name[50];
    char category[50];
    double amount;
    struct ExpenseTracker* next;
} ExpenseTracker;

// Function to insert an expense into the expense tracker
void insertExpense(ExpenseTracker** head, char* name, char* category, double amount) {
    ExpenseTracker* newExpense = malloc(sizeof(ExpenseTracker));

    strcpy(newExpense->name, name);
    strcpy(newExpense->category, category);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (*head == NULL) {
        *head = newExpense;
    } else {
        (*head)->next = newExpense;
    }
}

// Function to print all expenses
void printExpenses(ExpenseTracker* head) {
    while (head) {
        printf("Name: %s, Category: %s, Amount: %.2lf\n", head->name, head->category, head->amount);
        head = head->next;
    }
}

int main() {
    // Create an expense tracker
    ExpenseTracker* head = NULL;

    // Insert some expenses
    insertExpense(&head, "Groceries", "Food", 50.0);
    insertExpense(&head, "Clothes", "Fashion", 25.0);
    insertExpense(&head, "Electronics", "Gadgets", 100.0);

    // Print all expenses
    printExpenses(head);

    return 0;
}