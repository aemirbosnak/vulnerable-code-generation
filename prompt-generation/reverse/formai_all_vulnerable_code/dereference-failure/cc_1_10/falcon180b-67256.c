//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 50
#define MAX_EXPENSES 1000
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
    char category[MAX_CATEGORIES][MAX_NAME_LEN];
    int category_count;
} Expense;

Expense *expenses = NULL;
int expense_count = 0;

void add_expense(char *name, float amount, char *category) {
    expenses = realloc(expenses, sizeof(Expense) * ++expense_count);
    strcpy(expenses[expense_count - 1].name, name);
    expenses[expense_count - 1].amount = amount;
    strcpy(expenses[expense_count - 1].category[0], category);
    expenses[expense_count - 1].category_count = 1;
}

void print_expenses() {
    printf("Name\tAmount\tCategory\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%s\t%.2f\t", expenses[i].name, expenses[i].amount);
        for (int j = 0; j < expenses[i].category_count; j++) {
            printf("%s\t", expenses[i].category[j]);
        }
        printf("\n");
    }
}

int main() {
    expenses = malloc(sizeof(Expense) * MAX_EXPENSES);
    expense_count = 0;

    add_expense("Groceries", 50.00, "Food");
    add_expense("Gas", 25.00, "Transportation");
    add_expense("Rent", 800.00, "Housing");
    add_expense("Utilities", 100.00, "Housing");
    add_expense("Clothing", 75.00, "Shopping");

    print_expenses();

    return 0;
}