//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define static number of accounts
#define MAX_ACCOUNTS 100

// struct to represent an account
typedef struct {
    int id;
    char name[50];
    double balance;
} Account;

// function to create a new account
Account* create_account(int id, char* name, double balance) {
    Account* account = (Account*) malloc(sizeof(Account));
    account->id = id;
    strcpy(account->name, name);
    account->balance = balance;
    return account;
}

// function to deposit to an account
void deposit(Account* account, double amount) {
    account->balance += amount;
}

// function to withdraw from an account
void withdraw(Account* account, double amount) {
    account->balance -= amount;
}

// function to print an account's details
void print_account(Account* account) {
    printf("Account ID: %d\nName: %s\nBalance: %.2lf\n", account->id, account->name, account->balance);
}

// main program
int main() {
    // seed random number generator
    srand(time(NULL));

    // initialize array of accounts
    Account* accounts[MAX_ACCOUNTS];
    int num_accounts = 0;

    // loop to simulate transactions
    for(int i = 0; i < 10; i++) {
        // randomly choose an account to perform transaction on
        Account* account = accounts[rand() % num_accounts];

        // randomly choose transaction type
        int transaction_type = rand() % 2;

        // perform transaction
        if(transaction_type == 0) { // deposit
            double amount = rand() % 1000;
            deposit(account, amount);
            printf("Transaction: Deposit\nAmount: %.2lf\n", amount);
        } else { // withdraw
            double amount = rand() % 1000;
            withdraw(account, amount);
            printf("Transaction: Withdrawal\nAmount: %.2lf\n", amount);
        }

        // print account details after transaction
        print_account(account);
    }

    // free memory allocated to accounts
    for(int i = 0; i < num_accounts; i++) {
        free(accounts[i]);
    }

    return 0;
}