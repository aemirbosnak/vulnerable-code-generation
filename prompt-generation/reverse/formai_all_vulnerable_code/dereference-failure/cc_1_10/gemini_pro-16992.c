//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Expense structure
struct Expense {
    char *description;
    float amount;
    struct Expense *next;
};

// Function to create a new expense
struct Expense *createExpense(char *description, float amount) {
    struct Expense *newExpense = (struct Expense *)malloc(sizeof(struct Expense));
    newExpense->description = description;
    newExpense->amount = amount;
    newExpense->next = NULL;
    return newExpense;
}

// Function to add an expense to the list
void addExpense(struct Expense **head, struct Expense *newExpense) {
    if (*head == NULL) {
        *head = newExpense;
    } else {
        struct Expense *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newExpense;
    }
}

// Function to print the list of expenses
void printExpenses(struct Expense *head) {
    struct Expense *current = head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// Function to free the memory allocated to the list of expenses
void freeExpenses(struct Expense *head) {
    struct Expense *current = head;
    while (current != NULL) {
        struct Expense *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a new expense list
    struct Expense *head = NULL;

    // Add some expenses to the list
    addExpense(&head, createExpense("Groceries", 100.00));
    addExpense(&head, createExpense("Rent", 1200.00));
    addExpense(&head, createExpense("Utilities", 150.00));
    addExpense(&head, createExpense("Transportation", 200.00));
    addExpense(&head, createExpense("Entertainment", 100.00));

    // Print the list of expenses
    printf("Expenses:\n");
    printExpenses(head);

    // Free the memory allocated to the list of expenses
    freeExpenses(head);

    return 0;
}