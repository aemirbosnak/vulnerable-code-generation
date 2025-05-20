//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the types of transactions
enum transaction_type {
    INCOME,
    EXPENSE
};

// Define the structure of a transaction
struct transaction {
    enum transaction_type type;
    char *description;
    double amount;
};

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the global array of transactions
struct transaction transactions[MAX_TRANSACTIONS];

// Define the current number of transactions
int num_transactions = 0;

// Function to add a transaction to the global array of transactions
void add_transaction(enum transaction_type type, char *description, double amount) {
    // Check if the maximum number of transactions has been reached
    if (num_transactions == MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    // Allocate memory for the description
    char *description_copy = malloc(strlen(description) + 1);
    if (description_copy == NULL) {
        printf("Error: Out of memory.\n");
        return;
    }

    // Copy the description to the allocated memory
    strcpy(description_copy, description);

    // Create a new transaction
    struct transaction transaction = {
        .type = type,
        .description = description_copy,
        .amount = amount
    };

    // Add the transaction to the global array of transactions
    transactions[num_transactions++] = transaction;
}

// Function to print the global array of transactions
void print_transactions() {
    // Iterate over the global array of transactions
    for (int i = 0; i < num_transactions; i++) {
        // Print the transaction type
        if (transactions[i].type == INCOME) {
            printf("Income: ");
        } else {
            printf("Expense: ");
        }

        // Print the transaction description
        printf("%s\n", transactions[i].description);

        // Print the transaction amount
        printf("%.2f\n", transactions[i].amount);
    }
}

// Function to calculate the total income
double calculate_total_income() {
    // Initialize the total income to 0
    double total_income = 0;

    // Iterate over the global array of transactions
    for (int i = 0; i < num_transactions; i++) {
        // If the transaction type is income, add the amount to the total income
        if (transactions[i].type == INCOME) {
            total_income += transactions[i].amount;
        }
    }

    // Return the total income
    return total_income;
}

// Function to calculate the total expense
double calculate_total_expense() {
    // Initialize the total expense to 0
    double total_expense = 0;

    // Iterate over the global array of transactions
    for (int i = 0; i < num_transactions; i++) {
        // If the transaction type is expense, add the amount to the total expense
        if (transactions[i].type == EXPENSE) {
            total_expense += transactions[i].amount;
        }
    }

    // Return the total expense
    return total_expense;
}

// Function to calculate the net income
double calculate_net_income() {
    // Calculate the total income and total expense
    double total_income = calculate_total_income();
    double total_expense = calculate_total_expense();

    // Calculate the net income
    double net_income = total_income - total_expense;

    // Return the net income
    return net_income;
}

// Main function
int main() {
    // Add some sample transactions
    add_transaction(INCOME, "Salary", 5000);
    add_transaction(EXPENSE, "Rent", 1000);
    add_transaction(EXPENSE, "Groceries", 200);
    add_transaction(EXPENSE, "Transportation", 300);

    // Print the transactions
    print_transactions();

    // Calculate the total income, total expense, and net income
    double total_income = calculate_total_income();
    double total_expense = calculate_total_expense();
    double net_income = calculate_net_income();

    // Print the total income, total expense, and net income
    printf("Total Income: %.2f\n", total_income);
    printf("Total Expense: %.2f\n", total_expense);
    printf("Net Income: %.2f\n", net_income);

    return 0;
}