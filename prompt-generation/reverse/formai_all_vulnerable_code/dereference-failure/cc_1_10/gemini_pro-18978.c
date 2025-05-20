//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct Account {
    int account_number;
    char name[50];
    double balance;
} Account;

// Define the transaction structure
typedef struct Transaction {
    int account_number;
    char type[50];
    double amount;
} Transaction;

// Define the bank structure
typedef struct Bank {
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];
    int num_accounts;
    int num_transactions;
} Bank;

// Create a new bank
Bank* create_bank() {
    Bank* bank = malloc(sizeof(Bank));
    bank->num_accounts = 0;
    bank->num_transactions = 0;
    return bank;
}

// Add a new account to the bank
void add_account(Bank* bank, Account account) {
    bank->accounts[bank->num_accounts] = account;
    bank->num_accounts++;
}

// Add a new transaction to the bank
void add_transaction(Bank* bank, Transaction transaction) {
    bank->transactions[bank->num_transactions] = transaction;
    bank->num_transactions++;
}

// Get the account by account number
Account* get_account(Bank* bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }
    return NULL;
}

// Get the transactions by account number
Transaction* get_transactions(Bank* bank, int account_number) {
    Transaction* transactions = malloc(sizeof(Transaction) * bank->num_transactions);
    int j = 0;
    for (int i = 0; i < bank->num_transactions; i++) {
        if (bank->transactions[i].account_number == account_number) {
            transactions[j] = bank->transactions[i];
            j++;
        }
    }
    return transactions;
}

// Print the bank statement
void print_statement(Bank* bank, int account_number) {
    Account* account = get_account(bank, account_number);
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
    printf("\nTransactions:\n");
    Transaction* transactions = get_transactions(bank, account_number);
    for (int i = 0; i < bank->num_transactions; i++) {
        printf("%s %.2f\n", transactions[i].type, transactions[i].amount);
    }
    free(transactions);
}

int main() {
    // Create a new bank
    Bank* bank = create_bank();

    // Add some accounts to the bank
    Account account1 = {123456, "John Doe", 1000.00};
    add_account(bank, account1);
    Account account2 = {654321, "Jane Doe", 2000.00};
    add_account(bank, account2);

    // Add some transactions to the bank
    Transaction transaction1 = {123456, "Deposit", 500.00};
    add_transaction(bank, transaction1);
    Transaction transaction2 = {123456, "Withdrawal", 200.00};
    add_transaction(bank, transaction2);
    Transaction transaction3 = {654321, "Deposit", 1000.00};
    add_transaction(bank, transaction3);
    Transaction transaction4 = {654321, "Withdrawal", 500.00};
    add_transaction(bank, transaction4);

    // Print the bank statement for account 123456
    print_statement(bank, 123456);

    // Free the bank
    free(bank);

    return 0;
}