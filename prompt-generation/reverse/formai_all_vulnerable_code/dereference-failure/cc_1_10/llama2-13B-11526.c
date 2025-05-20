//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the structure for a bank account
typedef struct {
    int account_number;
    char account_holder[50];
    double balance;
} account;

// Define a function to create a new bank account
account* create_account(int account_number, char account_holder[50], double balance) {
    account* new_account = (account*) malloc(sizeof(account));
    new_account->account_number = account_number;
    strcpy(new_account->account_holder, account_holder);
    new_account->balance = balance;
    return new_account;
}

// Define a function to deposit money into an account
void deposit(account* account, double amount) {
    account->balance += amount;
}

// Define a function to withdraw money from an account
void withdraw(account* account, double amount) {
    if (amount > account->balance) {
        printf("Insufficient funds\n");
        return;
    }
    account->balance -= amount;
}

// Define a function to check the balance of an account
double get_balance(account* account) {
    return account->balance;
}

// Define a function to close an account
void close_account(account* account) {
    free(account);
}

int main() {
    // Create a new account
    account* account1 = create_account(1234, "John Doe", 1000.00);

    // Deposit money into the account
    deposit(account1, 500.00);

    // Withdraw money from the account
    withdraw(account1, 200.00);

    // Check the balance of the account
    double balance = get_balance(account1);
    printf("Balance: %f\n", balance);

    // Close the account
    close_account(account1);

    return 0;
}