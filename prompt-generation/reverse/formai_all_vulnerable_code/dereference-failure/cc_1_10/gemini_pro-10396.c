//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Data structures
typedef struct {
    char *name;
    double balance;
} Account;

typedef struct {
    char *description;
    double amount;
} Transaction;

// Function prototypes
void print_accounts(Account accounts[], int num_accounts);
void print_transactions(Transaction transactions[], int num_transactions);
void add_account(Account accounts[], int *num_accounts, char *name, double balance);
void add_transaction(Transaction transactions[], int *num_transactions, char *description, double amount);
void calculate_net_worth(Account accounts[], int num_accounts, double *net_worth);

int main() {
    // Cyberpunk-themed welcome message
    printf("Welcome to the Neon City Personal Finance Planner, runner.\n");

    // Initialize data structures
    Account accounts[10];
    int num_accounts = 0;
    Transaction transactions[100];
    int num_transactions = 0;
    double net_worth = 0.0;

    // Add some sample data
    add_account(accounts, &num_accounts, "CredChip", 1000.0);
    add_account(accounts, &num_accounts, "Eurobucks", 500.0);
    add_transaction(transactions, &num_transactions, "Rent", -500.0);
    add_transaction(transactions, &num_transactions, "Salary", 2000.0);

    // Print the accounts and transactions
    printf("Your accounts:\n");
    print_accounts(accounts, num_accounts);
    printf("\nYour transactions:\n");
    print_transactions(transactions, num_transactions);

    // Calculate the net worth
    calculate_net_worth(accounts, num_accounts, &net_worth);

    // Print the net worth
    printf("\nYour net worth: %0.2f\n", net_worth);

    return 0;
}

// Function definitions
void print_accounts(Account accounts[], int num_accounts) {
    for (int i = 0; i < num_accounts; i++) {
        printf("  - %s: %0.2f\n", accounts[i].name, accounts[i].balance);
    }
}

void print_transactions(Transaction transactions[], int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("  - %s: %0.2f\n", transactions[i].description, transactions[i].amount);
    }
}

void add_account(Account accounts[], int *num_accounts, char *name, double balance) {
    accounts[*num_accounts].name = malloc(strlen(name) + 1);
    strcpy(accounts[*num_accounts].name, name);
    accounts[*num_accounts].balance = balance;
    (*num_accounts)++;
}

void add_transaction(Transaction transactions[], int *num_transactions, char *description, double amount) {
    transactions[*num_transactions].description = malloc(strlen(description) + 1);
    strcpy(transactions[*num_transactions].description, description);
    transactions[*num_transactions].amount = amount;
    (*num_transactions)++;
}

void calculate_net_worth(Account accounts[], int num_accounts, double *net_worth) {
    for (int i = 0; i < num_accounts; i++) {
        *net_worth += accounts[i].balance;
    }
}