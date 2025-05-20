//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char *name;
    double amount;
} Expense;

typedef struct {
    char *name;
    double balance;
    Expense *expenses;
    int num_expenses;
} Account;

// Function prototypes
Account *create_account(char *name, double balance);
void add_expense(Account *account, char *name, double amount);
void print_account(Account *account);
void free_account(Account *account);

// Main function
int main() {
    // Create an account
    Account *account = create_account("My Account", 1000.00);

    // Add some expenses
    add_expense(account, "Rent", 500.00);
    add_expense(account, "Groceries", 200.00);
    add_expense(account, "Entertainment", 100.00);

    // Print the account
    print_account(account);

    // Free the account
    free_account(account);

    return 0;
}

// Function definitions
Account *create_account(char *name, double balance) {
    // Allocate memory for the account
    Account *account = malloc(sizeof(Account));

    // Set the account's name and balance
    account->name = strdup(name);
    account->balance = balance;

    // Initialize the account's expenses
    account->expenses = NULL;
    account->num_expenses = 0;

    // Return the account
    return account;
}

void add_expense(Account *account, char *name, double amount) {
    // Allocate memory for the expense
    Expense *expense = malloc(sizeof(Expense));

    // Set the expense's name and amount
    expense->name = strdup(name);
    expense->amount = amount;

    // Add the expense to the account
    account->expenses = realloc(account->expenses, (account->num_expenses + 1) * sizeof(Expense));
    account->expenses[account->num_expenses] = *expense;
    account->num_expenses++;
}

void print_account(Account *account) {
    // Print the account's name and balance
    printf("Account: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);

    // Print the account's expenses
    for (int i = 0; i < account->num_expenses; i++) {
        printf("Expense: %s\n", account->expenses[i].name);
        printf("Amount: %.2f\n", account->expenses[i].amount);
    }
}

void free_account(Account *account) {
    // Free the account's name
    free(account->name);

    // Free the account's expenses
    for (int i = 0; i < account->num_expenses; i++) {
        free(account->expenses[i].name);
    }
    free(account->expenses);

    // Free the account
    free(account);
}