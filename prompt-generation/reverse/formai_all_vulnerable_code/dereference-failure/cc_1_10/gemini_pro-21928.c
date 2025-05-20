//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char *description;
    float amount;
    char *date;
} Expense;

// Create an array of expenses
Expense expenses[MAX_EXPENSES];

// Get the number of expenses from the user
int get_num_expenses() {
    int num_expenses;
    printf("Enter the number of expenses you want to track: ");
    scanf("%d", &num_expenses);
    return num_expenses;
}

// Get the details of an expense from the user
Expense get_expense(int index) {
    Expense expense;
    char buffer[100];

    printf("Enter the description of expense %d: ", index + 1);
    scanf(" %[^\n]", buffer);
    expense.description = malloc(strlen(buffer) + 1);
    strcpy(expense.description, buffer);

    printf("Enter the amount of expense %d: ", index + 1);
    scanf("%f", &expense.amount);

    printf("Enter the date of expense %d (dd/mm/yyyy): ", index + 1);
    scanf(" %[^\n]", buffer);
    expense.date = malloc(strlen(buffer) + 1);
    strcpy(expense.date, buffer);

    return expense;
}

// Print the details of an expense
void print_expense(Expense expense) {
    printf("Description: %s\n", expense.description);
    printf("Amount: %.2f\n", expense.amount);
    printf("Date: %s\n", expense.date);
    printf("\n");
}

// Print the total amount of expenses
void print_total_expenses(float total_expenses) {
    printf("Total expenses: %.2f\n", total_expenses);
}

// Free the memory allocated for the expenses
void free_expenses(int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        free(expenses[i].description);
        free(expenses[i].date);
    }
}

// Main function
int main() {
    // Get the number of expenses from the user
    int num_expenses = get_num_expenses();

    // Get the details of each expense from the user
    for (int i = 0; i < num_expenses; i++) {
        expenses[i] = get_expense(i);
    }

    // Calculate the total amount of expenses
    float total_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }

    // Print the details of each expense
    for (int i = 0; i < num_expenses; i++) {
        print_expense(expenses[i]);
    }

    // Print the total amount of expenses
    print_total_expenses(total_expenses);

    // Free the memory allocated for the expenses
    free_expenses(num_expenses);

    return 0;
}