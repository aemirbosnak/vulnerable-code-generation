//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char *description;
    float amount;
    struct expense *next;
};

struct expense *head = NULL;

void add_expense(char *description, float amount) {
    struct expense *new_expense = malloc(sizeof(struct expense));
    new_expense->description = malloc(strlen(description) + 1);
    strcpy(new_expense->description, description);
    new_expense->amount = amount;
    new_expense->next = NULL;

    if (head == NULL) {
        head = new_expense;
    } else {
        struct expense *current_expense = head;
        while (current_expense->next != NULL) {
            current_expense = current_expense->next;
        }
        current_expense->next = new_expense;
    }
}

void print_expenses() {
    struct expense *current_expense = head;
    while (current_expense != NULL) {
        printf("%s: %.2f\n", current_expense->description, current_expense->amount);
        current_expense = current_expense->next;
    }
}

void free_expenses() {
    struct expense *current_expense = head;
    while (current_expense != NULL) {
        struct expense *next_expense = current_expense->next;
        free(current_expense->description);
        free(current_expense);
        current_expense = next_expense;
    }
}

int main() {
    add_expense("Groceries", 100.00);
    add_expense("Rent", 1200.00);
    add_expense("Utilities", 200.00);
    add_expense("Entertainment", 100.00);

    print_expenses();

    free_expenses();

    return 0;
}