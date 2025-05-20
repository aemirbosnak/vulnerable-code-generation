//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the expense structure
typedef struct expense {
    char *description;
    float amount;
    struct expense *next;
} expense_t;

// Create a new expense
expense_t *new_expense(char *description, float amount) {
    expense_t *expense = malloc(sizeof(expense_t));
    expense->description = strdup(description);
    expense->amount = amount;
    expense->next = NULL;
    return expense;
}

// Add an expense to the list
void add_expense(expense_t **head, expense_t *expense) {
    if (*head == NULL) {
        *head = expense;
    } else {
        expense->next = *head;
        *head = expense;
    }
}

// Print the list of expenses
void print_expenses(expense_t *head) {
    expense_t *current = head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// Free the list of expenses
void free_expenses(expense_t *head) {
    expense_t *current = head;
    while (current != NULL) {
        expense_t *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a new expense list
    expense_t *head = NULL;

    // Add some expenses to the list
    add_expense(&head, new_expense("Groceries", 100.00));
    add_expense(&head, new_expense("Gas", 50.00));
    add_expense(&head, new_expense("Rent", 1200.00));
    add_expense(&head, new_expense("Utilities", 200.00));

    // Print the list of expenses
    printf("Expenses:\n");
    print_expenses(head);

    // Free the list of expenses
    free_expenses(head);

    return 0;
}