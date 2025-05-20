//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
    int account_number;
    char *name;
    double balance;
} account_t;

// Create an array of accounts
account_t accounts[MAX_ACCOUNTS];

// Initialize the number of accounts to 0
int num_accounts = 0;

// Function to create a new account
account_t* create_account(int account_number, char *name, double balance) {
    // Check if the array of accounts is full
    if (num_accounts == MAX_ACCOUNTS) {
        return NULL;
    }

    // Allocate memory for the new account
    account_t *account = malloc(sizeof(account_t));

    // Set the account's properties
    account->account_number = account_number;
    account->name = strdup(name);
    account->balance = balance;

    // Increment the number of accounts
    num_accounts++;

    // Return the new account
    return account;
}

// Function to deposit money into an account
void deposit_money(account_t *account, double amount) {
    // Add the amount to the account's balance
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(account_t *account, double amount) {
    // Check if the withdrawal amount is greater than the account's balance
    if (amount > account->balance) {
        return;
    }

    // Subtract the amount from the account's balance
    account->balance -= amount;
}

// Function to print the details of an account
void print_account(account_t *account) {
    // Print the account's properties
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %f\n", account->balance);
}

// Function to find an account by account number
account_t* find_account_by_account_number(int account_number) {
    // Iterate over the array of accounts
    for (int i = 0; i < num_accounts; i++) {
        // Check if the account's account number matches the given account number
        if (accounts[i].account_number == account_number) {
            // Return the account
            return &accounts[i];
        }
    }

    // Return NULL if the account was not found
    return NULL;
}

// Function to find an account by name
account_t* find_account_by_name(char *name) {
    // Iterate over the array of accounts
    for (int i = 0; i < num_accounts; i++) {
        // Check if the account's name matches the given name
        if (strcmp(accounts[i].name, name) == 0) {
            // Return the account
            return &accounts[i];
        }
    }

    // Return NULL if the account was not found
    return NULL;
}

// Function to delete an account
void delete_account(account_t *account) {
    // Iterate over the array of accounts
    for (int i = 0; i < num_accounts; i++) {
        // Check if the account is the same as the given account
        if (&accounts[i] == account) {
            // Remove the account from the array
            for (int j = i; j < num_accounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }

            // Decrement the number of accounts
            num_accounts--;

            // Free the memory allocated for the account
            free(account->name);
            free(account);

            // Return
            return;
        }
    }
}

// Function to print the details of all accounts
void print_all_accounts() {
    // Iterate over the array of accounts
    for (int i = 0; i < num_accounts; i++) {
        // Print the account's details
        print_account(&accounts[i]);
        printf("\n");
    }
}

int main() {
    // Create some accounts
    account_t *account1 = create_account(12345, "John Doe", 1000.0);
    account_t *account2 = create_account(54321, "Jane Doe", 2000.0);
    account_t *account3 = create_account(98765, "John Smith", 3000.0);

    // Deposit money into account1
    deposit_money(account1, 500.0);

    // Withdraw money from account2
    withdraw_money(account2, 300.0);

    // Print the details of account1
    print_account(account1);
    printf("\n");

    // Find account3 by account number
    account_t *account3_by_account_number = find_account_by_account_number(98765);

    // Print the details of account3 by account number
    print_account(account3_by_account_number);
    printf("\n");

    // Find account2 by name
    account_t *account2_by_name = find_account_by_name("Jane Doe");

    // Print the details of account2 by name
    print_account(account2_by_name);
    printf("\n");

    // Delete account1
    delete_account(account1);

    // Print the details of all accounts
    print_all_accounts();

    return 0;
}