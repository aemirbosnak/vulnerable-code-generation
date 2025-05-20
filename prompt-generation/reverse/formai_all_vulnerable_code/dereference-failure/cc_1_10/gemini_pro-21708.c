//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of customers
#define MAX_CUSTOMERS 100

// Define the maximum number of transactions per customer
#define MAX_TRANSACTIONS 100

// Define the maximum length of a customer's name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a transaction description
#define MAX_DESCRIPTION_LENGTH 100

// Define the data structure for a customer
typedef struct customer {
    char name[MAX_NAME_LENGTH];
    int account_number;
    double balance;
    struct transaction *transactions;
} customer;

// Define the data structure for a transaction
typedef struct transaction {
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
    struct transaction *next;
} transaction;

// Define the global array of customers
customer customers[MAX_CUSTOMERS];

// Define the global variable to keep track of the number of customers
int num_customers = 0;

// Function to create a new customer
void create_customer(char *name, int account_number, double balance) {
    // Check if the maximum number of customers has been reached
    if (num_customers >= MAX_CUSTOMERS) {
        printf("Error: Maximum number of customers reached.\n");
        return;
    }

    // Create a new customer
    customer new_customer;
    strcpy(new_customer.name, name);
    new_customer.account_number = account_number;
    new_customer.balance = balance;
    new_customer.transactions = NULL;

    // Add the new customer to the global array of customers
    customers[num_customers] = new_customer;

    // Increment the number of customers
    num_customers++;
}

// Function to deposit money into a customer's account
void deposit(int account_number, double amount) {
    // Find the customer by their account number
    int i;
    for (i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            break;
        }
    }

    // Check if the customer was found
    if (i == num_customers) {
        printf("Error: Customer not found.\n");
        return;
    }

    // Deposit the money into the customer's account
    customers[i].balance += amount;

    // Create a new transaction
    transaction new_transaction;
    strcpy(new_transaction.description, "Deposit");
    new_transaction.amount = amount;
    new_transaction.next = NULL;

    // Add the new transaction to the customer's list of transactions
    if (customers[i].transactions == NULL) {
        customers[i].transactions = &new_transaction;
    } else {
        transaction *current = customers[i].transactions;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = &new_transaction;
    }
}

// Function to withdraw money from a customer's account
void withdraw(int account_number, double amount) {
    // Find the customer by their account number
    int i;
    for (i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            break;
        }
    }

    // Check if the customer was found
    if (i == num_customers) {
        printf("Error: Customer not found.\n");
        return;
    }

    // Check if the customer has enough money in their account
    if (customers[i].balance < amount) {
        printf("Error: Insufficient funds.\n");
        return;
    }

    // Withdraw the money from the customer's account
    customers[i].balance -= amount;

    // Create a new transaction
    transaction new_transaction;
    strcpy(new_transaction.description, "Withdraw");
    new_transaction.amount = amount;
    new_transaction.next = NULL;

    // Add the new transaction to the customer's list of transactions
    if (customers[i].transactions == NULL) {
        customers[i].transactions = &new_transaction;
    } else {
        transaction *current = customers[i].transactions;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = &new_transaction;
    }
}

// Function to print the balance of a customer's account
void print_balance(int account_number) {
    // Find the customer by their account number
    int i;
    for (i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            break;
        }
    }

    // Check if the customer was found
    if (i == num_customers) {
        printf("Error: Customer not found.\n");
        return;
    }

    // Print the customer's balance
    printf("Balance: %f\n", customers[i].balance);
}

// Function to print the list of transactions for a customer
void print_transactions(int account_number) {
    // Find the customer by their account number
    int i;
    for (i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            break;
        }
    }

    // Check if the customer was found
    if (i == num_customers) {
        printf("Error: Customer not found.\n");
        return;
    }

    // Print the customer's list of transactions
    transaction *current = customers[i].transactions;
    while (current != NULL) {
        printf("%s: %f\n", current->description, current->amount);
        current = current->next;
    }
}

// Main function
int main() {
    // Create some customers
    create_customer("John Doe", 123456789, 1000.00);
    create_customer("Jane Doe", 987654321, 2000.00);
    create_customer("Bob Smith", 111222333, 3000.00);

    // Deposit some money into a customer's account
    deposit(123456789, 500.00);

    // Withdraw some money from a customer's account
    withdraw(987654321, 100.00);

    // Print the balance of a customer's account
    print_balance(111222333);

    // Print the list of transactions for a customer
    print_transactions(123456789);

    return 0;
}