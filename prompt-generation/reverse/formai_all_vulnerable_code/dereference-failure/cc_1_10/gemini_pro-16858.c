//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store expense information
typedef struct Expense {
    char description[50];   // Description of the expense
    float amount;          // Amount of the expense
    struct Expense *next;   // Pointer to the next expense in the list
} Expense;

// Function to create a new expense
Expense *createExpense(char *description, float amount) {
    Expense *newExpense = malloc(sizeof(Expense));
    if (newExpense == NULL) {
        perror("Error allocating memory for new expense");
        exit(1);
    }
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->next = NULL;
    return newExpense;
}

// Function to add an expense to the expense list
void addExpense(Expense **head, Expense *newExpense) {
    if (*head == NULL) {
        *head = newExpense;
    } else {
        Expense *currentExpense = *head;
        while (currentExpense->next != NULL) {
            currentExpense = currentExpense->next;
        }
        currentExpense->next = newExpense;
    }
}

// Function to print the expense list
void printExpenses(Expense *head) {
    Expense *currentExpense = head;
    while (currentExpense != NULL) {
        printf("%s: %.2f\n", currentExpense->description, currentExpense->amount);
        currentExpense = currentExpense->next;
    }
}

// Function to free the memory allocated for the expense list
void freeExpenses(Expense *head) {
    Expense *currentExpense = head;
    while (currentExpense != NULL) {
        Expense *nextExpense = currentExpense->next;
        free(currentExpense);
        currentExpense = nextExpense;
    }
}

// Main function
int main() {
    // Create a new expense list
    Expense *head = NULL;

    // Add some expenses to the list
    addExpense(&head, createExpense("Rent", 1000.00));
    addExpense(&head, createExpense("Groceries", 200.00));
    addExpense(&head, createExpense("Utilities", 150.00));
    addExpense(&head, createExpense("Entertainment", 100.00));

    // Print the expense list
    printExpenses(head);

    // Free the memory allocated for the expense list
    freeExpenses(head);

    return 0;
}