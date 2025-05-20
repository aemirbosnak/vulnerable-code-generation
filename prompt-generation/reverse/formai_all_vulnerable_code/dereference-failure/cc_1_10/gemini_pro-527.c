//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
/*
 * Claude Shannon's Expense Tracker
 *
 * This program helps you to track your expenses.
 *
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be tracked.
#define MAX_EXPENSES 100

// Define the structure of an expense.
typedef struct {
    char *description;
    double amount;
    int date;
} expense_t;

// Create an array of expenses.
expense_t expenses[MAX_EXPENSES];

// Initialize the number of expenses to 0.
int num_expenses = 0;

// Define the function to add an expense.
void add_expense(char *description, double amount, int date) {
    // Check if the number of expenses has reached the maximum.
    if (num_expenses == MAX_EXPENSES) {
        printf("Error: The maximum number of expenses has been reached.\n");
        return;
    }

    // Allocate memory for the description.
    expenses[num_expenses].description = malloc(strlen(description) + 1);

    // Copy the description into the array.
    strcpy(expenses[num_expenses].description, description);

    // Set the amount and date.
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].date = date;

    // Increment the number of expenses.
    num_expenses++;
}

// Define the function to print the expenses.
void print_expenses() {
    // Print the header.
    printf("-------------------------------------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Description", "Amount", "Date");
    printf("-------------------------------------------------------------------------------\n");

    // Print each expense.
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s %-10.2f %-10d\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }

    // Print the footer.
    printf("-------------------------------------------------------------------------------\n");
}

// Define the function to get the total expenses.
double get_total_expenses() {
    double total = 0.0;

    // Add up the amounts of all the expenses.
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    return total;
}

// Define the function to get the average expenses.
double get_average_expenses() {
    double average = 0.0;

    // Check if the number of expenses is 0.
    if (num_expenses == 0) {
        return 0.0;
    }

    // Add up the amounts of all the expenses.
    double total = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    // Calculate the average.
    average = total / num_expenses;

    return average;
}

// Define the function to get the maximum expenses.
double get_maximum_expenses() {
    double maximum = 0.0;

    // Check if the number of expenses is 0.
    if (num_expenses == 0) {
        return 0.0;
    }

    // Find the maximum amount.
    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].amount > maximum) {
            maximum = expenses[i].amount;
        }
    }

    return maximum;
}

// Define the function to get the minimum expenses.
double get_minimum_expenses() {
    double minimum = 0.0;

    // Check if the number of expenses is 0.
    if (num_expenses == 0) {
        return 0.0;
    }

    // Find the minimum amount.
    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].amount < minimum) {
            minimum = expenses[i].amount;
        }
    }

    return minimum;
}

// Define the main function.
int main() {
    // Add some sample expenses.
    add_expense("Groceries", 100.00, 20230301);
    add_expense("Gas", 50.00, 20230302);
    add_expense("Entertainment", 20.00, 20230303);
    add_expense("Rent", 1200.00, 20230304);
    add_expense("Utilities", 200.00, 20230305);

    // Print the expenses.
    print_expenses();

    // Get the total expenses.
    double total = get_total_expenses();

    // Get the average expenses.
    double average = get_average_expenses();

    // Get the maximum expenses.
    double maximum = get_maximum_expenses();

    // Get the minimum expenses.
    double minimum = get_minimum_expenses();

    // Print the summary.
    printf("\nSummary:\n");
    printf("Total expenses: $%.2f\n", total);
    printf("Average expenses: $%.2f\n", average);
    printf("Maximum expenses: $%.2f\n", maximum);
    printf("Minimum expenses: $%.2f\n", minimum);

    return 0;
}