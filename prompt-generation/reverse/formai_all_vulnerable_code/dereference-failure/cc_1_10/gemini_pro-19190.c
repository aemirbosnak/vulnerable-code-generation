//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the bank account structure
typedef struct bank_account {
    char *name;
    int balance;
} bank_account;

// Create a new bank account
bank_account *create_account(char *name, int balance) {
    bank_account *account = malloc(sizeof(bank_account));
    account->name = name;
    account->balance = balance;
    return account;
}

// Deposit money into an account
void deposit(bank_account *account, int amount) {
    account->balance += amount;
}

// Withdraw money from an account
void withdraw(bank_account *account, int amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Print the account balance
void print_balance(bank_account *account) {
    printf("%s has a balance of %d\n", account->name, account->balance);
}

// Main function
int main() {
    // Create a new bank account
    bank_account *account = create_account("Ser Barristan Selmy", 1000);

    // Deposit money into the account
    deposit(account, 500);

    // Withdraw money from the account
    withdraw(account, 300);

    // Print the account balance
    print_balance(account);

    // Free the memory allocated for the account
    free(account);

    return 0;
}