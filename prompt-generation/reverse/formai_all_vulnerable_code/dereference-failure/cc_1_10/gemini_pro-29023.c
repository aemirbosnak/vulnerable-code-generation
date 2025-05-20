//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions that can be stored.
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction.
typedef struct {
    char date[11];
    char description[50];
    double amount;
    char type[10];
} Transaction;

// Define the structure of the personal finance planner.
typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
    double balance;
} PersonalFinancePlanner;

// Create a new personal finance planner.
PersonalFinancePlanner* create_personal_finance_planner() {
    PersonalFinancePlanner* planner = malloc(sizeof(PersonalFinancePlanner));
    planner->num_transactions = 0;
    planner->balance = 0.0;
    return planner;
}

// Add a transaction to the personal finance planner.
void add_transaction(PersonalFinancePlanner* planner, Transaction transaction) {
    if (planner->num_transactions < MAX_TRANSACTIONS) {
        planner->transactions[planner->num_transactions] = transaction;
        planner->num_transactions++;
        if (strcmp(transaction.type, "INCOME") == 0) {
            planner->balance += transaction.amount;
        } else if (strcmp(transaction.type, "EXPENSE") == 0) {
            planner->balance -= transaction.amount;
        }
    }
}

// Print the personal finance planner.
void print_personal_finance_planner(PersonalFinancePlanner* planner) {
    printf("Personal Finance Planner\n");
    printf("-----------------------\n");
    printf("Date       Description          Amount   Type\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s  %s  %7.2f  %s\n", planner->transactions[i].date, planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
    printf("\n");
    printf("Balance: %7.2f\n", planner->balance);
}

// Free the memory allocated for the personal finance planner.
void free_personal_finance_planner(PersonalFinancePlanner* planner) {
    free(planner);
}

// Main function.
int main() {
    // Create a new personal finance planner.
    PersonalFinancePlanner* planner = create_personal_finance_planner();

    // Add some transactions to the personal finance planner.
    Transaction transaction1 = {"2023-01-01", "Salary", 1000.00, "INCOME"};
    add_transaction(planner, transaction1);
    Transaction transaction2 = {"2023-01-05", "Rent", -500.00, "EXPENSE"};
    add_transaction(planner, transaction2);
    Transaction transaction3 = {"2023-01-10", "Groceries", -100.00, "EXPENSE"};
    add_transaction(planner, transaction3);
    Transaction transaction4 = {"2023-01-15", "Entertainment", -50.00, "EXPENSE"};
    add_transaction(planner, transaction4);

    // Print the personal finance planner.
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner.
    free_personal_finance_planner(planner);

    return 0;
}