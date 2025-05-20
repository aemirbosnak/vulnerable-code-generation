//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Structure for tracking expenses
struct expense {
    char description[50];
    float amount;
};

// Function to calculate total expenses
float getTotalExpenses(struct expense expenses[], int numExpenses) {
    float totalExpenses = 0;
    for(int i=0; i<numExpenses; i++) {
        totalExpenses += expenses[i].amount;
    }
    return totalExpenses;
}

int main() {
    // Welcome message
    printf("*** Personal Finance Planner ***\n");

    // Get budget from user
    float budget;
    printf("Enter your budget: $");
    scanf("%f", &budget);

    // Get number of expenses from user
    int numExpenses;
    printf("Enter the number of expenses: ");
    scanf("%d", &numExpenses);

    // Create array of expenses
    struct expense expenses[numExpenses];

    // Get expense details from user
    for(int i=0; i<numExpenses; i++) {
        printf("Enter expense description: ");
        scanf("%s", &expenses[i].description);
        printf("Enter expense amount: $");
        scanf("%f", &expenses[i].amount);
    }

    // Calculate total expenses
    float totalExpenses = getTotalExpenses(expenses, numExpenses);

    // Calculate remaining budget
    float remainingBudget = budget - totalExpenses;

    // Print budget report
    printf("\n*** Budget Report ***\n");
    printf("Budget: $%.2f\n", budget);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Remaining Budget: $%.2f\n", remainingBudget);

    return 0;
}