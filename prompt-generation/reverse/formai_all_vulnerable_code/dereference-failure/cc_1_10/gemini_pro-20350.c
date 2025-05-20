//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store each expense
typedef struct Expense {
    char* name;
    double amount;
    char* category;
    char* date;
} Expense;

// Define an array to store all expenses
Expense expenses[100];

// Initialize the array of expenses
int num_expenses = 0;

// Declare functions
void add_expense(char* name, double amount, char* category, char* date);
void print_expenses();
void search_expenses(char* query);

// Main function
int main() {
    // Add some sample expenses
    add_expense("Dinner", 50.00, "Food", "2023-02-14");
    add_expense("Flowers", 25.00, "Gifts", "2023-02-14");
    add_expense("Movie tickets", 20.00, "Entertainment", "2023-02-14");

    // Print the expenses
    print_expenses();

    // Search for expenses
    search_expenses("Dinner");

    return 0;
}

// Add an expense to the array
void add_expense(char* name, double amount, char* category, char* date) {
    // Allocate memory for the new expense
    Expense* expense = malloc(sizeof(Expense));

    // Copy the expense data into the new expense
    expense->name = strdup(name);
    expense->amount = amount;
    expense->category = strdup(category);
    expense->date = strdup(date);

    // Add the new expense to the array
    expenses[num_expenses] = *expense;
    num_expenses++;
}

// Print the expenses in the array
void print_expenses() {
    // Iterate over the expenses and print them
    for (int i = 0; i < num_expenses; i++) {
        printf("Expense: %s\n", expenses[i].name);
        printf("Amount: $%.2f\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("Date: %s\n\n", expenses[i].date);
    }
}

// Search the expenses in the array for a given query
void search_expenses(char* query) {
    // Iterate over the expenses and search for the query
    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].name, query) != NULL) {
            // Print the matching expense
            printf("Expense: %s\n", expenses[i].name);
            printf("Amount: $%.2f\n", expenses[i].amount);
            printf("Category: %s\n", expenses[i].category);
            printf("Date: %s\n\n", expenses[i].date);
        }
    }
}