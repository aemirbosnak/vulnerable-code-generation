//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to store each expense
typedef struct expense {
    char *description;
    float amount;
    struct expense *next;
} expense_t;

// Define the struct to store the list of expenses
typedef struct expense_list {
    struct expense *head;
    struct expense *tail;
} expense_list_t;

// Create a new expense
expense_t *create_expense(char *description, float amount) {
    expense_t *expense = malloc(sizeof(expense_t));
    expense->description = strdup(description);
    expense->amount = amount;
    expense->next = NULL;
    return expense;
}

// Add an expense to the list
void add_expense(expense_list_t *list, expense_t *expense) {
    if (list->head == NULL) {
        list->head = expense;
        list->tail = expense;
    } else {
        list->tail->next = expense;
        list->tail = expense;
    }
}

// Print the list of expenses
void print_expenses(expense_list_t *list) {
    expense_t *current = list->head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// Free the memory allocated for the list of expenses
void free_expenses(expense_list_t *list) {
    expense_t *current = list->head;
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
    expense_list_t *list = malloc(sizeof(expense_list_t));
    list->head = NULL;
    list->tail = NULL;

    // Add some expenses to the list
    add_expense(list, create_expense("Dinner", 50.00));
    add_expense(list, create_expense("Movie", 20.00));
    add_expense(list, create_expense("Flowers", 30.00));

    // Print the list of expenses
    printf("MyDearest's Expense Tracker:\n");
    print_expenses(list);

    // Free the memory allocated for the list of expenses
    free_expenses(list);
    free(list);

    return 0;
}