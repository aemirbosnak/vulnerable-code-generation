//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the account types
#define CHECKING 1
#define SAVINGS 2
#define CREDIT_CARD 3
#define LOAN 4

// Define the transaction types
#define DEPOSIT 1
#define WITHDRAWAL 2
#define TRANSFER 3

// Define the struct for an account
typedef struct account {
    int type;
    char *name;
    double balance;
} account;

// Define the struct for a transaction
typedef struct transaction {
    int type;
    double amount;
    char *from_account;
    char *to_account;
} transaction;

// Create an account
account *create_account(int type, char *name, double balance) {
    account *new_account = malloc(sizeof(account));
    new_account->type = type;
    new_account->name = name;
    new_account->balance = balance;
    return new_account;
}

// Create a transaction
transaction *create_transaction(int type, double amount, char *from_account, char *to_account) {
    transaction *new_transaction = malloc(sizeof(transaction));
    new_transaction->type = type;
    new_transaction->amount = amount;
    new_transaction->from_account = from_account;
    new_transaction->to_account = to_account;
    return new_transaction;
}

// Print an account
void print_account(account *account) {
    printf("%s: $%.2f\n", account->name, account->balance);
}

// Print a transaction
void print_transaction(transaction *transaction) {
    switch (transaction->type) {
        case DEPOSIT:
            printf("Deposited $%.2f into %s\n", transaction->amount, transaction->to_account);
            break;
        case WITHDRAWAL:
            printf("Withdrew $%.2f from %s\n", transaction->amount, transaction->from_account);
            break;
        case TRANSFER:
            printf("Transferred $%.2f from %s to %s\n", transaction->amount, transaction->from_account, transaction->to_account);
            break;
    }
}

// Get the balance of an account
double get_balance(account *account) {
    return account->balance;
}

// Deposit money into an account
void deposit(account *account, double amount) {
    account->balance += amount;
}

// Withdraw money from an account
void withdraw(account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Transfer money from one account to another
void transfer(account *from_account, account *to_account, double amount) {
    if (amount <= from_account->balance) {
        from_account->balance -= amount;
        to_account->balance += amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Main function
int main() {
    // Create some accounts
    account *checking_account = create_account(CHECKING, "Checking", 1000.00);
    account *savings_account = create_account(SAVINGS, "Savings", 2000.00);
    account *credit_card_account = create_account(CREDIT_CARD, "Credit Card", -1000.00);
    account *loan_account = create_account(LOAN, "Loan", -5000.00);

    // Create some transactions
    transaction *deposit_transaction = create_transaction(DEPOSIT, 500.00, "Savings", "Checking");
    transaction *withdrawal_transaction = create_transaction(WITHDRAWAL, 200.00, "Checking", "Cash");
    transaction *transfer_transaction = create_transaction(TRANSFER, 1000.00, "Checking", "Savings");

    // Print the accounts
    printf("Accounts:\n");
    print_account(checking_account);
    print_account(savings_account);
    print_account(credit_card_account);
    print_account(loan_account);

    // Print the transactions
    printf("Transactions:\n");
    print_transaction(deposit_transaction);
    print_transaction(withdrawal_transaction);
    print_transaction(transfer_transaction);

    // Free the memory
    free(checking_account);
    free(savings_account);
    free(credit_card_account);
    free(loan_account);
    free(deposit_transaction);
    free(withdrawal_transaction);
    free(transfer_transaction);

    return 0;
}