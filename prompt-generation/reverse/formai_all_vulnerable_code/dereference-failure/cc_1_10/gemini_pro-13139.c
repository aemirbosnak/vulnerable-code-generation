//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structures
typedef struct {
    char *name;
    double amount;
    time_t date;
} Transaction;

typedef struct {
    char *name;
    double balance;
    Transaction *transactions;
    int num_transactions;
} Account;

// Function prototypes
Account *create_account(char *name);
void destroy_account(Account *account);
void add_transaction(Account *account, char *name, double amount, time_t date);
void print_account(Account *account);

// Main function
int main() {
    // Create an account
    Account *account = create_account("My Account");

    // Add some transactions
    add_transaction(account, "Salary", 1000.00, time(NULL));
    add_transaction(account, "Rent", -500.00, time(NULL));
    add_transaction(account, "Groceries", -100.00, time(NULL));
    add_transaction(account, "Savings", 200.00, time(NULL));

    // Print the account
    print_account(account);

    // Destroy the account
    destroy_account(account);

    return 0;
}

// Function definitions
Account *create_account(char *name) {
    Account *account = malloc(sizeof(Account));
    account->name = strdup(name);
    account->balance = 0.00;
    account->transactions = NULL;
    account->num_transactions = 0;
    return account;
}

void destroy_account(Account *account) {
    free(account->name);
    for (int i = 0; i < account->num_transactions; i++) {
        free(account->transactions[i].name);
    }
    free(account->transactions);
    free(account);
}

void add_transaction(Account *account, char *name, double amount, time_t date) {
    account->balance += amount;
    account->transactions = realloc(account->transactions, (account->num_transactions + 1) * sizeof(Transaction));
    account->transactions[account->num_transactions].name = strdup(name);
    account->transactions[account->num_transactions].amount = amount;
    account->transactions[account->num_transactions].date = date;
    account->num_transactions++;
}

void print_account(Account *account) {
    printf("Account: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
    printf("Transactions:\n");
    for (int i = 0; i < account->num_transactions; i++) {
        printf(" - %s: %.2f (%s)\n", account->transactions[i].name, account->transactions[i].amount, ctime(&account->transactions[i].date));
    }
}