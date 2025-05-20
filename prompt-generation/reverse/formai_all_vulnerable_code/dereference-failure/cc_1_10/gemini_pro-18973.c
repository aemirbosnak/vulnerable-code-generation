//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char *description;
    double amount;
    struct expense *next;
} expense_t;

expense_t *head = NULL;

void add_expense(char *description, double amount) {
    expense_t *new_expense = malloc(sizeof(expense_t));
    new_expense->description = strdup(description);
    new_expense->amount = amount;
    new_expense->next = head;
    head = new_expense;
}

void print_expenses() {
    expense_t *current = head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

double get_total_expenses() {
    double total = 0;
    expense_t *current = head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

int main() {
    add_expense("Groceries", 100);
    add_expense("Gas", 50);
    add_expense("Rent", 1500);
    add_expense("Utilities", 200);
    add_expense("Entertainment", 100);

    print_expenses();

    printf("Total expenses: $%.2f\n", get_total_expenses());

    return 0;
}