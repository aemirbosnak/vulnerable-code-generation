//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent an expense
typedef struct {
    char* description;
    float amount;
    char* category;
} Expense;

// Function to create a new expense
Expense* createExpense(char* description, float amount, char* category) {
    Expense* expense = malloc(sizeof(Expense));
    expense->description = strdup(description);
    expense->amount = amount;
    expense->category = strdup(category);
    return expense;
}

// Function to free the memory allocated for an expense
void freeExpense(Expense* expense) {
    free(expense->description);
    free(expense->category);
    free(expense);
}

// Function to print an expense
void printExpense(Expense* expense) {
    printf("Description: %s\n", expense->description);
    printf("Amount: %.2f\n", expense->amount);
    printf("Category: %s\n", expense->category);
}

// Function to get the total amount of expenses in a given category
float getTotalAmountInCategory(Expense** expenses, int numExpenses, char* category) {
    float totalAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i]->category, category) == 0) {
            totalAmount += expenses[i]->amount;
        }
    }
    return totalAmount;
}

// Function to get the most expensive category
char* getMostExpensiveCategory(Expense** expenses, int numExpenses) {
    char* mostExpensiveCategory = NULL;
    float maxAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        float totalAmountInCategory = getTotalAmountInCategory(expenses, numExpenses, expenses[i]->category);
        if (totalAmountInCategory > maxAmount) {
            maxAmount = totalAmountInCategory;
            mostExpensiveCategory = expenses[i]->category;
        }
    }
    return mostExpensiveCategory;
}

// Function to print a summary of expenses
void printSummary(Expense** expenses, int numExpenses) {
    printf("Total number of expenses: %d\n", numExpenses);

    // Calculate the total amount of expenses
    float totalAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        totalAmount += expenses[i]->amount;
    }
    printf("Total amount of expenses: %.2f\n", totalAmount);

    // Get the most expensive category
    char* mostExpensiveCategory = getMostExpensiveCategory(expenses, numExpenses);
    printf("Most expensive category: %s\n", mostExpensiveCategory);

    // Calculate the average amount of expenses
    float averageAmount = totalAmount / numExpenses;
    printf("Average amount of expenses: %.2f\n", averageAmount);
}

// Main function
int main() {
    // Create an array of expenses
    Expense* expenses[] = {
        createExpense("Groceries", 100.00, "Food"),
        createExpense("Gas", 50.00, "Transportation"),
        createExpense("Rent", 1200.00, "Housing"),
        createExpense("Utilities", 200.00, "Housing"),
        createExpense("Entertainment", 100.00, "Entertainment"),
        createExpense("Clothing", 50.00, "Clothing"),
        createExpense("Other", 50.00, "Other")
    };
    int numExpenses = sizeof(expenses) / sizeof(expenses[0]);

    // Print each expense
    for (int i = 0; i < numExpenses; i++) {
        printExpense(expenses[i]);
        printf("\n");
    }

    // Print a summary of expenses
    printSummary(expenses, numExpenses);

    // Free the memory allocated for each expense
    for (int i = 0; i < numExpenses; i++) {
        freeExpense(expenses[i]);
    }

    return 0;
}