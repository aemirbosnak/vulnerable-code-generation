//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[50];
    float amount;
} Expense;

// Function to print the menu
void printMenu() {
    printf("1. Add an expense\n");
    printf("2. Delete an expense\n");
    printf("3. List all expenses\n");
    printf("4. Quit\n");
}

// Function to get an integer from the user
int getInt(char *prompt) {
    int number;
    printf("%s", prompt);
    scanf("%d", &number);
    return number;
}

// Function to get a float from the user
float getFloat(char *prompt) {
    float number;
    printf("%s", prompt);
    scanf("%f", &number);
    return number;
}

// Function to get a string from the user
void getString(char *prompt, char *string) {
    printf("%s", prompt);
    scanf("%s", string);
}

// Function to add an expense
void addExpense(Expense *expenses, int *numExpenses) {
    // Get the description of the expense
    char description[50];
    getString("Enter the description of the expense: ", description);

    // Get the amount of the expense
    float amount = getFloat("Enter the amount of the expense: ");

    // Add the expense to the array
    expenses[*numExpenses].amount = amount;
    strcpy(expenses[*numExpenses].description, description);

    // Increment the number of expenses
    (*numExpenses)++;
}

// Function to delete an expense
void deleteExpense(Expense *expenses, int *numExpenses) {
    // Get the index of the expense to delete
    int index = getInt("Enter the index of the expense to delete: ");

    // Delete the expense from the array
    for (int i = index; i < *numExpenses - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    // Decrement the number of expenses
    (*numExpenses)--;
}

// Function to list all expenses
void listExpenses(Expense *expenses, int numExpenses) {
    // Print the header
    printf("Index\tDescription\t\tAmount\n");

    // Print the expenses
    for (int i = 0; i < numExpenses; i++) {
        printf("%d\t%s\t\t%.2f\n", i, expenses[i].description, expenses[i].amount);
    }
}

// Function to quit the program
void quit() {
    printf("Goodbye!\n");
    exit(0);
}

// Main function
int main() {
    // Initialize the expenses array
    Expense expenses[MAX_EXPENSES];

    // Initialize the number of expenses
    int numExpenses = 0;

    // Loop until the user quits
    bool running = true;
    while (running) {
        // Print the menu
        printMenu();

        // Get the user's choice
        int choice = getInt("Enter your choice: ");

        // Switch on the user's choice
        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                deleteExpense(expenses, &numExpenses);
                break;
            case 3:
                listExpenses(expenses, numExpenses);
                break;
            case 4:
                quit();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}