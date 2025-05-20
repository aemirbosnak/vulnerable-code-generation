//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store an expense
typedef struct Expense {
    char description[50];
    float amount;
    char category[20];
    struct Expense *next;
} Expense;

// Function to create a new expense
Expense *createExpense(char *description, float amount, char *category) {
    Expense *newExpense = (Expense *)malloc(sizeof(Expense));
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    strcpy(newExpense->category, category);
    newExpense->next = NULL;
    return newExpense;
}

// Function to add an expense to the list
void addExpense(Expense **head, Expense *newExpense) {
    if (*head == NULL) {
        *head = newExpense;
    } else {
        Expense *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newExpense;
    }
}

// Function to print the list of expenses
void printExpenses(Expense *head) {
    Expense *current = head;
    while (current != NULL) {
        printf("%s %.2f %s\n", current->description, current->amount, current->category);
        current = current->next;
    }
}

// Function to free the list of expenses
void freeExpenses(Expense *head) {
    Expense *current = head;
    while (current != NULL) {
        Expense *next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a new expense list
    Expense *head = NULL;

    // Add some expenses to the list
    addExpense(&head, createExpense("Groceries", 100.00, "Food"));
    addExpense(&head, createExpense("Gas", 50.00, "Transportation"));
    addExpense(&head, createExpense("Entertainment", 20.00, "Entertainment"));
    addExpense(&head, createExpense("Rent", 1200.00, "Housing"));

    // Print the list of expenses
    printf("Your expenses:\n");
    printExpenses(head);

    // Free the list of expenses
    freeExpenses(head);

    return 0;
}