//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the account types
#define ACCOUNT_TYPE_SAVINGS 1
#define ACCOUNT_TYPE_CHECKING 2
#define ACCOUNT_TYPE_CREDIT 3

// Define the transaction types
#define TRANSACTION_TYPE_DEPOSIT 1
#define TRANSACTION_TYPE_WITHDRAWAL 2
#define TRANSACTION_TYPE_TRANSFER 3

// Define the maximum number of accounts
#define MAX_ACCOUNTS 10

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the account structure
typedef struct {
    int account_type;
    double balance;
    char name[50];
} Account;

// Define the transaction structure
typedef struct {
    int transaction_type;
    double amount;
    char description[50];
} Transaction;

// Define the personal finance planner structure
typedef struct {
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];
    int num_accounts;
    int num_transactions;
} PersonalFinancePlanner;

// Create a new personal finance planner
PersonalFinancePlanner* create_personal_finance_planner() {
    PersonalFinancePlanner* planner = (PersonalFinancePlanner*)malloc(sizeof(PersonalFinancePlanner));
    planner->num_accounts = 0;
    planner->num_transactions = 0;
    return planner;
}

// Add an account to the personal finance planner
void add_account(PersonalFinancePlanner* planner, Account account) {
    planner->accounts[planner->num_accounts] = account;
    planner->num_accounts++;
}

// Add a transaction to the personal finance planner
void add_transaction(PersonalFinancePlanner* planner, Transaction transaction) {
    planner->transactions[planner->num_transactions] = transaction;
    planner->num_transactions++;
}

// Print the personal finance planner
void print_personal_finance_planner(PersonalFinancePlanner* planner) {
    // Print the accounts
    printf("Accounts:\n");
    for (int i = 0; i < planner->num_accounts; i++) {
        Account account = planner->accounts[i];
        printf("  - %s: $%.2f\n", account.name, account.balance);
    }

    // Print the transactions
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        Transaction transaction = planner->transactions[i];
        printf("  - %s: $%.2f - %s\n", transaction.description, transaction.amount, transaction.description);
    }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(PersonalFinancePlanner* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    PersonalFinancePlanner* planner = create_personal_finance_planner();

    // Add some accounts to the personal finance planner
    Account savings_account = {ACCOUNT_TYPE_SAVINGS, 1000.00, "Savings Account"};
    add_account(planner, savings_account);

    Account checking_account = {ACCOUNT_TYPE_CHECKING, 500.00, "Checking Account"};
    add_account(planner, checking_account);

    Account credit_account = {ACCOUNT_TYPE_CREDIT, -100.00, "Credit Card"};
    add_account(planner, credit_account);

    // Add some transactions to the personal finance planner
    Transaction deposit_transaction = {TRANSACTION_TYPE_DEPOSIT, 100.00, "Deposit"};
    add_transaction(planner, deposit_transaction);

    Transaction withdrawal_transaction = {TRANSACTION_TYPE_WITHDRAWAL, 50.00, "Withdrawal"};
    add_transaction(planner, withdrawal_transaction);

    Transaction transfer_transaction = {TRANSACTION_TYPE_TRANSFER, 100.00, "Transfer from Savings to Checking"};
    add_transaction(planner, transfer_transaction);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}