//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACCOUNTS 100
#define MAX_DEPOSIT 10000

// Structure to store account information
typedef struct {
    int account_no;
    char name[20];
    double balance;
    double interest_rate;
} account_t;

// Function to create a new account
account_t* create_account(int account_no, char name[20], double balance, double interest_rate) {
    account_t* new_account = (account_t*)malloc(sizeof(account_t));
    new_account->account_no = account_no;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    new_account->interest_rate = interest_rate;
    return new_account;
}

// Function to deposit money into an account
void deposit_money(account_t* account, double amount) {
    account->balance += amount;
    printf("Account %d: Deposited %g\n", account->account_no, amount);
}

// Function to withdraw money from an account
void withdraw_money(account_t* account, double amount) {
    if (amount > account->balance) {
        printf("Insufficient funds in account %d\n", account->account_no);
        return;
    }
    account->balance -= amount;
    printf("Account %d: Withdrawn %g\n", account->account_no, amount);
}

// Function to calculate interest on an account
void calculate_interest(account_t* account) {
    account->balance += (account->balance * account->interest_rate) / 100;
    printf("Account %d: Interest calculated at %g\n", account->account_no, account->balance);
}

// Main function
int main() {
    account_t* accounts[MAX_ACCOUNTS];
    int i;

    // Create some sample accounts
    accounts[0] = create_account(1, "John Doe", 1000, 5);
    accounts[1] = create_account(2, "Jane Smith", 5000, 3);
    accounts[2] = create_account(3, "Bob Brown", 2000, 2);

    // Deposit some money into the accounts
    deposit_money(accounts[0], 500);
    deposit_money(accounts[1], 3000);
    deposit_money(accounts[2], 1000);

    // Withdraw some money from the accounts
    withdraw_money(accounts[0], 200);
    withdraw_money(accounts[1], 1500);
    withdraw_money(accounts[2], 500);

    // Calculate interest on the accounts
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        calculate_interest(accounts[i]);
    }

    return 0;
}