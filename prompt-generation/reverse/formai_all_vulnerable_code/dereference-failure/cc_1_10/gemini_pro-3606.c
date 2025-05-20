//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char *description;
    float amount;
    struct Expense *next;
    struct Expense *prev;
};

struct Expense *head = NULL;
struct Expense *tail = NULL;

void add_expense(char *description, float amount) {
    struct Expense *new_expense = malloc(sizeof(struct Expense));
    new_expense->description = description;
    new_expense->amount = amount;
    new_expense->next = NULL;

    if (head == NULL) {
        head = new_expense;
        tail = new_expense;
    } else {
        tail->next = new_expense;
        new_expense->prev = tail;
        tail = new_expense;
    }
}

void print_expenses() {
    struct Expense *current_expense = head;

    while (current_expense != NULL) {
        printf("%s: $%.2f\n", current_expense->description, current_expense->amount);
        current_expense = current_expense->next;
    }
}

void free_expenses() {
    struct Expense *current_expense = head;

    while (current_expense != NULL) {
        struct Expense *next_expense = current_expense->next;
        free(current_expense->description);
        free(current_expense);
        current_expense = next_expense;
    }
}

int main() {
    add_expense("Rent", 1200.00);
    add_expense("Groceries", 200.00);
    add_expense("Utilities", 150.00);
    add_expense("Transportation", 300.00);
    add_expense("Entertainment", 100.00);

    print_expenses();

    free_expenses();

    return 0;
}