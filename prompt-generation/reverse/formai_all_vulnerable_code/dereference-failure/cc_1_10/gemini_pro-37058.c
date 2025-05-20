//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct expense {
    char *description;
    float amount;
    struct expense *next;
};

struct expense *head = NULL;
struct expense *tail = NULL;

void add_expense(char *description, float amount) {
    struct expense *new_expense = malloc(sizeof(struct expense));
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
    struct expense *current = head;

    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

void free_expenses() {
    struct expense *current = head;

    while (current != NULL) {
        struct expense *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }

    head = NULL;
    tail = NULL;
}

int main() {
    // Add some expenses
    add_expense("Groceries", 50.00);
    add_expense("Gas", 25.00);
    add_expense("Entertainment", 30.00);

    // Print the expenses
    print_expenses();

    // Free the expenses
    free_expenses();

    return 0;
}