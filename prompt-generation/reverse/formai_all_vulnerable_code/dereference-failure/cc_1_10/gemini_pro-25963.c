//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store income and expense details
typedef struct {
    char *name;
    double amount;
} IncomeExpense;

// Function to create a new IncomeExpense struct
IncomeExpense *createIncomeExpense(char *name, double amount) {
    IncomeExpense *ie = malloc(sizeof(IncomeExpense));
    ie->name = strdup(name);
    ie->amount = amount;
    return ie;
}

// Function to add an income or expense to the list
void addIncomeExpense(IncomeExpense **list, int *length, IncomeExpense *ie) {
    *list = realloc(*list, (*length + 1) * sizeof(IncomeExpense));
    (*list)[*length] = *ie;
    (*length)++;
}

// Function to print the list of incomes and expenses
void printList(IncomeExpense *list, int length) {
    for (int i = 0; i < length; i++) {
        printf("%s: %.2f\n", list[i].name, list[i].amount);
    }
}

// Function to calculate the total income and expenses
double calculateTotal(IncomeExpense *list, int length) {
    double total = 0.0;
    for (int i = 0; i < length; i++) {
        total += list[i].amount;
    }
    return total;
}

// Function to free the memory allocated for the list
void freeList(IncomeExpense *list, int length) {
    for (int i = 0; i < length; i++) {
        free(list[i].name);
    }
    free(list);
}

int main() {
    // Create a list of incomes and expenses
    IncomeExpense *list = NULL;
    int length = 0;

    // Add some sample incomes and expenses
    addIncomeExpense(&list, &length, createIncomeExpense("Salary", 2000.00));
    addIncomeExpense(&list, &length, createIncomeExpense("Bonus", 500.00));
    addIncomeExpense(&list, &length, createIncomeExpense("Rent", -1000.00));
    addIncomeExpense(&list, &length, createIncomeExpense("Groceries", -200.00));
    addIncomeExpense(&list, &length, createIncomeExpense("Entertainment", -100.00));

    // Print the list of incomes and expenses
    printList(list, length);

    // Calculate the total income and expenses
    double total = calculateTotal(list, length);

    // Print the total income and expenses
    printf("Total income: %.2f\n", total);
    printf("Total expenses: %.2f\n", -total);

    // Free the memory allocated for the list
    freeList(list, length);

    return 0;
}