//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

/* Define the structure of a bank account */
typedef struct {
    int account_number;
    char name[50];
    double balance;
} BankAccount;

/* Function to create a new bank account */
BankAccount* create_account(int account_number, char* name, double balance) {
    BankAccount* account = (BankAccount*) malloc(sizeof(BankAccount));
    account->account_number = account_number;
    strcpy(account->name, name);
    account->balance = balance;
    return account;
}

/* Function to deposit money into an account */
void deposit(BankAccount* account, double amount) {
    account->balance += amount;
}

/* Function to withdraw money from an account */
int withdraw(BankAccount* account, double amount) {
    if(account->balance >= amount) {
        account->balance -= amount;
        return 0;
    } else {
        printf("Insufficient funds\n");
        return -1;
    }
}

/* Function to print account details */
void print_account(BankAccount* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
}

/* Main function */
int main() {
    /* Create a new account */
    BankAccount* account = create_account(12345, "John Doe", 1000.00);

    /* Print account details */
    print_account(account);

    /* Deposit money into the account */
    deposit(account, 500.00);
    print_account(account);

    /* Withdraw money from the account */
    withdraw(account, 200.00);
    print_account(account);

    /* Attempt to withdraw more money than available */
    withdraw(account, 1500.00);

    return 0;
}