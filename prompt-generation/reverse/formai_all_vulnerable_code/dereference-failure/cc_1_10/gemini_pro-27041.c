//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the expense structure
typedef struct expense {
    char description[50];
    float amount;
    struct expense *next;
} expense_t;

// Define the linked list of expenses
expense_t *head = NULL;

// Function to add an expense to the linked list
void add_expense(char *description, float amount) {
    expense_t *new_expense = malloc(sizeof(expense_t));
    strcpy(new_expense->description, description);
    new_expense->amount = amount;
    new_expense->next = head;
    head = new_expense;
}

// Function to print the linked list of expenses
void print_expenses() {
    expense_t *current = head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list of expenses
void free_expenses() {
    expense_t *current = head;
    while (current != NULL) {
        expense_t *next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Add some expenses to the linked list
    add_expense("Groceries", 50.00);
    add_expense("Gas", 20.00);
    add_expense("Entertainment", 30.00);
    add_expense("Other", 10.00);

    // Print the linked list of expenses
    print_expenses();

    // Free the memory allocated for the linked list of expenses
    free_expenses();

    return 0;
}