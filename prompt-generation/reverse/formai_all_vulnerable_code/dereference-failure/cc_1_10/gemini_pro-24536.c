//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Bank account structure
typedef struct bank_account {
    char *name;
    int account_number;
    double balance;
} bank_account;

// Create a new bank account
bank_account *create_account(char *name, int account_number, double balance) {
    bank_account *account = malloc(sizeof(bank_account));
    account->name = name;
    account->account_number = account_number;
    account->balance = balance;
    return account;
}

// Deposit money into a bank account
void deposit(bank_account *account, double amount) {
    account->balance += amount;
}

// Withdraw money from a bank account
void withdraw(bank_account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Transfer money from one bank account to another
void transfer(bank_account *from_account, bank_account *to_account, double amount) {
    if (amount <= from_account->balance) {
        from_account->balance -= amount;
        to_account->balance += amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Print the details of a bank account
void print_account(bank_account *account) {
    printf("Name: %s\n", account->name);
    printf("Account number: %d\n", account->account_number);
    printf("Balance: %f\n", account->balance);
}

int main() {
    // Create a bank account for John Doe with account number 12345 and an initial balance of $1000
    bank_account *john_doe_account = create_account("John Doe", 12345, 1000.00);

    // Print the details of John Doe's bank account
    printf("John Doe's account details:\n");
    print_account(john_doe_account);

    // Deposit $500 into John Doe's bank account
    deposit(john_doe_account, 500.00);

    // Print the details of John Doe's bank account after the deposit
    printf("John Doe's account details after the deposit:\n");
    print_account(john_doe_account);

    // Withdraw $300 from John Doe's bank account
    withdraw(john_doe_account, 300.00);

    // Print the details of John Doe's bank account after the withdrawal
    printf("John Doe's account details after the withdrawal:\n");
    print_account(john_doe_account);

    // Transfer $200 from John Doe's bank account to Jane Doe's bank account
    bank_account *jane_doe_account = create_account("Jane Doe", 54321, 500.00);
    transfer(john_doe_account, jane_doe_account, 200.00);

    // Print the details of John Doe's bank account after the transfer
    printf("John Doe's account details after the transfer:\n");
    print_account(john_doe_account);

    // Print the details of Jane Doe's bank account after the transfer
    printf("Jane Doe's account details after the transfer:\n");
    print_account(jane_doe_account);

    // Free the memory allocated for the bank accounts
    free(john_doe_account);
    free(jane_doe_account);

    return 0;
}