//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction structure
typedef struct {
    char description[100];
    float amount;
    int type; // 0 for income, 1 for expense
} transaction_t;

// Define the personal finance planner struct
typedef struct {
    char name[100];
    float balance;
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner(char* name) {
    personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
    strcpy(planner->name, name);
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner_t* planner, char* description, float amount, int type) {
    // Check if the number of transactions has reached the maximum
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: The maximum number of transactions has been reached.\n");
        return;
    }

    // Create a new transaction
    transaction_t transaction;
    strcpy(transaction.description, description);
    transaction.amount = amount;
    transaction.type = type;

    // Add the transaction to the planner
    planner->transactions[planner->num_transactions] = transaction;
    planner->num_transactions++;

    // Update the balance
    if (type == 0) {
        planner->balance += amount;
    } else {
        planner->balance -= amount;
    }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner_t* planner) {
    printf("Name: %s\n", planner->name);
    printf("Balance: %f\n", planner->balance);
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  %s: %f\n", planner->transactions[i].description, planner->transactions[i].amount);
    }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner_t* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t* planner = create_personal_finance_planner("John Doe");

    // Add some transactions
    add_transaction(planner, "Salary", 1000.0, 0);
    add_transaction(planner, "Rent", -500.0, 1);
    add_transaction(planner, "Groceries", -100.0, 1);
    add_transaction(planner, "Entertainment", -50.0, 1);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}