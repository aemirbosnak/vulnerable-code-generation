//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct transaction {
    char description[50];
    double amount;
    int type; // 0 for expense, 1 for income
} transaction;

// Define the structure of the personal finance planner
typedef struct personal_finance_planner {
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
    double total_income;
    double total_expenses;
    double net_worth;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner* create_personal_finance_planner() {
    personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
    planner->num_transactions = 0;
    planner->total_income = 0;
    planner->total_expenses = 0;
    planner->net_worth = 0;
    return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, transaction* transaction) {
    planner->transactions[planner->num_transactions] = *transaction;
    planner->num_transactions++;
    if (transaction->type == 0) {
        planner->total_expenses += transaction->amount;
    } else {
        planner->total_income += transaction->amount;
    }
    planner->net_worth = planner->total_income - planner->total_expenses;
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner* planner) {
    printf("Personal Finance Planner\n");
    printf("-----------------------\n");
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s: $%.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
    }
    printf("\n");
    printf("Total Income: $%.2f\n", planner->total_income);
    printf("Total Expenses: $%.2f\n", planner->total_expenses);
    printf("Net Worth: $%.2f\n", planner->net_worth);
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_personal_finance_planner();

    // Add some transactions to the personal finance planner
    transaction transaction1 = {"Salary", 2000, 1};
    add_transaction(planner, &transaction1);
    transaction transaction2 = {"Rent", -500, 0};
    add_transaction(planner, &transaction2);
    transaction transaction3 = {"Groceries", -100, 0};
    add_transaction(planner, &transaction3);
    transaction transaction4 = {"Entertainment", -50, 0};
    add_transaction(planner, &transaction4);
    transaction transaction5 = {"Savings", 200, 1};
    add_transaction(planner, &transaction5);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}