//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Account structure
typedef struct Account {
    int account_number;
    char account_holder_name[50];
    double account_balance;
    time_t account_creation_date;
} Account;

// Create a new account
Account* create_account(int account_number, const char* account_holder_name, double account_balance) {
    Account* new_account = (Account*) malloc(sizeof(Account));
    new_account->account_number = account_number;
    strcpy(new_account->account_holder_name, account_holder_name);
    new_account->account_balance = account_balance;
    new_account->account_creation_date = time(NULL);
    return new_account;
}

// Deposit money into an account
void deposit_money(Account* account, double amount) {
    account->account_balance += amount;
}

// Withdraw money from an account
void withdraw_money(Account* account, double amount) {
    if (amount <= account->account_balance) {
        account->account_balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

// Transfer money from one account to another
void transfer_money(Account* from_account, Account* to_account, double amount) {
    if (amount <= from_account->account_balance) {
        from_account->account_balance -= amount;
        to_account->account_balance += amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

// Print the details of an account
void print_account_details(Account* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Account Holder Name: %s\n", account->account_holder_name);
    printf("Account Balance: %.2f\n", account->account_balance);
    printf("Account Creation Date: %s\n", ctime(&account->account_creation_date));
}

// Main function
int main() {
    // Initialize the bank and create some accounts
    Account* bank[100];
    int num_accounts = 0;

    bank[num_accounts++] = create_account(123456, "John Doe", 1000.00);
    bank[num_accounts++] = create_account(654321, "Jane Doe", 2000.00);
    bank[num_accounts++] = create_account(789012, "Bob Smith", 3000.00);

    // Perform some banking operations
    deposit_money(bank[0], 500.00);
    withdraw_money(bank[1], 300.00);
    transfer_money(bank[2], bank[0], 400.00);

    // Print the details of all accounts
    for (int i = 0; i < num_accounts; i++) {
        print_account_details(bank[i]);
        printf("\n");
    }

    // Free the memory allocated for the accounts
    for (int i = 0; i < num_accounts; i++) {
        free(bank[i]);
    }

    return 0;
}