//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the account structure
struct account {
    int account_number;
    char *name;
    double balance;
};

// Function to create a new account
struct account *create_account(int account_number, char *name, double balance) {
    // Allocate memory for the account
    struct account *account = malloc(sizeof(struct account));

    // Set the account's properties
    account->account_number = account_number;
    account->name = name;
    account->balance = balance;

    // Return the account
    return account;
}

// Function to deposit money into an account
void deposit(struct account *account, double amount) {
    // Add the amount to the account's balance
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(struct account *account, double amount) {
    // Check if the amount is greater than the account's balance
    if (amount > account->balance) {
        printf("Insufficient funds\n");
    } else {
        // Subtract the amount from the account's balance
        account->balance -= amount;
    }
}

// Function to print the account's details
void print_account(struct account *account) {
    // Print the account's properties
    printf("Account number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
}

// Main function
int main() {
    // Create a new account
    struct account *account = create_account(12345, "John Doe", 1000.00);

    // Deposit money into the account
    deposit(account, 500.00);

    // Withdraw money from the account
    withdraw(account, 300.00);

    // Print the account's details
    print_account(account);

    // Free the memory allocated for the account
    free(account);

    return 0;
}