//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char* description;
    float amount;
    int type; // 0 for income, 1 for expense
} Transaction;

// Declare an array of transactions
Transaction transactions[MAX_TRANSACTIONS];

// Initialize the number of transactions to 0
int num_transactions = 0;

// Function to add a transaction to the array
void add_transaction(char* description, float amount, int type) {
    // Check if the array is full
    if (num_transactions == MAX_TRANSACTIONS) {
        printf("Error: The array of transactions is full.\n");
        return;
    }

    // Allocate memory for the description
    transactions[num_transactions].description = malloc(strlen(description) + 1);
    strcpy(transactions[num_transactions].description, description);

    // Set the amount and type of the transaction
    transactions[num_transactions].amount = amount;
    transactions[num_transactions].type = type;

    // Increment the number of transactions
    num_transactions++;
}

// Function to print the transactions
void print_transactions() {
    // Loop through the array of transactions
    for (int i = 0; i < num_transactions; i++) {
        // Print the description, amount, and type of the transaction
        printf("%s\t%.2f\t%s\n", transactions[i].description, transactions[i].amount, transactions[i].type == 0 ? "Income" : "Expense");
    }
}

// Function to calculate the total income
float calculate_total_income() {
    // Initialize the total income to 0
    float total_income = 0;

    // Loop through the array of transactions
    for (int i = 0; i < num_transactions; i++) {
        // If the transaction is an income, add the amount to the total income
        if (transactions[i].type == 0) {
            total_income += transactions[i].amount;
        }
    }

    // Return the total income
    return total_income;
}

// Function to calculate the total expense
float calculate_total_expense() {
    // Initialize the total expense to 0
    float total_expense = 0;

    // Loop through the array of transactions
    for (int i = 0; i < num_transactions; i++) {
        // If the transaction is an expense, add the amount to the total expense
        if (transactions[i].type == 1) {
            total_expense += transactions[i].amount;
        }
    }

    // Return the total expense
    return total_expense;
}

// Function to calculate the net income
float calculate_net_income() {
    // Calculate the total income and total expense
    float total_income = calculate_total_income();
    float total_expense = calculate_total_expense();

    // Calculate the net income
    float net_income = total_income - total_expense;

    // Return the net income
    return net_income;
}

// Main function
int main() {
    // Add some sample transactions
    add_transaction("Salary", 2000, 0);
    add_transaction("Rent", -500, 1);
    add_transaction("Groceries", -100, 1);
    add_transaction("Entertainment", -50, 1);

    // Print the transactions
    print_transactions();

    // Calculate the total income, total expense, and net income
    float total_income = calculate_total_income();
    float total_expense = calculate_total_expense();
    float net_income = calculate_net_income();

    // Print the total income, total expense, and net income
    printf("Total income: %.2f\n", total_income);
    printf("Total expense: %.2f\n", total_expense);
    printf("Net income: %.2f\n", net_income);

    return 0;
}