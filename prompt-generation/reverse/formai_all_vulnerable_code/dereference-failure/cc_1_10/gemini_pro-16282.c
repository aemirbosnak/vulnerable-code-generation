//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char *description;
    float amount;
    struct expense *next;
};

struct expense *root = NULL;

void add_expense(char *description, float amount) {
    struct expense *new_expense = malloc(sizeof(struct expense));
    new_expense->description = strdup(description);
    new_expense->amount = amount;
    new_expense->next = root;
    root = new_expense;
}

void print_expenses() {
    struct expense *current_expense = root;
    while (current_expense != NULL) {
        printf("%s: $%.2f\n", current_expense->description, current_expense->amount);
        current_expense = current_expense->next;
    }
}

void free_expenses() {
    struct expense *current_expense = root;
    while (current_expense != NULL) {
        struct expense *next_expense = current_expense->next;
        free(current_expense->description);
        free(current_expense);
        current_expense = next_expense;
    }
}

int main() {
    add_expense("Groceries", 50.00);
    add_expense("Gas", 25.00);
    add_expense("Entertainment", 20.00);
    add_expense("Rent", 1000.00);

    print_expenses();

    free_expenses();

    return 0;
}