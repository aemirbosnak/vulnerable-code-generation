//FormAI DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define expense structure
struct Expense {
    char category[20];
    char description[50];
    float amount;
};

// Declare global variables
struct Expense* expenses;
int numExpenses = 0;

// Function to add expense
void addExpense() {
    // Allocate memory for new expense
    expenses = (struct Expense*) realloc(expenses, (numExpenses + 1) * sizeof(struct Expense));

    // Prompt user for expense details
    char category[20];
    char description[50];
    float amount;

    printf("Enter expense category: ");
    scanf("%s", category);
    printf("Enter expense description: ");
    scanf("%s", description);
    printf("Enter expense amount: $");
    scanf("%f", &amount);

    // Store expense details in memory
    strcpy(expenses[numExpenses].category, category);
    strcpy(expenses[numExpenses].description, description);
    expenses[numExpenses].amount = amount;

    printf("Expense added successfully!\n\n");

    numExpenses++;
}

// Function to display expense report
void displayExpenses() {
    // Check if there are any expenses
    if (numExpenses == 0) {
        printf("No expenses found!\n\n");
        return;
    }

    // Print header
    printf("%-20s | %-50s | %s\n", "Category", "Description", "Amount");
    printf("----------------------------------------------------------------------------------\n");

    // Loop through expenses and print details
    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        printf("%-20s | %-50s | $%.2f\n", expenses[i].category, expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }

    // Print footer
    printf("----------------------------------------------------------------------------------\n");
    printf("%-71s$%.2f\n\n", "Total:", total);
}

int main() {
    int choice;

    // Print welcome message
    printf("Welcome to the Expense Tracker program!\n");

    // Prompt user for choice and loop until exit
    while (1) {
        printf("What do you want to do?\n");
        printf("1. Add an expense\n");
        printf("2. Display all expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                printf("Thank you for using the Expense Tracker program!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
}