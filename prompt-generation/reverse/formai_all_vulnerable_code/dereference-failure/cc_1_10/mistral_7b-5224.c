//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_EXPENSES 100

typedef struct Expense {
    char name[MAX_NAME_LENGTH + 1];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;
Expense *current = NULL;

void init() {
    head = NULL;
}

void addExpense(const char *name, float amount) {
    Expense *newExpense = (Expense *)malloc(sizeof(Expense));

    if (newExpense == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;
}

void removeExpense(const char *name) {
    Expense *prev = NULL;
    Expense *current = head;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        fprintf(stderr, "Expense not found\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void viewExpenses() {
    Expense *expense = head;

    while (expense != NULL) {
        printf("%s: %.2f\n", expense->name, expense->amount);
        expense = expense->next;
    }
}

void searchExpense(const char *name) {
    Expense *expense = head;

    while (expense != NULL) {
        if (strcmp(expense->name, name) == 0) {
            printf("%s: %.2f\n", expense->name, expense->amount);
            return;
        }
        expense = expense->next;
    }

    fprintf(stderr, "Expense not found\n");
}

void setCurrentExpense(Expense *expense) {
    current = expense;
}

float getCurrentExpenseAmount() {
    return current->amount;
}

void main() {
    init();

    addExpense("Groceries", 50.0);
    addExpense("Gasoline", 30.0);
    addExpense("Dinner", 45.0);

    viewExpenses();

    searchExpense("Gasoline");
    searchExpense("Lunch");

    setCurrentExpense(head);
    printf("Current expense: %.2f\n", getCurrentExpenseAmount());

    removeExpense("Groceries");

    viewExpenses();
}