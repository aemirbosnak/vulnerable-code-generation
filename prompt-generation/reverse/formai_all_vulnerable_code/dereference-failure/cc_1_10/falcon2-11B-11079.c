//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: mind-bending
// C Banking Record System example program in a mind-bending style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the account structure
typedef struct account {
    int account_number;
    char name[50];
    double balance;
} account;

// Function to create a new account
account* create_account(int account_number, char name[50], double balance) {
    account* new_account = malloc(sizeof(account));
    if (new_account == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    new_account->account_number = account_number;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into an account
void deposit(account* account, double amount) {
    account->balance += amount;
    printf("Deposited %f\n", amount);
}

// Function to withdraw money from an account
void withdraw(account* account, double amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrew %f\n", amount);
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to display account information
void display_account(account* account) {
    printf("Account number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Function to transfer money between accounts
void transfer(account* from_account, account* to_account, double amount) {
    if (from_account->balance >= amount) {
        from_account->balance -= amount;
        to_account->balance += amount;
        printf("Transferred %f from %d to %d\n", amount, from_account->account_number, to_account->account_number);
    } else {
        printf("Insufficient funds\n");
    }
}

// Main function
int main() {
    account* my_account = create_account(12345, "John Doe", 1000.00);
    display_account(my_account);

    deposit(my_account, 500.00);
    display_account(my_account);

    withdraw(my_account, 200.00);
    display_account(my_account);

    account* other_account = create_account(67890, "Jane Smith", 2000.00);
    display_account(other_account);

    transfer(my_account, other_account, 300.00);
    display_account(my_account);
    display_account(other_account);

    return 0;
}