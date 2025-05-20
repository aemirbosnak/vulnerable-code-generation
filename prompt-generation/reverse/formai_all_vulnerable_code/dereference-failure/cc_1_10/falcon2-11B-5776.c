//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for Bank Account
struct Account {
    int id;
    char name[50];
    double balance;
};

// Define a function to create a new account
struct Account* create_account(int id, char* name, double balance) {
    struct Account* new_account = (struct Account*)malloc(sizeof(struct Account));
    new_account->id = id;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    return new_account;
}

// Define a function to display account details
void display_account(struct Account* account) {
    printf("Account ID: %d\n", account->id);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Define a function to deposit money into an account
void deposit(struct Account* account, double amount) {
    account->balance += amount;
}

// Define a function to withdraw money from an account
void withdraw(struct Account* account, double amount) {
    if (account->balance < amount) {
        printf("Insufficient funds.\n");
    } else {
        account->balance -= amount;
    }
}

int main() {
    // Create an account
    struct Account* account = create_account(12345, "John Doe", 1000.00);

    // Display account details
    display_account(account);

    // Deposit money
    deposit(account, 500.00);

    // Display account details after deposit
    display_account(account);

    // Withdraw money
    withdraw(account, 200.00);

    // Display account details after withdrawal
    display_account(account);

    // Free the memory
    free(account);

    return 0;
}