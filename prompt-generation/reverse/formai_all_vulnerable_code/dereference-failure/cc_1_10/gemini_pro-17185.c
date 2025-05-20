//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Introspection: A clever way of using preprocessor macros to print function names
#define HERE printf("Function: %s\n", __func__);

// Structure to represent an expense
typedef struct Expense {
    char *description;
    float amount;
    struct Expense *next;
} Expense;

// Function to create a new expense
Expense *create_expense(char *description, float amount) {
    HERE;
    Expense *new_expense = malloc(sizeof(Expense));
    new_expense->description = malloc(strlen(description) + 1);
    strcpy(new_expense->description, description);
    new_expense->amount = amount;
    new_expense->next = NULL;
    return new_expense;
}

// Function to add an expense to a list
void add_expense(Expense **head, Expense *new_expense) {
    HERE;
    if (*head == NULL) {
        *head = new_expense;
    } else {
        Expense *current_expense = *head;
        while (current_expense->next != NULL) {
            current_expense = current_expense->next;
        }
        current_expense->next = new_expense;
    }
}

// Function to print the list of expenses
void print_expenses(Expense *head) {
    HERE;
    Expense *current_expense = head;
    while (current_expense != NULL) {
        printf("Description: %s\n", current_expense->description);
        printf("Amount: %.2f\n", current_expense->amount);
        printf("\n");
        current_expense = current_expense->next;
    }
}

// Function to free the memory allocated for the list of expenses
void free_expenses(Expense *head) {
    HERE;
    Expense *current_expense = head;
    while (current_expense != NULL) {
        Expense *next_expense = current_expense->next;
        free(current_expense->description);
        free(current_expense);
        current_expense = next_expense;
    }
}

// Main function
int main() {
    HERE;
    // Create a linked list to store the expenses
    Expense *head = NULL;

    // Add some expenses to the list
    add_expense(&head, create_expense("Dinner", 20.00));
    add_expense(&head, create_expense("Gas", 15.00));
    add_expense(&head, create_expense("Entertainment", 30.00));

    // Print the list of expenses
    print_expenses(head);

    // Free the memory allocated for the list of expenses
    free_expenses(head);

    return 0;
}