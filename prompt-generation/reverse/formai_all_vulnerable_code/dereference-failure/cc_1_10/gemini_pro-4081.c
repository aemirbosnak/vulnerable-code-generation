//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a bank account
typedef struct {
    char *name;
    int balance;
} account_t;

// Define a function to create a new bank account
account_t *create_account(char *name, int balance) {
    account_t *account = malloc(sizeof(account_t));
    account->name = name;
    account->balance = balance;
    return account;
}

// Define a function to deposit money into a bank account
void deposit(account_t *account, int amount) {
    account->balance += amount;
}

// Define a function to withdraw money from a bank account
void withdraw(account_t *account, int amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Define a function to print the balance of a bank account
void print_balance(account_t *account) {
    printf("%s's balance: %d\n", account->name, account->balance);
}

// Define a function to transfer money from one bank account to another
void transfer(account_t *from, account_t *to, int amount) {
    if (amount <= from->balance) {
        from->balance -= amount;
        to->balance += amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Main function
int main() {
    // Create two bank accounts
    account_t *account1 = create_account("Alice", 100);
    account_t *account2 = create_account("Bob", 200);

    // Deposit money into account1
    deposit(account1, 50);

    // Withdraw money from account2
    withdraw(account2, 100);

    // Print the balances of both accounts
    print_balance(account1);
    print_balance(account2);

    // Transfer money from account1 to account2
    transfer(account1, account2, 25);

    // Print the balances of both accounts
    print_balance(account1);
    print_balance(account2);

    // Free the memory allocated for the bank accounts
    free(account1);
    free(account2);

    return 0;
}