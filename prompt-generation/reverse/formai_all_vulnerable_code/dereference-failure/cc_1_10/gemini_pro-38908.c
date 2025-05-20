//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of customers and accounts
#define MAX_CUSTOMERS 100
#define MAX_ACCOUNTS 10

// Define the customer structure
typedef struct {
    int account_number;
    char name[50];
    double balance;
} customer;

// Define the account structure
typedef struct {
    int account_number;
    double balance;
} account;

// Define the banking system structure
typedef struct {
    customer customers[MAX_CUSTOMERS];
    account accounts[MAX_ACCOUNTS];
    int num_customers;
    int num_accounts;
} banking_system;

// Create a new banking system
banking_system* create_banking_system() {
    banking_system* bs = malloc(sizeof(banking_system));
    bs->num_customers = 0;
    bs->num_accounts = 0;
    return bs;
}

// Add a new customer to the banking system
void add_customer(banking_system* bs, customer* c) {
    bs->customers[bs->num_customers] = *c;
    bs->num_customers++;
}

// Add a new account to the banking system
void add_account(banking_system* bs, account* a) {
    bs->accounts[bs->num_accounts] = *a;
    bs->num_accounts++;
}

// Find a customer by their account number
customer* find_customer_by_account_number(banking_system* bs, int account_number) {
    for (int i = 0; i < bs->num_customers; i++) {
        if (bs->customers[i].account_number == account_number) {
            return &bs->customers[i];
        }
    }
    return NULL;
}

// Find an account by its account number
account* find_account_by_account_number(banking_system* bs, int account_number) {
    for (int i = 0; i < bs->num_accounts; i++) {
        if (bs->accounts[i].account_number == account_number) {
            return &bs->accounts[i];
        }
    }
    return NULL;
}

// Deposit money into an account
void deposit_money(banking_system* bs, int account_number, double amount) {
    account* a = find_account_by_account_number(bs, account_number);
    if (a != NULL) {
        a->balance += amount;
    }
}

// Withdraw money from an account
void withdraw_money(banking_system* bs, int account_number, double amount) {
    account* a = find_account_by_account_number(bs, account_number);
    if (a != NULL) {
        if (a->balance >= amount) {
            a->balance -= amount;
        }
    }
}

// Transfer money between two accounts
void transfer_money(banking_system* bs, int from_account_number, int to_account_number, double amount) {
    account* from_account = find_account_by_account_number(bs, from_account_number);
    account* to_account = find_account_by_account_number(bs, to_account_number);
    if (from_account != NULL && to_account != NULL) {
        if (from_account->balance >= amount) {
            from_account->balance -= amount;
            to_account->balance += amount;
        }
    }
}

// Print the details of all customers
void print_all_customers(banking_system* bs) {
    for (int i = 0; i < bs->num_customers; i++) {
        printf("Customer %d:\n", i + 1);
        printf("    Account number: %d\n", bs->customers[i].account_number);
        printf("    Name: %s\n", bs->customers[i].name);
        printf("    Balance: %f\n", bs->customers[i].balance);
    }
}

// Print the details of all accounts
void print_all_accounts(banking_system* bs) {
    for (int i = 0; i < bs->num_accounts; i++) {
        printf("Account %d:\n", i + 1);
        printf("    Account number: %d\n", bs->accounts[i].account_number);
        printf("    Balance: %f\n", bs->accounts[i].balance);
    }
}

// Main function
int main() {
    // Create a new banking system
    banking_system* bs = create_banking_system();

    // Add some customers to the banking system
    customer c1 = {12345, "John Doe", 1000.00};
    add_customer(bs, &c1);
    customer c2 = {23456, "Jane Doe", 2000.00};
    add_customer(bs, &c2);

    // Add some accounts to the banking system
    account a1 = {12345, 1000.00};
    add_account(bs, &a1);
    account a2 = {23456, 2000.00};
    add_account(bs, &a2);

    // Deposit some money into an account
    deposit_money(bs, 12345, 500.00);

    // Withdraw some money from an account
    withdraw_money(bs, 23456, 100.00);

    // Transfer some money between two accounts
    transfer_money(bs, 12345, 23456, 200.00);

    // Print the details of all customers
    print_all_customers(bs);

    // Print the details of all accounts
    print_all_accounts(bs);

    return 0;
}