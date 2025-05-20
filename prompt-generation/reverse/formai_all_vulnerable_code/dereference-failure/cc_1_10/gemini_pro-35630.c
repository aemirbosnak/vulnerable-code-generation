//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct expense {
    char *description;
    double amount;
    char *category;
    struct expense *next;
} expense;

// Create a new expense
expense *create_expense(char *description, double amount, char *category) {
    expense *new_expense = malloc(sizeof(expense));
    new_expense->description = strdup(description);
    new_expense->amount = amount;
    new_expense->category = strdup(category);
    new_expense->next = NULL;
    return new_expense;
}

// Add an expense to the list of expenses
void add_expense(expense **head, expense *new_expense) {
    if (*head == NULL) {
        *head = new_expense;
    } else {
        expense *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_expense;
    }
}

// Print the list of expenses
void print_expenses(expense *head) {
    expense *current = head;
    while (current != NULL) {
        printf("%s: $%.2f (%s)\n", current->description, current->amount, current->category);
        current = current->next;
    }
}

// Free the list of expenses
void free_expenses(expense *head) {
    expense *current = head;
    while (current != NULL) {
        expense *next = current->next;
        free(current->description);
        free(current->category);
        free(current);
        current = next;
    }
}

// Get the total amount of expenses
double get_total_amount(expense *head) {
    double total = 0;
    expense *current = head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

// Get the total amount of expenses in a category
double get_total_amount_in_category(expense *head, char *category) {
    double total = 0;
    expense *current = head;
    while (current != NULL) {
        if (strcmp(current->category, category) == 0) {
            total += current->amount;
        }
        current = current->next;
    }
    return total;
}

// Main function
int main() {
    // Create a linked list of expenses
    expense *head = NULL;
    add_expense(&head, create_expense("Groceries", 100.00, "Food"));
    add_expense(&head, create_expense("Gas", 50.00, "Transportation"));
    add_expense(&head, create_expense("Rent", 1500.00, "Housing"));
    add_expense(&head, create_expense("Utilities", 200.00, "Utilities"));
    add_expense(&head, create_expense("Entertainment", 100.00, "Entertainment"));

    // Print the list of expenses
    printf("Expenses:\n");
    print_expenses(head);

    // Get the total amount of expenses
    double total_amount = get_total_amount(head);
    printf("Total amount: $%.2f\n", total_amount);

    // Get the total amount of expenses in a category
    double total_amount_in_food = get_total_amount_in_category(head, "Food");
    printf("Total amount in Food category: $%.2f\n", total_amount_in_food);

    // Free the list of expenses
    free_expenses(head);

    return 0;
}