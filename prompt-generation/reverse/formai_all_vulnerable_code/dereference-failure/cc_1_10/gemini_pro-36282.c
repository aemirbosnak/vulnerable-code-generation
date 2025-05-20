//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a transaction
typedef struct {
    char *description;
    double amount;
    int type; // 0 for expense, 1 for income
} Transaction;

// Define the structure of a budget
typedef struct {
    double income;
    double expenses;
    double savings;
} Budget;

// Create a new transaction
Transaction *new_transaction(char *description, double amount, int type) {
    Transaction *transaction = malloc(sizeof(Transaction));
    transaction->description = description;
    transaction->amount = amount;
    transaction->type = type;
    return transaction;
}

// Create a new budget
Budget *new_budget(double income, double expenses, double savings) {
    Budget *budget = malloc(sizeof(Budget));
    budget->income = income;
    budget->expenses = expenses;
    budget->savings = savings;
    return budget;
}

// Add a transaction to a budget
void add_transaction(Budget *budget, Transaction *transaction) {
    if (transaction->type == 0) {
        budget->expenses += transaction->amount;
    } else {
        budget->income += transaction->amount;
    }
}

// Calculate the savings for a budget
double calculate_savings(Budget *budget) {
    return budget->income - budget->expenses;
}

// Print a budget
void print_budget(Budget *budget) {
    printf("Income: $%.2f\n", budget->income);
    printf("Expenses: $%.2f\n", budget->expenses);
    printf("Savings: $%.2f\n", calculate_savings(budget));
}

// Main function
int main() {
    // Create a new budget
    Budget *budget = new_budget(2000, 1500, 500);

    // Create some transactions
    Transaction *transaction1 = new_transaction("Rent", 1000, 0);
    Transaction *transaction2 = new_transaction("Groceries", 200, 0);
    Transaction *transaction3 = new_transaction("Salary", 2000, 1);

    // Add the transactions to the budget
    add_transaction(budget, transaction1);
    add_transaction(budget, transaction2);
    add_transaction(budget, transaction3);

    // Print the budget
    print_budget(budget);

    return 0;
}