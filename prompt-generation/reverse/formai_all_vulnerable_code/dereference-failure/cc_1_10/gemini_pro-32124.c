//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
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
    char type; // 'D' for debit, 'C' for credit
} transaction_t;

// Define the structure of the personal finance planner
typedef struct {
    double balance;
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner() {
    personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
    if (planner == NULL) {
        return NULL;
    }
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Destroy a personal finance planner
void destroy_personal_finance_planner(personal_finance_planner_t* planner) {
    free(planner);
}

// Add a transaction to a personal finance planner
int add_transaction(personal_finance_planner_t* planner, const char* description, double amount, char type) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        return -1;
    }
    strcpy(planner->transactions[planner->num_transactions].description, description);
    planner->transactions[planner->num_transactions].amount = amount;
    planner->transactions[planner->num_transactions].type = type;
    planner->num_transactions++;
    if (type == 'D') {
        planner->balance -= amount;
    } else if (type == 'C') {
        planner->balance += amount;
    }
    return 0;
}

// Print the transactions in a personal finance planner
void print_transactions(personal_finance_planner_t* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s: $%.2f (%c)\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
}

// Get the balance of a personal finance planner
double get_balance(personal_finance_planner_t* planner) {
    return planner->balance;
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t* planner = create_personal_finance_planner();

    // Add some transactions to the planner
    add_transaction(planner, "Salary", 2000.00, 'C');
    add_transaction(planner, "Rent", 1000.00, 'D');
    add_transaction(planner, "Groceries", 200.00, 'D');
    add_transaction(planner, "Savings", 500.00, 'C');

    // Print the transactions
    print_transactions(planner);

    // Get the balance
    double balance = get_balance(planner);
    printf("Balance: $%.2f\n", balance);

    // Destroy the planner
    destroy_personal_finance_planner(planner);

    return 0;
}