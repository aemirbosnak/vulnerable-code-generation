//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the maximum length of a transaction description
#define MAX_DESCRIPTION_LENGTH 50

// Define the structure of a transaction
typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
    int date;
} Transaction;

// Define the structure of a personal finance planner
typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
    double balance;
} PersonalFinancePlanner;

// Create a new personal finance planner
PersonalFinancePlanner* create_personal_finance_planner() {
    PersonalFinancePlanner* planner = malloc(sizeof(PersonalFinancePlanner));
    planner->num_transactions = 0;
    planner->balance = 0.0;
    return planner;
}

// Add a transaction to a personal finance planner
void add_transaction(PersonalFinancePlanner* planner, Transaction transaction) {
    planner->transactions[planner->num_transactions] = transaction;
    planner->num_transactions++;
    planner->balance += transaction.amount;
}

// Print the transactions in a personal finance planner
void print_transactions(PersonalFinancePlanner* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        Transaction transaction = planner->transactions[i];
        printf("%s: $%.2f\n", transaction.description, transaction.amount);
    }
}

// Print the balance of a personal finance planner
void print_balance(PersonalFinancePlanner* planner) {
    printf("Balance: $%.2f\n", planner->balance);
}

// Free the memory allocated for a personal finance planner
void free_personal_finance_planner(PersonalFinancePlanner* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    PersonalFinancePlanner* planner = create_personal_finance_planner();

    // Add some transactions to the planner
    Transaction transaction1 = {"Salary", 1000.00, 20230101};
    add_transaction(planner, transaction1);

    Transaction transaction2 = {"Rent", -500.00, 20230105};
    add_transaction(planner, transaction2);

    Transaction transaction3 = {"Groceries", -100.00, 20230110};
    add_transaction(planner, transaction3);

    // Print the transactions in the planner
    print_transactions(planner);

    // Print the balance of the planner
    print_balance(planner);

    // Free the memory allocated for the planner
    free_personal_finance_planner(planner);

    return 0;
}