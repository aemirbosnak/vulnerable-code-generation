//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the struct for an expense
typedef struct expense {
    char *description;
    float amount;
    struct expense *next;
} expense_t;

// define the struct for the expenses list
typedef struct expenses_list {
    expense_t *head;
    expense_t *tail;
} expenses_list_t;

// create a new expense
expense_t *create_expense(char *description, float amount) {
    expense_t *new_expense = malloc(sizeof(expense_t));
    new_expense->description = strdup(description);
    new_expense->amount = amount;
    new_expense->next = NULL;
    return new_expense;
}

// add an expense to the list
void add_expense(expenses_list_t *list, expense_t *expense) {
    if (list->head == NULL) {
        list->head = expense;
        list->tail = expense;
    } else {
        list->tail->next = expense;
        list->tail = expense;
    }
}

// print the expenses list
void print_expenses(expenses_list_t *list) {
    expense_t *current = list->head;
    while (current != NULL) {
        printf("%s: %.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// get the total amount of expenses
float get_total_expenses(expenses_list_t *list) {
    float total = 0;
    expense_t *current = list->head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

// free the memory allocated for the expenses list
void free_expenses(expenses_list_t *list) {
    expense_t *current = list->head;
    while (current != NULL) {
        expense_t *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
}

// main function
int main() {
    // create a new expenses list
    expenses_list_t expenses;
    expenses.head = NULL;
    expenses.tail = NULL;

    // add some expenses to the list
    add_expense(&expenses, create_expense("Groceries", 100.00));
    add_expense(&expenses, create_expense("Entertainment", 50.00));
    add_expense(&expenses, create_expense("Transportation", 200.00));

    // print the expenses list
    print_expenses(&expenses);

    // get the total amount of expenses
    float total_expenses = get_total_expenses(&expenses);
    printf("Total expenses: %.2f\n", total_expenses);

    // free the memory allocated for the expenses list
    free_expenses(&expenses);

    return 0;
}