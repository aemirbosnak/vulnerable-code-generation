//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum number of transactions that can be stored.
#define MAX_TRANSACTIONS 100

// Defines the structure of a transaction.
typedef struct {
    char* payee;          // The name of the payee.
    float amount;         // The amount of the transaction.
    char* category;       // The category of the transaction.
    char* date;           // The date of the transaction.
} Transaction;

// Defines the structure of a personal finance planner.
typedef struct {
    Transaction* transactions;  // The array of transactions.
    int num_transactions;       // The number of transactions.
} PersonalFinancePlanner;

// Creates a new personal finance planner.
PersonalFinancePlanner* create_personal_finance_planner() {
    PersonalFinancePlanner* planner = malloc(sizeof(PersonalFinancePlanner));
    planner->transactions = malloc(sizeof(Transaction) * MAX_TRANSACTIONS);
    planner->num_transactions = 0;
    return planner;
}

// Adds a transaction to the personal finance planner.
void add_transaction(PersonalFinancePlanner* planner, Transaction* transaction) {
    if (planner->num_transactions < MAX_TRANSACTIONS) {
        planner->transactions[planner->num_transactions] = *transaction;
        planner->num_transactions++;
    } else {
        printf("Error: Too many transactions. Unable to add new transaction.\n");
    }
}

// Prints the transactions in the personal finance planner.
void print_transactions(PersonalFinancePlanner* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        Transaction* transaction = &planner->transactions[i];
        printf("%s, %f, %s, %s\n", transaction->payee, transaction->amount, transaction->category, transaction->date);
    }
}

// Frees the memory used by the personal finance planner.
void free_personal_finance_planner(PersonalFinancePlanner* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        free(planner->transactions[i].payee);
        free(planner->transactions[i].category);
        free(planner->transactions[i].date);
    }
    free(planner->transactions);
    free(planner);
}

// Main function.
int main() {
    // Creates a new personal finance planner.
    PersonalFinancePlanner* planner = create_personal_finance_planner();

    // Adds some transactions to the personal finance planner.
    Transaction transaction1 = {"Amazon", 100.00, "Shopping", "2023-01-01"};
    add_transaction(planner, &transaction1);
    Transaction transaction2 = {"Walmart", 50.00, "Groceries", "2023-01-05"};
    add_transaction(planner, &transaction2);
    Transaction transaction3 = {"Starbucks", 25.00, "Food & Dining", "2023-01-10"};
    add_transaction(planner, &transaction3);

    // Prints the transactions in the personal finance planner.
    print_transactions(planner);

    // Frees the memory used by the personal finance planner.
    free_personal_finance_planner(planner);

    return 0;
}