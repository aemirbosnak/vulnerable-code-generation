//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char *description;
    float amount;
    struct expense *next;
} expense;

expense *head = NULL;

void add_expense(char *description, float amount) {
    expense *new_expense = malloc(sizeof(expense));
    new_expense->description = strdup(description);
    new_expense->amount = amount;
    new_expense->next = head;
    head = new_expense;
}

void print_expenses() {
    expense *current = head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

void free_expenses() {
    expense *current = head;
    while (current != NULL) {
        expense *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    add_expense("Groceries", 50.00);
    add_expense("Gas", 25.00);
    add_expense("Rent", 1000.00);
    add_expense("Utilities", 150.00);
    add_expense("Entertainment", 50.00);

    print_expenses();

    free_expenses();

    return 0;
}