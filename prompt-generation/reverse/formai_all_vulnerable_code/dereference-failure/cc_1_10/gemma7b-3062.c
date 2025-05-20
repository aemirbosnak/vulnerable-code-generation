//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <string.h>

// Define a structure to store bank account information
typedef struct BankAccount {
    char name[50];
    int account_no;
    double balance;
} BankAccount;

// Function to create a new bank account
BankAccount* create_account(char* name, int account_no, double balance) {
    BankAccount* new_account = malloc(sizeof(BankAccount));
    strcpy(new_account->name, name);
    new_account->account_no = account_no;
    new_account->balance = balance;

    return new_account;
}

// Function to deposit money into a bank account
void deposit(BankAccount* account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from a bank account
void withdraw(BankAccount* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

// Function to transfer money between accounts
void transfer(BankAccount* from_account, BankAccount* to_account, double amount) {
    if (amount <= from_account->balance) {
        from_account->balance -= amount;
        to_account->balance += amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

int main() {
    // Create a new bank account
    BankAccount* my_account = create_account("John Doe", 123456, 1000.0);

    // Deposit money into the account
    deposit(my_account, 500.0);

    // Withdraw money from the account
    withdraw(my_account, 200.0);

    // Transfer money between accounts
    transfer(my_account, create_account("Jane Doe", 654321, 2000.0), 200.0);

    // Print the account balance
    printf("Your current balance: $%.2lf\n", my_account->balance);

    return 0;
}