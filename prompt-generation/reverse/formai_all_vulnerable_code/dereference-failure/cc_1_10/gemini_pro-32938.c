//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the maximum length of a transaction description
#define MAX_DESCRIPTION_LENGTH 100

// Define the data structure for a transaction
typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
    time_t date;
} transaction_t;

// Define the data structure for the personal finance planner
typedef struct {
    char name[100];
    double balance;
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
void add_transaction(personal_finance_planner_t* planner, char* description, double amount, time_t date) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    strcpy(planner->transactions[planner->num_transactions].description, description);
    planner->transactions[planner->num_transactions].amount = amount;
    planner->transactions[planner->num_transactions].date = date;
    planner->num_transactions++;
    planner->balance += amount;
}

// Get the balance of the personal finance planner
double get_balance(personal_finance_planner_t* planner) {
    return planner->balance;
}

// Print the transactions of the personal finance planner
void print_transactions(personal_finance_planner_t* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s: %.2f (%s)\n", planner->transactions[i].description, planner->transactions[i].amount, ctime(&planner->transactions[i].date));
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

    // Add some transactions to the planner
    add_transaction(planner, "Salary", 2000.00, time(NULL));
    add_transaction(planner, "Rent", -1000.00, time(NULL));
    add_transaction(planner, "Groceries", -200.00, time(NULL));
    add_transaction(planner, "Savings", 500.00, time(NULL));

    // Get the balance of the planner
    double balance = get_balance(planner);
    printf("Balance: %.2f\n", balance);

    // Print the transactions of the planner
    print_transactions(planner);

    // Free the memory allocated for the planner
    free_personal_finance_planner(planner);

    return 0;
}