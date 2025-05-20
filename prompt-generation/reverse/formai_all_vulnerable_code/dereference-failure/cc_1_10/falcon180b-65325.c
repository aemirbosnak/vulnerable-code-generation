//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100 // Maximum number of expenses that can be tracked

typedef struct {
    char description[50]; // Expense description
    float amount; // Expense amount
    int month; // Month of the expense
    int year; // Year of the expense
} Expense;

void addExpense(Expense expenses[], int numExpenses, char* desc, float amt, int m, int y) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Error: Cannot add more expenses.\n");
        return;
    }

    int i = numExpenses;
    while (i > 0 && expenses[i-1].year > y || expenses[i-1].month > m) {
        i--;
    }

    expenses[i] = (Expense) {
       .description = desc,
       .amount = amt,
       .month = m,
       .year = y
    };

    numExpenses++;
}

void printExpenses(Expense expenses[], int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - $%.2f (%d/%d)\n", expenses[i].description, expenses[i].amount, expenses[i].month, expenses[i].year);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    addExpense(expenses, numExpenses, "Groceries", 50.23, 1, 2022);
    addExpense(expenses, numExpenses, "Rent", 1000.00, 1, 2022);
    addExpense(expenses, numExpenses, "Utilities", 75.67, 1, 2022);

    printExpenses(expenses, numExpenses);

    return 0;
}