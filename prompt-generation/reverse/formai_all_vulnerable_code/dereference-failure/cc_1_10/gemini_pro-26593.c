//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char description[50];
    double amount;
    int type; // 0 for income, 1 for expense
} transaction_t;

// Define the structure of a personal finance planner
typedef struct {
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
    double total_income;
    double total_expenses;
    double net_worth;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner() {
    personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
    planner->num_transactions = 0;
    planner->total_income = 0;
    planner->total_expenses = 0;
    planner->net_worth = 0;
    return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner_t* planner, transaction_t transaction) {
    planner->transactions[planner->num_transactions] = transaction;
    planner->num_transactions++;
    if (transaction.type == 0) {
        planner->total_income += transaction.amount;
    } else {
        planner->total_expenses += transaction.amount;
    }
    planner->net_worth = planner->total_income - planner->total_expenses;
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner_t* planner) {
    printf("Personal Finance Planner\n");
    printf("=======================\n");
    printf("Total income: %.2f\n", planner->total_income);
    printf("Total expenses: %.2f\n", planner->total_expenses);
    printf("Net worth: %.2f\n", planner->net_worth);
    printf("\n");
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf(" - %s: %.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
    }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner_t* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t* planner = create_personal_finance_planner();

    // Add some transactions to the personal finance planner
    transaction_t transaction1 = {"Salary", 1000.00, 0};
    add_transaction(planner, transaction1);
    transaction_t transaction2 = {"Rent", -500.00, 1};
    add_transaction(planner, transaction2);
    transaction_t transaction3 = {"Groceries", -100.00, 1};
    add_transaction(planner, transaction3);
    transaction_t transaction4 = {"Utilities", -50.00, 1};
    add_transaction(planner, transaction4);
    transaction_t transaction5 = {"Entertainment", -50.00, 1};
    add_transaction(planner, transaction5);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}