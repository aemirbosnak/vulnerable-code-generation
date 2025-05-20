//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome message
void welcome() {
    printf("\n\nWelcome to Sherlock's Expense Tracker, my dear Watson!\n\n");
    printf("Elementary, my dear Watson! Let us begin our investigation...\n");
}

// Get the expense details
void getExpenses(int* numExpenses, char*** expenseNames, int** expenseAmounts) {
    printf("How many expenses did you incur, Watson?\n");
    scanf("%d", numExpenses);

    // Allocate memory for the expense names and amounts
    *expenseNames = (char**)malloc(*numExpenses * sizeof(char*));
    *expenseAmounts = (int*)malloc(*numExpenses * sizeof(int));

    for (int i = 0; i < *numExpenses; i++) {
        printf("What expense did you incur, Watson? (Enter name, amount)\n");
        (*expenseNames)[i] = (char*)malloc(100 * sizeof(char));
        scanf(" %[^\n]", (*expenseNames)[i]);
        scanf("%d", &(*expenseAmounts)[i]);
    }
}

// Calculate the total expense
int calculateTotalExpense(int numExpenses, int* expenseAmounts) {
    int totalExpense = 0;
    for (int i = 0; i < numExpenses; i++) {
        totalExpense += expenseAmounts[i];
    }
    return totalExpense;
}

// Print the expense report
void printExpenseReport(int numExpenses, char** expenseNames, int* expenseAmounts, int totalExpense) {
    printf("\n\nExpense Report, my dear Watson:\n\n");
    printf("-----------------------------------------------------------\n");
    printf("%-30s%-20s\n", "Expense Name", "Amount");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-30s%-20d\n", expenseNames[i], expenseAmounts[i]);
    }
    printf("-----------------------------------------------------------\n");
    printf("Total Expense: %d\n\n", totalExpense);
}

// Main function
int main() {
    welcome();

    // Get the expense details
    int numExpenses;
    char** expenseNames;
    int* expenseAmounts;
    getExpenses(&numExpenses, &expenseNames, &expenseAmounts);

    // Calculate the total expense
    int totalExpense = calculateTotalExpense(numExpenses, expenseAmounts);

    // Print the expense report
    printExpenseReport(numExpenses, expenseNames, expenseAmounts, totalExpense);

    // Free the allocated memory
    for (int i = 0; i < numExpenses; i++) {
        free(expenseNames[i]);
    }
    free(expenseNames);
    free(expenseAmounts);

    return 0;
}