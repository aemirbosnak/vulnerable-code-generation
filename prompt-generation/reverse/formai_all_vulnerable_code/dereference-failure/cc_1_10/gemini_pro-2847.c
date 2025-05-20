//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char *description;
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void addExpense(char *description, float amount) {
    Expense *newExpense = malloc(sizeof(Expense));
    newExpense->description = strdup(description);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;
}

void printExpenses() {
    Expense *current = head;
    while (current != NULL) {
        printf("Description: %s\n", current->description);
        printf("Amount: %.2f\n", current->amount);
        current = current->next;
    }
}

int main() {
    // Initialize the expense tracker with a few starting expenses
    addExpense("Dinner at our favorite restaurant", 50.00);
    addExpense("Movie tickets", 20.00);
    addExpense("Gas for the car", 30.00);

    // Print out the current list of expenses
    printf("My Sweetheart's Expense Tracker:\n");
    printExpenses();

    // Add a new expense
    char description[100];
    float amount;
    printf("\nLet's add a new expense, my love. What did we spend money on today?\n");
    printf("Description: ");
    scanf("%s", description);
    printf("Amount: ");
    scanf("%f", &amount);
    addExpense(description, amount);

    // Print out the updated list of expenses
    printf("\nOur updated expense tracker:\n");
    printExpenses();

    // Calculate the total amount of expenses
    float total = 0.00;
    Expense *current = head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }

    // Print out the total amount of expenses
    printf("\nOur total expenses so far: %.2f\n", total);

    // Free the memory allocated for the expenses
    Expense *next;
    while (head != NULL) {
        next = head->next;
        free(head->description);
        free(head);
        head = next;
    }

    return 0;
}