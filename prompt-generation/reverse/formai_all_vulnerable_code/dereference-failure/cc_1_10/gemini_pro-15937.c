//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account details
typedef struct account {
    char name[50];
    char account_number[20];
    double balance;
} account_t;

// Function to create a new account
account_t* create_account(char* name, char* account_number, double balance) {
    account_t* new_account = (account_t*)malloc(sizeof(account_t));
    strcpy(new_account->name, name);
    strcpy(new_account->account_number, account_number);
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into an account
void deposit_money(account_t* account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(account_t* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds in account.\n");
    }
}

// Function to print the account details
void print_account_details(account_t* account) {
    printf("Account holder: %s\n", account->name);
    printf("Account number: %s\n", account->account_number);
    printf("Account balance: %.2f\n", account->balance);
}

int main() {
    // Create two accounts
    account_t* account1 = create_account("Romeo Montague", "1234567890", 1000.00);
    account_t* account2 = create_account("Juliet Capulet", "0987654321", 500.00);

    // Deposit money into Romeo's account
    deposit_money(account1, 200.00);

    // Withdraw money from Juliet's account
    withdraw_money(account2, 100.00);

    // Print the account details
    print_account_details(account1);
    printf("\n");
    print_account_details(account2);

    // Free the allocated memory
    free(account1);
    free(account2);

    return 0;
}