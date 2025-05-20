//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of customers and accounts
#define MAX_CUSTOMERS 100
#define MAX_ACCOUNTS 10

// Define the customer and account structures
typedef struct {
    char name[50];
    int age;
    char address[100];
    char phone[20];
} customer;

typedef struct {
    int account_number;
    double balance;
    customer *owner;
} account;

// Define the bank structure
typedef struct {
    customer customers[MAX_CUSTOMERS];
    account accounts[MAX_ACCOUNTS];
    int num_customers;
    int num_accounts;
} bank;

// Create a new bank
bank *create_bank() {
    bank *new_bank = malloc(sizeof(bank));
    new_bank->num_customers = 0;
    new_bank->num_accounts = 0;
    return new_bank;
}

// Add a new customer to the bank
void add_customer(bank *bank, customer *new_customer) {
    bank->customers[bank->num_customers] = *new_customer;
    bank->num_customers++;
}

// Add a new account to the bank
void add_account(bank *bank, account *new_account) {
    bank->accounts[bank->num_accounts] = *new_account;
    bank->num_accounts++;
}

// Find a customer by their name
customer *find_customer_by_name(bank *bank, char *name) {
    for (int i = 0; i < bank->num_customers; i++) {
        if (strcmp(bank->customers[i].name, name) == 0) {
            return &bank->customers[i];
        }
    }
    return NULL;
}

// Find an account by its account number
account *find_account_by_number(bank *bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }
    return NULL;
}

// Deposit money into an account
void deposit_money(account *account, double amount) {
    account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Transfer money between accounts
void transfer_money(account *from_account, account *to_account, double amount) {
    if (amount <= from_account->balance) {
        from_account->balance -= amount;
        to_account->balance += amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Print the details of a customer
void print_customer(customer *customer) {
    printf("Name: %s\n", customer->name);
    printf("Age: %d\n", customer->age);
    printf("Address: %s\n", customer->address);
    printf("Phone: %s\n", customer->phone);
}

// Print the details of an account
void print_account(account *account) {
    printf("Account number: %d\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
    printf("Owner: %s\n", account->owner->name);
}

// Print the details of a bank
void print_bank(bank *bank) {
    printf("Customers:\n");
    for (int i = 0; i < bank->num_customers; i++) {
        print_customer(&bank->customers[i]);
        printf("\n");
    }
    printf("Accounts:\n");
    for (int i = 0; i < bank->num_accounts; i++) {
        print_account(&bank->accounts[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new bank
    bank *bank = create_bank();

    // Add some customers to the bank
    customer customer1 = {"John Doe", 30, "123 Main Street", "555-1212"};
    add_customer(bank, &customer1);
    customer customer2 = {"Jane Doe", 25, "456 Elm Street", "555-1213"};
    add_customer(bank, &customer2);

    // Add some accounts to the bank
    account account1 = {123456, 1000.00, &customer1};
    add_account(bank, &account1);
    account account2 = {654321, 2000.00, &customer2};
    add_account(bank, &account2);

    // Deposit money into an account
    deposit_money(&account1, 500.00);

    // Withdraw money from an account
    withdraw_money(&account2, 1000.00);

    // Transfer money between accounts
    transfer_money(&account1, &account2, 500.00);

    // Print the details of the bank
    print_bank(bank);

    return 0;
}