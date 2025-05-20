//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an expense
typedef struct Expense {
    char* description;
    float amount;
    struct Expense *next;
} Expense;

// Function to create a new expense
Expense* createExpense(char* description, float amount) {
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    newExpense->description = description;
    newExpense->amount = amount;
    newExpense->next = NULL;
    return newExpense;
}

// Function to add an expense to the front of the list
Expense* addExpense(Expense* head, Expense* newExpense) {
    newExpense->next = head;
    return newExpense;
}

// Function to print the expenses in the list
void printExpenses(Expense* head) {
    Expense* currentExpense = head;
    while (currentExpense != NULL) {
        printf("%s: $%.2f\n", currentExpense->description, currentExpense->amount);
        currentExpense = currentExpense->next;
    }
}

// Function to free the memory allocated for the expenses
void freeExpenses(Expense* head) {
    Expense* currentExpense = head;
    while (currentExpense != NULL) {
        Expense* nextExpense = currentExpense->next;
        free(currentExpense->description);
        free(currentExpense);
        currentExpense = nextExpense;
    }
}

int main() {
    // Create a new expense list
    Expense* head = NULL;

    // Add some expenses to the list
    head = addExpense(head, createExpense("Groceries", 100.00));
    head = addExpense(head, createExpense("Gas", 50.00));
    head = addExpense(head, createExpense("Entertainment", 20.00));

    // Print the expenses
    printf("Your expenses:\n");
    printExpenses(head);

    // Free the memory allocated for the expenses
    freeExpenses(head);

    return 0;
}