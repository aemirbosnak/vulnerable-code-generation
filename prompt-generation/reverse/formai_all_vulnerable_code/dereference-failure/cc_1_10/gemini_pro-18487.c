//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: genius
#include <stdio.h>
#include <string.h>

// Structure to store account details
typedef struct account {
    int account_number;
    char name[50];
    double balance;
} account_t;

// Function to create a new account
account_t *create_account(int account_number, char *name, double balance) {
    account_t *new_account = malloc(sizeof(account_t));
    new_account->account_number = account_number;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into an account
void deposit_money(account_t *account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(account_t *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to print account details
void print_account_details(account_t *account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create two accounts
    account_t *account1 = create_account(123456, "John Doe", 1000.0);
    account_t *account2 = create_account(654321, "Jane Doe", 2000.0);

    // Deposit money into account1
    deposit_money(account1, 500.0);

    // Withdraw money from account2
    withdraw_money(account2, 300.0);

    // Print account details
    print_account_details(account1);
    print_account_details(account2);

    // Free the memory allocated to the accounts
    free(account1);
    free(account2);

    return 0;
}