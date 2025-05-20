//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure of a transaction
typedef struct {
    char* description;
    double amount;
    int category;
} transaction;

// Define the categories of transactions
#define CATEGORY_INCOME 1
#define CATEGORY_EXPENSE 2

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Create an array of transactions
transaction transactions[MAX_TRANSACTIONS];

// Define the current number of transactions
int num_transactions = 0;

// Get the user's input
void get_input() {
    char input[100];
    double amount;
    int category;

    printf("Enter a transaction (description, amount, category): ");
    scanf("%s %lf %d", input, &amount, &category);

    // Create a new transaction
    transaction new_transaction;
    new_transaction.description = malloc(strlen(input) + 1);
    strcpy(new_transaction.description, input);
    new_transaction.amount = amount;
    new_transaction.category = category;

    // Add the new transaction to the array
    transactions[num_transactions++] = new_transaction;
}

// Print the transactions
void print_transactions() {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: %lf (%d)\n", transactions[i].description, transactions[i].amount, transactions[i].category);
    }
}

// Free the memory allocated for the transactions
void free_transactions() {
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i].description);
    }
}

// Calculate the total income
double calculate_total_income() {
    double total_income = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].category == CATEGORY_INCOME) {
            total_income += transactions[i].amount;
        }
    }
    return total_income;
}

// Calculate the total expense
double calculate_total_expense() {
    double total_expense = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].category == CATEGORY_EXPENSE) {
            total_expense += transactions[i].amount;
        }
    }
    return total_expense;
}

// Calculate the net income
double calculate_net_income() {
    double total_income = calculate_total_income();
    double total_expense = calculate_total_expense();
    return total_income - total_expense;
}

// Print a summary of the transactions
void print_summary() {
    double total_income = calculate_total_income();
    double total_expense = calculate_total_expense();
    double net_income = calculate_net_income();

    printf("Total income: %lf\n", total_income);
    printf("Total expense: %lf\n", total_expense);
    printf("Net income: %lf\n", net_income);
}

// Main function
int main() {
    // Get the user's input
    get_input();

    // Print the transactions
    print_transactions();

    // Print a summary of the transactions
    print_summary();

    // Free the memory allocated for the transactions
    free_transactions();

    return 0;
}