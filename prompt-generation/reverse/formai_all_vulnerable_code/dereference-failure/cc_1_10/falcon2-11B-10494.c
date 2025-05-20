//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EXPENSES 10

struct Expense {
    char name[50];
    double amount;
    struct Expense* next;
};

struct Expense* expenses = NULL;

void add_expense(const char* name, double amount) {
    struct Expense* new_expense = malloc(sizeof(struct Expense));
    if (new_expense == NULL) {
        printf("Failed to allocate memory for new expense\n");
        return;
    }

    strcpy(new_expense->name, name);
    new_expense->amount = amount;

    if (expenses == NULL) {
        expenses = new_expense;
    } else {
        new_expense->next = expenses;
        expenses = new_expense;
    }
}

void display_expenses() {
    struct Expense* curr_expense = expenses;
    while (curr_expense!= NULL) {
        printf("%s: %f\n", curr_expense->name, curr_expense->amount);
        curr_expense = curr_expense->next;
    }
}

int main() {
    add_expense("Rent", 1000);
    add_expense("Groceries", 200);
    add_expense("Utilities", 150);
    add_expense("Transportation", 300);
    add_expense("Entertainment", 50);

    display_expenses();

    return 0;
}