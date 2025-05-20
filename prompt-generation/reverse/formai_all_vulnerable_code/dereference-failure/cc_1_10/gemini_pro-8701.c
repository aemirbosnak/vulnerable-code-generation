//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char description[100];
    double amount;
    struct Expense *next;
};

struct Expense *head = NULL;

void addExpense(char *description, double amount) {
    struct Expense *newExpense = (struct Expense *)malloc(sizeof(struct Expense));
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;
}

void printExpenses() {
    struct Expense *current = head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

void totalExpenses() {
    struct Expense *current = head;
    double total = 0;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    printf("Total expenses: $%.2f\n", total);
}

void clearExpenses() {
    struct Expense *current = head;
    while (current != NULL) {
        struct Expense *next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    printf("Welcome to the Expense Tracker Extravaganza!\n");
    printf("Let's get this party started and track those expenses!\n");

    addExpense("Coffee", 3.50);
    addExpense("Lunch", 12.00);
    addExpense("Dinner", 20.00);
    addExpense("Groceries", 50.00);
    addExpense("Rent", 1000.00);

    printf("Check out these awesome expenses you've been racking up!\n");
    printExpenses();

    printf("Whoa, that's a lot of dough! Let's see how much you've spent in total...\n");
    totalExpenses();

    printf("Time to clean up this mess! Let's erase those expenses and start fresh!\n");
    clearExpenses();

    printf("Boom! Expenses are gone like magic! You're welcome.\n");

    return 0;
}