//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[256];
    float amount;
    struct expense *next;
};

struct expense *head = NULL;

void add_expense(char *name, float amount) {
    struct expense *new_expense = malloc(sizeof(struct expense));
    strcpy(new_expense->name, name);
    new_expense->amount = amount;
    new_expense->next = head;
    head = new_expense;
}

void print_expenses() {
    struct expense *current = head;
    while (current != NULL) {
        printf("%s: %.2f\n", current->name, current->amount);
        current = current->next;
    }
}

float total_expenses() {
    float total = 0;
    struct expense *current = head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

int main() {
    add_expense("Groceries", 100);
    add_expense("Rent", 1200);
    add_expense("Utilities", 200);
    add_expense("Entertainment", 50);

    print_expenses();

    printf("Total expenses: %.2f\n", total_expenses());

    return 0;
}