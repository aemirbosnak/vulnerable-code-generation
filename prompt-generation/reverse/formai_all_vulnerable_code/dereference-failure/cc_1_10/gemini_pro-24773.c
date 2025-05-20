//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *category;
    double amount;
} Expense;

Expense *expenses = NULL;
int expenses_count = 0;

void add_expense(const char *category, double amount) {
    expenses = realloc(expenses, sizeof(Expense) * (expenses_count + 1));
    expenses[expenses_count].category = malloc(strlen(category) + 1);
    strcpy(expenses[expenses_count].category, category);
    expenses[expenses_count].amount = amount;
    expenses_count++;
}

void print_expense(const Expense *expense) {
    printf("%-12s $%.2f\n", expense->category, expense->amount);
}

void print_expenses() {
    for (int i = 0; i < expenses_count; i++) {
        print_expense(&expenses[i]);
    }
}

void free_expenses() {
    for (int i = 0; i < expenses_count; i++) {
        free(expenses[i].category);
    }
    free(expenses);
}

int main() {
    add_expense("Groceries", 100.50);
    add_expense("Rent", 1200.00);
    add_expense("Utilities", 150.00);
    add_expense("Transportation", 200.00);
    add_expense("Entertainment", 100.00);
    add_expense("Other", 50.00);

    print_expenses();

    free_expenses();

    return 0;
}