//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CUSTOMERS 100
#define MAX_ACCOUNTS 1000
#define MIN_BALANCE 100
#define MAX_BALANCE 10000

// Structure to store customer information
typedef struct {
    int id;
    char name[50];
    char address[100];
    int account_num;
    double balance;
} customer_t;

// Structure to store account information
typedef struct {
    int account_id;
    char account_name[50];
    double balance;
} account_t;

// Function to create a new customer
customer_t* create_customer(int id, char name[50], char address[100]) {
    customer_t* cust = (customer_t*) malloc(sizeof(customer_t));
    cust->id = id;
    strcpy(cust->name, name);
    strcpy(cust->address, address);
    cust->account_num = 0;
    cust->balance = 0.0;
    return cust;
}

// Function to create a new account
account_t* create_account(int account_id, char account_name[50]) {
    account_t* acc = (account_t*) malloc(sizeof(account_t));
    acc->account_id = account_id;
    strcpy(acc->account_name, account_name);
    acc->balance = 0.0;
    return acc;
}

// Function to deposit money into an account
void deposit_money(customer_t* cust, double amount) {
    if (cust->balance + amount >= MIN_BALANCE && amount >= 0.0) {
        cust->balance += amount;
        printf("Customer %d deposited %f into account %d\n", cust->id, amount, cust->account_num);
    } else {
        printf("Insufficient balance or negative amount\n");
    }
}

// Function to withdraw money from an account
void withdraw_money(customer_t* cust, double amount) {
    if (cust->balance - amount >= 0.0) {
        cust->balance -= amount;
        printf("Customer %d withdrew %f from account %d\n", cust->id, amount, cust->account_num);
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to check if a customer has enough balance for a withdrawal
int check_balance(customer_t* cust, double amount) {
    return (cust->balance >= amount);
}

// Function to get the current balance of an account
double get_balance(account_t* acc) {
    return acc->balance;
}

int main() {
    // Create customers and accounts
    customer_t* cust1 = create_customer(1, "John Doe", "123 Main St");
    customer_t* cust2 = create_customer(2, "Jane Doe", "456 Elm St");
    account_t* acc1 = create_account(1, "Checking");
    account_t* acc2 = create_account(2, "Savings");

    // Deposit money
    deposit_money(cust1, 1000.0);
    deposit_money(cust2, 500.0);

    // Withdraw money
    withdraw_money(cust1, 500.0);
    withdraw_money(cust2, 300.0);

    // Check balance
    if (check_balance(cust1, 100.0)) {
        printf("Customer 1 has enough balance for a withdrawal of $100\n");
    } else {
        printf("Customer 1 does not have enough balance for a withdrawal\n");
    }

    if (check_balance(cust2, 200.0)) {
        printf("Customer 2 has enough balance for a withdrawal of $200\n");
    } else {
        printf("Customer 2 does not have enough balance for a withdrawal\n");
    }

    return 0;
}