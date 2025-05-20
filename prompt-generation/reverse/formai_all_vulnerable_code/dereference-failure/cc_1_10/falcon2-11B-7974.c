//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an expense
typedef struct {
    char description[50];
    double amount;
} Expense;

// Array to store expenses
Expense expenses[10];

// Function to add an expense
void addExpense(char *description, double amount) {
    Expense newExpense;
    strcpy(newExpense.description, description);
    newExpense.amount = amount;
    
    // Add the new expense to the end of the array
    int index = sizeof(expenses) / sizeof(Expense);
    if (index >= 10) {
        fprintf(stderr, "Expenses array is full, cannot add new expense.\n");
        return;
    }
    expenses[index] = newExpense;
}

// Function to view expenses
void viewExpenses() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Expense %d: %s ($%.2f)\n", i+1, expenses[i].description, expenses[i].amount);
    }
}

// Function to calculate total expenses
double calculateTotalExpenses() {
    int i;
    double total = 0.0;
    for (i = 0; i < 10; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    char description[50];
    double amount;
    
    // Get user input for expenses
    printf("Enter expense description: ");
    fgets(description, sizeof(description), stdin);
    sscanf(description, "%s $%.2f", description, &amount);
    addExpense(description, amount);
    
    // View and calculate total expenses
    viewExpenses();
    printf("Total expenses: $%.2f\n", calculateTotalExpenses());
    
    return 0;
}