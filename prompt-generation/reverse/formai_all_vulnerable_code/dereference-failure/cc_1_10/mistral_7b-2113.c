//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_NAME_LEN 50
#define MAX_COST 10000

typedef struct Expense {
    char name[MAX_NAME_LEN];
    int cost;
    struct Expense *next;
} Expense;

Expense *expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char *name, int cost) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    Expense *new_expense = (Expense *) malloc(sizeof(Expense));
    strcpy(new_expense->name, name);
    new_expense->cost = cost;
    new_expense->next = NULL;

    expenses[num_expenses++] = new_expense;
}

void display_expenses(int start, int end) {
    if (start >= num_expenses || end < 0 || start > num_expenses - 1) {
        printf("Invalid expense range.\n");
        return;
    }

    if (start == end) {
        printf("%d. %s: $%d\n", start + 1, expenses[start]->name, expenses[start]->cost);
        return;
    }

    printf("%d. %s: $%d\n", start + 1, expenses[start]->name, expenses[start]->cost);
    display_expenses(start + 1, end);
}

void display_expenses_recursive() {
    if (num_expenses == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    display_expenses(0, num_expenses - 1);
}

int main() {
    add_expense("Groceries", 50);
    add_expense("Gasoline", 30);
    add_expense("Utilities", 70);
    add_expense("Rent", MAX_COST);

    printf("Expenses:\n");
    display_expenses_recursive();

    return 0;
}