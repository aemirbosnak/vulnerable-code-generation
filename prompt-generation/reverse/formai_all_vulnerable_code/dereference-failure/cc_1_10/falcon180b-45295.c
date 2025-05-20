//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a bank account
typedef struct {
    char name[50];
    char account_number[20];
    float balance;
} BankAccount;

// Function to create a new bank account
BankAccount* create_account(char* name, char* account_number) {
    BankAccount* new_account = (BankAccount*) malloc(sizeof(BankAccount));
    strcpy(new_account->name, name);
    strcpy(new_account->account_number, account_number);
    new_account->balance = 0.0;
    return new_account;
}

// Function to deposit money into an account
void deposit(BankAccount* account, float amount) {
    account->balance += amount;
    printf("Deposit of %.2f made to account %s (%s). New balance: %.2f\n", amount, account->name, account->account_number, account->balance);
}

// Function to withdraw money from an account
void withdraw(BankAccount* account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal of %.2f made from account %s (%s). New balance: %.2f\n", amount, account->name, account->account_number, account->balance);
    } else {
        printf("Insufficient funds in account %s (%s)\n", account->name, account->account_number);
    }
}

// Function to print account details
void print_account(BankAccount* account) {
    printf("Account Holder Name: %s\n", account->name);
    printf("Account Number: %s\n", account->account_number);
    printf("Current Balance: %.2f\n", account->balance);
}

// Main function to simulate banking operations
int main() {
    BankAccount* account1 = create_account("John Doe", "123456789");
    BankAccount* account2 = create_account("Jane Smith", "987654321");

    deposit(account1, 1000.00);
    deposit(account2, 2000.00);

    print_account(account1);
    print_account(account2);

    withdraw(account1, 500.00);
    withdraw(account2, 1500.00);

    print_account(account1);
    print_account(account2);

    return 0;
}