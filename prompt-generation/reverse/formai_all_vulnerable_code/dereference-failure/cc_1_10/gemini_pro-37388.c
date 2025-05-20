//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char *description;
    double amount;
    struct expense *next;
} expense;

expense *head = NULL;

void add_expense(char *description, double amount) {
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

double get_total_expenses() {
    double total = 0;
    expense *current = head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

void free_expenses() {
    expense *current = head;
    while (current != NULL) {
        expense *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
}

int main() {
    add_expense("Groceries", 100);
    add_expense("Rent", 1200);
    add_expense("Utilities", 200);
    add_expense("Transportation", 300);
    add_expense("Entertainment", 100);

    print_expenses();
    printf("Total expenses: $%.2f\n", get_total_expenses());

    free_expenses();

    return 0;
}