//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Customer structure
typedef struct customer {
    char name[50];
    char address[100];
    char phone[20];
    int age;
    double balance;
} customer_t;

// Account structure
typedef struct account {
    int account_number;
    char account_type[20];
    double balance;
    customer_t customer;
} account_t;

// Function to create a new customer
customer_t* create_customer(char* name, char* address, char* phone, int age, double balance) {
    customer_t* customer = (customer_t*)malloc(sizeof(customer_t));
    strcpy(customer->name, name);
    strcpy(customer->address, address);
    strcpy(customer->phone, phone);
    customer->age = age;
    customer->balance = balance;
    return customer;
}

// Function to create a new account
account_t* create_account(int account_number, char* account_type, double balance, customer_t* customer) {
    account_t* account = (account_t*)malloc(sizeof(account_t));
    account->account_number = account_number;
    strcpy(account->account_type, account_type);
    account->balance = balance;
    account->customer = *customer;
    return account;
}

// Function to deposit money into an account
void deposit_money(account_t* account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(account_t* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to transfer money from one account to another
void transfer_money(account_t* from_account, account_t* to_account, double amount) {
    if (amount <= from_account->balance) {
        from_account->balance -= amount;
        to_account->balance += amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to print the customer details
void print_customer_details(customer_t* customer) {
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Phone: %s\n", customer->phone);
    printf("Age: %d\n", customer->age);
    printf("Balance: %.2f\n", customer->balance);
}

// Function to print the account details
void print_account_details(account_t* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Account Type: %s\n", account->account_type);
    printf("Balance: %.2f\n", account->balance);
    print_customer_details(&account->customer);
}

// Main function
int main() {
    // Create a new customer
    customer_t* customer = create_customer("John Doe", "123 Main Street", "123-456-7890", 30, 1000.00);

    // Create a new account
    account_t* account = create_account(1234567890, "Savings", 500.00, customer);

    // Deposit money into the account
    deposit_money(account, 200.00);

    // Withdraw money from the account
    withdraw_money(account, 100.00);

    // Transfer money to another account
    transfer_money(account, account, 100.00);

    // Print the customer details
    print_customer_details(customer);

    // Print the account details
    print_account_details(account);

    return 0;
}