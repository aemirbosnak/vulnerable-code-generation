//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions.
#define MAX_TRANSACTIONS 100

// Define the transaction types.
#define INCOME 1
#define EXPENSE 2

// Define the transaction categories.
#define FOOD 1
#define HOUSING 2
#define TRANSPORTATION 3
#define ENTERTAINMENT 4
#define OTHER 5

// Define the transaction structure.
typedef struct transaction {
    int type;
    int category;
    float amount;
    char description[100];
} transaction_t;

// Define the personal finance planner structure.
typedef struct personal_finance_planner {
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
    float balance;
} personal_finance_planner_t;

// Create a new personal finance planner.
personal_finance_planner_t *create_personal_finance_planner() {
    personal_finance_planner_t *planner = malloc(sizeof(personal_finance_planner_t));
    planner->num_transactions = 0;
    planner->balance = 0.0f;
    return planner;
}

// Add a transaction to the personal finance planner.
void add_transaction(personal_finance_planner_t *planner, transaction_t transaction) {
    planner->transactions[planner->num_transactions] = transaction;
    planner->num_transactions++;
    planner->balance += transaction.amount;
}

// Print the personal finance planner.
void print_personal_finance_planner(personal_finance_planner_t *planner) {
    printf("Personal Finance Planner\n");
    printf("------------------------------------------------\n");
    printf("Number of Transactions: %d\n", planner->num_transactions);
    printf("Balance: $%.2f\n", planner->balance);
    printf("\n");
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        transaction_t transaction = planner->transactions[i];
        printf("  - Type: %s\n", transaction.type == INCOME ? "Income" : "Expense");
        printf("  - Category: %s\n", transaction.category == FOOD ? "Food" :
                                    transaction.category == HOUSING ? "Housing" :
                                    transaction.category == TRANSPORTATION ? "Transportation" :
                                    transaction.category == ENTERTAINMENT ? "Entertainment" :
                                    "Other");
        printf("  - Amount: $%.2f\n", transaction.amount);
        printf("  - Description: %s\n", transaction.description);
        printf("\n");
    }
}

// Free the memory allocated for the personal finance planner.
void free_personal_finance_planner(personal_finance_planner_t *planner) {
    free(planner);
}

int main() {
    // Create a new personal finance planner.
    personal_finance_planner_t *planner = create_personal_finance_planner();

    // Add some transactions to the personal finance planner.
    transaction_t transaction1 = {INCOME, FOOD, 100.0f, "Salary"};
    add_transaction(planner, transaction1);
    transaction_t transaction2 = {EXPENSE, HOUSING, 50.0f, "Rent"};
    add_transaction(planner, transaction2);
    transaction_t transaction3 = {EXPENSE, TRANSPORTATION, 25.0f, "Gas"};
    add_transaction(planner, transaction3);
    transaction_t transaction4 = {EXPENSE, ENTERTAINMENT, 10.0f, "Movie"};
    add_transaction(planner, transaction4);
    transaction_t transaction5 = {EXPENSE, OTHER, 5.0f, "Coffee"};
    add_transaction(planner, transaction5);

    // Print the personal finance planner.
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner.
    free_personal_finance_planner(planner);

    return 0;
}