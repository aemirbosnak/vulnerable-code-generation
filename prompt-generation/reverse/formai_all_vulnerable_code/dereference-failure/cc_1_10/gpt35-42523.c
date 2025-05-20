//FormAI DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[50];
    char category[50];
    double amount;
    struct expense *nextExpense;
};

struct category {
    char name[50];
    double totalAmount;
    struct category *nextCategory;
};

struct expense *headExpense = NULL;
struct category *headCategory = NULL;

void addExpense(char name[], char category[], double amount) {
    struct expense *newExpense = (struct expense*) malloc(sizeof(struct expense));
    strcpy(newExpense->name, name);
    strcpy(newExpense->category, category);
    newExpense->amount = amount;

    if (headExpense == NULL) {
        headExpense = newExpense;
        headExpense->nextExpense = NULL;
    } else {
        newExpense->nextExpense = headExpense;
        headExpense = newExpense;
    }

    struct category *current = headCategory;
    while (current != NULL) {
        if (strcmp(current->name, category) == 0) {
            current->totalAmount += amount;
            return;
        }
        current = current->nextCategory;
    }

    struct category *newCategory = (struct category*) malloc(sizeof(struct category));
    strcpy(newCategory->name, category);
    newCategory->totalAmount = amount;

    if (headCategory == NULL) {
        headCategory = newCategory;
        headCategory->nextCategory = NULL;
    } else {
        newCategory->nextCategory = headCategory;
        headCategory = newCategory;
    }
}

void printExpenses() {
    printf("\n--- Expenses ---\n");

    struct expense *currentExpense = headExpense;
    while (currentExpense != NULL) {
        printf("%-20s | %-20s | $%.2f\n", currentExpense->name, currentExpense->category, currentExpense->amount);
        currentExpense = currentExpense->nextExpense;
    }

    printf("-----------------\n");

    printf("\n--- Categories ---\n");

    struct category *currentCategory = headCategory;
    while (currentCategory != NULL) {
        printf("%-20s | $%.2f\n", currentCategory->name, currentCategory->totalAmount);
        currentCategory = currentCategory->nextCategory;
    }

    printf("-------------------\n");
}

int main() {
    addExpense("Groceries", "Food", 70.42);
    addExpense("Gasoline", "Transportation", 35.21);
    addExpense("Electricity Bill", "Utilities", 90.05);
    addExpense("Dinner Out", "Food", 42.50);

    printExpenses();

    return 0;
}