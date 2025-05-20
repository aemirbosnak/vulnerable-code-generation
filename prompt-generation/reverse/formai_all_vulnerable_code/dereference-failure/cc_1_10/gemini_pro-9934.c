//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char *description;
    long amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void addExpense(char *description, long amount) {
    Expense *newExpense = malloc(sizeof(Expense));
    newExpense->description = strdup(description);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        Expense *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newExpense;
    }
}

void printExpenses() {
    Expense *current = head;
    while (current != NULL) {
        printf("%s: %ld\n", current->description, current->amount);
        current = current->next;
    }
}

void freeExpenses() {
    Expense *current = head;
    while (current != NULL) {
        Expense *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    addExpense("A new pair of shoes", 10);
    addExpense("A bag of flour", 5);
    addExpense("A new sword", 20);
    addExpense("A new horse", 100);

    printExpenses();

    freeExpenses();

    return 0;
}