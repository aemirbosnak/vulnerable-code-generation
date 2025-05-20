//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char *description;
    double amount;
    struct expense *next;
};

struct expense *head = NULL;
struct expense *tail = NULL;

void add_expense(char *description, double amount) {
    struct expense *new_expense = malloc(sizeof(struct expense));
    new_expense->description = malloc(strlen(description) + 1);
    strcpy(new_expense->description, description);
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
    add_expense("Groceries", 100.00);
    add_expense("Gas", 50.00);
    add_expense("Rent", 1200.00);
    add_expense("Electricity", 100.00);
    add_expense("Water", 50.00);
    add_expense("Internet", 50.00);
    add_expense("Phone", 50.00);
    add_expense("Car insurance", 100.00);
    add_expense("Health insurance", 100.00);
    add_expense("Life insurance", 50.00);

    print_expenses();

    free_expenses();

    return 0;
}