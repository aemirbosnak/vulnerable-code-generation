//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char *description;
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;
Expense *tail = NULL;

void addExpense(char *description, float amount) {
    Expense *newExpense = malloc(sizeof(Expense));
    newExpense->description = strdup(description);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
        tail = newExpense;
    } else {
        tail->next = newExpense;
        tail = newExpense;
    }
}

void printExpenses() {
    Expense *current = head;

    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

float getTotalExpenses() {
    Expense *current = head;
    float total = 0.0;

    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }

    return total;
}

int main() {
    addExpense("Groceries", 100.0);
    addExpense("Rent", 1200.0);
    addExpense("Utilities", 200.0);
    addExpense("Transportation", 300.0);
    addExpense("Entertainment", 100.0);

    printExpenses();

    printf("Total expenses: $%.2f\n", getTotalExpenses());

    return 0;
}