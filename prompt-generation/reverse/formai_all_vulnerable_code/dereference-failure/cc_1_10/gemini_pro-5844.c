//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char description[50];
    float amount;
    char type; // 'I' for income, 'E' for expense
} transaction;

// Define the structure of the personal finance planner
typedef struct {
    float balance;
    int num_transactions;
    transaction transactions[MAX_TRANSACTIONS];
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner* create_personal_finance_planner() {
    personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
    planner->balance = 0;
    planner->num_transactions = 0;
    return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, transaction* transaction) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }
    planner->transactions[planner->num_transactions] = *transaction;
    planner->num_transactions++;
    if (transaction->type == 'I') {
        planner->balance += transaction->amount;
    } else if (transaction->type == 'E') {
        planner->balance -= transaction->amount;
    } else {
        printf("Error: Invalid transaction type.\n");
    }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner* planner) {
    printf("Balance: %.2f\n", planner->balance);
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  %s %.2f %c\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
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
    transaction transaction1 = {"Salary", 1000.00, 'I'};
    add_transaction(planner, &transaction1);
    transaction transaction2 = {"Rent", 500.00, 'E'};
    add_transaction(planner, &transaction2);
    transaction transaction3 = {"Groceries", 200.00, 'E'};
    add_transaction(planner, &transaction3);
    transaction transaction4 = {"Entertainment", 100.00, 'E'};
    add_transaction(planner, &transaction4);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}