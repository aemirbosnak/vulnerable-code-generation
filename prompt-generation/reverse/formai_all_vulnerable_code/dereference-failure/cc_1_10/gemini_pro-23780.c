//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense_t {
    char *description;
    float amount;
    struct expense_t *next;
} expense_t;

expense_t *head = NULL;
expense_t *tail = NULL;

void add_expense(char *description, float amount) {
    expense_t *new_expense = (expense_t *)malloc(sizeof(expense_t));
    new_expense->description = strdup(description);
    new_expense->amount = amount;
    new_expense->next = NULL;

    if (head == NULL) {
        head = new_expense;
        tail = new_expense;
    } else {
        tail->next = new_expense;
        tail = new_expense;
    }
}

void print_expenses() {
    expense_t *current = head;

    while (current != NULL) {
        printf("%s: %.2f\n", current->description, current->amount);
        current = current->next;
    }
}

void free_expenses() {
    expense_t *current = head;

    while (current != NULL) {
        expense_t *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }

    head = NULL;
    tail = NULL;
}

int main() {
    add_expense("Groceries", 100.00);
    add_expense("Gas", 50.00);
    add_expense("Rent", 1200.00);
    add_expense("Utilities", 150.00);
    add_expense("Entertainment", 50.00);

    print_expenses();

    free_expenses();

    return 0;
}