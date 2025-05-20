//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT_NUMBER 10
#define MAX_TRANSACTION_AMOUNT 1000

// Structure to store account information
typedef struct {
    int account_number;
    double balance;
} account_t;

// Function to create a new account
account_t* create_account(int account_number) {
    account_t* new_account = (account_t*)malloc(sizeof(account_t));
    new_account->account_number = account_number;
    new_account->balance = 0;
    return new_account;
}

// Function to perform a deposit transaction
void deposit(account_t* account, double amount) {
    if (amount > MAX_TRANSACTION_AMOUNT) {
        printf("Error: Invalid transaction amount\n");
        return;
    }

    account->balance += amount;
    printf("Deposit successful. New balance: %f\n", account->balance);
}

// Function to perform a withdrawal transaction
void withdraw(account_t* account, double amount) {
    if (amount > account->balance) {
        printf("Error: Insufficient balance\n");
        return;
    }

    account->balance -= amount;
    printf("Withdrawal successful. New balance: %f\n", account->balance);
}

// Function to perform a transfer transaction
void transfer(account_t* from_account, double amount, account_t* to_account) {
    if (amount > from_account->balance) {
        printf("Error: Insufficient balance in source account\n");
        return;
    }

    from_account->balance -= amount;
    to_account->balance += amount;

    printf("Transfer successful. New balances: %f, %f\n", from_account->balance, to_account->balance);
}

int main() {
    account_t* account1 = create_account(123);
    account_t* account2 = create_account(456);

    deposit(account1, 1000);
    deposit(account2, 500);

    withdraw(account1, 500);
    withdraw(account2, 200);

    transfer(account1, 300, account2);

    printf("Account 1 balance: %f\n", account1->balance);
    printf("Account 2 balance: %f\n", account2->balance);

    return 0;
}