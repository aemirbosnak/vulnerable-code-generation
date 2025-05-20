//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database of accounts
struct account {
    int account_number;
    char name[50];
    double balance;
};

// Database of transactions
struct transaction {
    int transaction_id;
    int account_number;
    char type[50];
    double amount;
};

// Function to create a new account
struct account* create_account(int account_number, char *name, double balance) {
    struct account *new_account = (struct account*)malloc(sizeof(struct account));
    new_account->account_number = account_number;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    return new_account;
}

// Function to create a new transaction
struct transaction* create_transaction(int transaction_id, int account_number, char *type, double amount) {
    struct transaction *new_transaction = (struct transaction*)malloc(sizeof(struct transaction));
    new_transaction->transaction_id = transaction_id;
    new_transaction->account_number = account_number;
    strcpy(new_transaction->type, type);
    new_transaction->amount = amount;
    return new_transaction;
}

// Function to deposit money into an account
void deposit(struct account *account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(struct account *account, double amount) {
    account->balance -= amount;
}

// Function to print the details of an account
void print_account(struct account *account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Function to print the details of a transaction
void print_transaction(struct transaction *transaction) {
    printf("Transaction ID: %d\n", transaction->transaction_id);
    printf("Account Number: %d\n", transaction->account_number);
    printf("Type: %s\n", transaction->type);
    printf("Amount: %.2f\n", transaction->amount);
}

// Main function
int main() {
    // Create two accounts
    struct account *account1 = create_account(123456, "John Doe", 1000.00);
    struct account *account2 = create_account(654321, "Jane Doe", 2000.00);

    // Create three transactions
    struct transaction *transaction1 = create_transaction(1, 123456, "Deposit", 500.00);
    struct transaction *transaction2 = create_transaction(2, 654321, "Withdrawal", 300.00);
    struct transaction *transaction3 = create_transaction(3, 123456, "Transfer", 200.00);

    // Deposit money into account1
    deposit(account1, transaction1->amount);

    // Withdraw money from account2
    withdraw(account2, transaction2->amount);

    // Transfer money from account1 to account2
    withdraw(account1, transaction3->amount);
    deposit(account2, transaction3->amount);

    // Print the details of account1
    printf("Account 1:\n");
    print_account(account1);

    // Print the details of account2
    printf("\nAccount 2:\n");
    print_account(account2);

    // Print the details of transaction1
    printf("\nTransaction 1:\n");
    print_transaction(transaction1);

    // Print the details of transaction2
    printf("\nTransaction 2:\n");
    print_transaction(transaction2);

    // Print the details of transaction3
    printf("\nTransaction 3:\n");
    print_transaction(transaction3);

    return 0;
}