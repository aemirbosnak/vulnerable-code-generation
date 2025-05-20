//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char name[50];
    double amount;
    char type[20];
} Transaction;

typedef struct {
    char name[50];
    double balance;
    Transaction *transactions;
    int num_transactions;
} Account;

// Function prototypes
Account *create_account(char *name);
void add_transaction(Account *account, Transaction *transaction);
void print_account(Account *account);
void print_transactions(Account *account);
void free_account(Account *account);

// Main function
int main() {
    // Create a new account
    Account *account = create_account("My Account");

    // Add some transactions
    Transaction transaction1 = {"Rent", -1000, "Expense"};
    add_transaction(account, &transaction1);

    Transaction transaction2 = {"Salary", 2000, "Income"};
    add_transaction(account, &transaction2);

    Transaction transaction3 = {"Groceries", -200, "Expense"};
    add_transaction(account, &transaction3);

    // Print the account
    print_account(account);

    // Free the account
    free_account(account);

    return 0;
}

// Function definitions
Account *create_account(char *name) {
    // Allocate memory for the account
    Account *account = malloc(sizeof(Account));

    // Set the account's name
    strcpy(account->name, name);

    // Set the account's balance to 0
    account->balance = 0;

    // Set the account's transactions to NULL
    account->transactions = NULL;

    // Set the account's num_transactions to 0
    account->num_transactions = 0;

    // Return the account
    return account;
}

void add_transaction(Account *account, Transaction *transaction) {
    // Allocate memory for the new transaction
    Transaction *new_transaction = malloc(sizeof(Transaction));

    // Copy the transaction's data into the new transaction
    strcpy(new_transaction->name, transaction->name);
    new_transaction->amount = transaction->amount;
    strcpy(new_transaction->type, transaction->type);

    // Add the new transaction to the account's transactions list
    account->transactions = realloc(account->transactions, sizeof(Transaction) * (account->num_transactions + 1));
    account->transactions[account->num_transactions] = *new_transaction;

    // Increment the account's num_transactions
    account->num_transactions++;

    // Update the account's balance
    account->balance += transaction->amount;
}

void print_account(Account *account) {
    // Print the account's name
    printf("Account: %s\n", account->name);

    // Print the account's balance
    printf("Balance: %.2f\n", account->balance);

    // Print the account's transactions
    print_transactions(account);
}

void print_transactions(Account *account) {
    // Print the header
    printf("Transactions:\n");
    printf("Name\tAmount\tType\n");

    // Print each transaction
    for (int i = 0; i < account->num_transactions; i++) {
        Transaction *transaction = &account->transactions[i];
        printf("%s\t%.2f\t%s\n", transaction->name, transaction->amount, transaction->type);
    }
}

void free_account(Account *account) {
    // Free the account's transactions
    free(account->transactions);

    // Free the account
    free(account);
}