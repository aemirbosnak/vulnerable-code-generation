//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store expense data
typedef struct Expense {
    char name[50];
    int amount;
    char category[50];
} Expense;

// Define a function to add an expense
void addExpense(Expense *expenses, int *numExpenses) {
    // Allocate memory for a new expense
    expenses = (Expense *)realloc(expenses, (*numExpenses + 1) * sizeof(Expense));

    // Get the expense name, amount, and category from the user
    printf("Enter the expense name: ");
    scanf("%s", expenses[*numExpenses].name);

    printf("Enter the expense amount: ");
    scanf("%d", &expenses[*numExpenses].amount);

    printf("Enter the expense category: ");
    scanf("%s", expenses[*numExpenses].category);

    // Increment the number of expenses
    (*numExpenses)++;
}

// Define a function to print expenses
void printExpenses(Expense *expenses, int numExpenses) {
    // Print the expense data
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %d\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("\n");
    }
}

int main() {
    // Define an array of expenses
    Expense *expenses = NULL;

    // Define the number of expenses
    int numExpenses = 0;

    // Add some expenses
    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);

    // Print the expenses
    printExpenses(expenses, numExpenses);

    return 0;
}