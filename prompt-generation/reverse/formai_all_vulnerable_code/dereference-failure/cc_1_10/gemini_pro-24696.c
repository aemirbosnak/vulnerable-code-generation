//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Sherlock's banking record system

typedef struct _account {
    int account_number;
    char *name;
    double balance;
} account;

// The great detective's casebook
account *accounts;
int num_accounts;

// Initialize the system
void init_system() {
    accounts = malloc(sizeof(account) * 100);
    num_accounts = 0;
}

// Add a new account
void add_account(int account_number, char *name, double balance) {
    accounts[num_accounts].account_number = account_number;
    accounts[num_accounts].name = name;
    accounts[num_accounts].balance = balance;
    num_accounts++;
}

// Deposit money into an account
void deposit(int account_number, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            break;
        }
    }
}

// Withdraw money from an account
void withdraw(int account_number, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
            } else {
                printf("Insufficient funds in account %d\n", account_number);
            }
            break;
        }
    }
}

// Print the balance of an account
void print_balance(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Account %d: £%.2f\n", account_number, accounts[i].balance);
            break;
        }
    }
}

// The main investigation
int main() {
    // Initialize the system
    init_system();

    // Add some accounts
    add_account(123456, "Sherlock Holmes", 1000.00);
    add_account(654321, "Dr. Watson", 500.00);
    add_account(789456, "Irene Adler", 2000.00);

    // Deposit some money
    deposit(123456, 100.00);
    deposit(654321, 50.00);

    // Withdraw some money
    withdraw(123456, 50.00);
    withdraw(654321, 100.00);

    // Print the balances
    print_balance(123456);
    print_balance(654321);
    print_balance(789456);

    return 0;
}