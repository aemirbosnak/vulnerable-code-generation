//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct for a bank account
typedef struct bank_account {
    int account_number;
    char name[50];
    double balance;
    int branch_id;
    int account_type;
} bank_account;

// Define a function to create a new bank account
bank_account* create_account() {
    bank_account* new_account = (bank_account*)malloc(sizeof(bank_account));
    srand(time(0));
    new_account->account_number = rand() % 1000000;
    new_account->balance = 0.0;
    new_account->branch_id = 1;
    new_account->account_type = 0;
    return new_account;
}

// Define a function to deposit money into an account
void deposit(bank_account* account, double amount) {
    account->balance += amount;
}

// Define a function to withdraw money from an account
void withdraw(bank_account* account, double amount) {
    account->balance -= amount;
    if (account->balance < 0) {
        printf("Insufficient funds.\n");
    }
}

// Define a function to display the account details
void display_account(bank_account* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
    printf("Branch ID: %d\n", account->branch_id);
    printf("Account Type: %d\n", account->account_type);
}

int main() {
    bank_account* account = create_account();
    printf("Account Details:\n");
    display_account(account);
    printf("\n");

    // Deposit some money
    deposit(account, 1000.0);
    printf("Account Details after deposit:\n");
    display_account(account);
    printf("\n");

    // Withdraw some money
    withdraw(account, 500.0);
    printf("Account Details after withdrawal:\n");
    display_account(account);
    printf("\n");

    return 0;
}