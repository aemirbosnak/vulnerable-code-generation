//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double amount;
} Transaction;

typedef struct {
    char *name;
    double balance;
    Transaction *transactions;
    int num_transactions;
} Account;

int main() {
    // Create some accounts
    Account checking = {"Checking", 1000.00};
    Account savings = {"Savings", 2000.00};
    Account credit_card = {"Credit Card", -500.00};

    // Create some transactions
    Transaction transaction1 = {"Rent", -1200.00};
    Transaction transaction2 = {"Groceries", -100.00};
    Transaction transaction3 = {"Salary", 2000.00};

    // Add the transactions to the accounts
    checking.transactions = malloc(sizeof(Transaction) * 2);
    checking.transactions[0] = transaction1;
    checking.transactions[1] = transaction2;
    checking.num_transactions = 2;

    savings.transactions = malloc(sizeof(Transaction) * 1);
    savings.transactions[0] = transaction3;
    savings.num_transactions = 1;

    // Print the account balances
    printf("Thank you for using our Personal Finance Planner!\n");
    printf("Your current account balances are:\n");
    printf("    Checking: $%.2f\n", checking.balance);
    printf("    Savings: $%.2f\n", savings.balance);
    printf("    Credit Card: $%.2f\n", credit_card.balance);

    // Free the memory allocated for the accounts and transactions
    free(checking.transactions);
    free(savings.transactions);
    free(credit_card.name);
    free(checking.name);
    free(savings.name);

    return 0;
}