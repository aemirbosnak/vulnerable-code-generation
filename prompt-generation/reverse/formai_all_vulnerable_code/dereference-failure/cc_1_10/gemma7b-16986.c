//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define an array to store expense details
struct Expense {
    char name[50];
    int amount;
    char category[50];
};

// Define a function to add an expense
void addExpense(struct Expense *expenses, int *numExpenses) {
    // Allocate memory for a new expense
    expenses = (struct Expense *)realloc(expenses, (*numExpenses + 1) * sizeof(struct Expense));

    // Get the expense details from the user
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%d", &expenses[*numExpenses].amount);

    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses].category);

    // Increment the number of expenses
    (*numExpenses)++;
}

// Define a function to display expenses
void displayExpenses(struct Expense *expenses, int numExpenses) {
    // Print the expense details
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %d\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("\n");
    }
}

int main() {
    // Create an array of expenses
    struct Expense *expenses = NULL;

    // Initialize the number of expenses to 0
    int numExpenses = 0;

    // Add some expenses
    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);

    // Display the expenses
    displayExpenses(expenses, numExpenses);

    return 0;
}