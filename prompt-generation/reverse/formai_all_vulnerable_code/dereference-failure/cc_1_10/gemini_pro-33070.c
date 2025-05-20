//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the account structure
typedef struct account {
    char *name;
    double balance;
} account;

// Create a new account
account *create_account(char *name, double balance) {
    account *new_account = malloc(sizeof(account));
    new_account->name = name;
    new_account->balance = balance;
    return new_account;
}

// Destroy an account
void destroy_account(account *account) {
    free(account->name);
    free(account);
}

// Print an account
void print_account(account *account) {
    printf("%s: $%.2f\n", account->name, account->balance);
}

// Get a random amount of money
double get_random_amount() {
    return (double)rand() / RAND_MAX * 1000.0;
}

// Transfer money between accounts
void transfer_money(account *from_account, account *to_account, double amount) {
    from_account->balance -= amount;
    to_account->balance += amount;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a list of accounts
    account *accounts[] = {
        create_account("Checking", 1000.0),
        create_account("Savings", 2000.0),
        create_account("Investment", 3000.0),
    };

    // Print the initial balances of the accounts
    printf("Initial balances:\n");
    for (int i = 0; i < 3; i++) {
        print_account(accounts[i]);
    }

    // Simulate a series of transactions
    for (int i = 0; i < 10; i++) {
        // Get a random amount of money
        double amount = get_random_amount();

        // Get two random accounts
        int from_index = rand() % 3;
        int to_index = rand() % 3;

        // Transfer the money
        transfer_money(accounts[from_index], accounts[to_index], amount);
    }

    // Print the final balances of the accounts
    printf("\nFinal balances:\n");
    for (int i = 0; i < 3; i++) {
        print_account(accounts[i]);
    }

    // Destroy the accounts
    for (int i = 0; i < 3; i++) {
        destroy_account(accounts[i]);
    }

    return 0;
}