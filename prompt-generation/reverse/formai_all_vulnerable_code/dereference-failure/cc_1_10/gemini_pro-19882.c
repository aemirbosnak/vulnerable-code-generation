//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the account structure
typedef struct {
    int account_number;
    char *name;
    double balance;
} account_t;

// Create a new account
account_t *create_account(int account_number, char *name, double balance) {
    account_t *account = malloc(sizeof(account_t));
    account->account_number = account_number;
    account->name = name;
    account->balance = balance;
    return account;
}

// Destroy an account
void destroy_account(account_t *account) {
    free(account->name);
    free(account);
}

// Deposit money into an account
void deposit_money(account_t *account, double amount) {
    account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(account_t *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    }
}

// Transfer money from one account to another
void transfer_money(account_t *from_account, account_t *to_account, double amount) {
    if (amount <= from_account->balance) {
        from_account->balance -= amount;
        to_account->balance += amount;
    }
}

// Print the account information
void print_account(account_t *account) {
    printf("Account number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create two accounts
    account_t *account1 = create_account(123456, "Alice", 1000.00);
    account_t *account2 = create_account(654321, "Bob", 2000.00);

    // Deposit money into account1
    deposit_money(account1, 500.00);

    // Withdraw money from account2
    withdraw_money(account2, 300.00);

    // Transfer money from account1 to account2
    transfer_money(account1, account2, 200.00);

    // Print the account information
    print_account(account1);
    print_account(account2);

    // Destroy the accounts
    destroy_account(account1);
    destroy_account(account2);

    return 0;
}