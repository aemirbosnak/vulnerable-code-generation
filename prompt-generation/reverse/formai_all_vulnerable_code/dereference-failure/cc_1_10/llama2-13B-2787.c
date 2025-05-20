//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to store customer information
struct customer {
    int account_number;
    int balance;
};

// Function to create a new customer
struct customer *new_customer(int account_number, int balance) {
    struct customer *customer = malloc(sizeof(struct customer));
    customer->account_number = account_number;
    customer->balance = balance;
    return customer;
}

// Function to deposit money into a customer's account
void deposit(struct customer *customer, int amount) {
    customer->balance += amount;
}

// Function to withdraw money from a customer's account
void withdraw(struct customer *customer, int amount) {
    if (customer->balance >= amount) {
        customer->balance -= amount;
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to display the balance of a customer's account
void display_balance(struct customer *customer) {
    printf("Account balance: %d\n", customer->balance);
}

// Function to simulate a banking transaction
void transaction(struct customer *customer, int amount) {
    if (amount > 0) {
        deposit(customer, amount);
    } else {
        withdraw(customer, amount);
    }
    display_balance(customer);
}

// Recursive function to simulate a banking transaction
void recursive_transaction(struct customer *customer, int amount) {
    if (amount > 0) {
        recursive_transaction(customer, amount / 2); // Half the amount for the next transaction
        deposit(customer, amount);
    } else {
        withdraw(customer, amount);
        recursive_transaction(customer, amount); // Repeat the transaction with the remaining amount
    }
}

int main() {
    struct customer *customer1 = new_customer(101, 1000); // Create a new customer with account number 101 and initial balance of 1000
    struct customer *customer2 = new_customer(102, 500); // Create a new customer with account number 102 and initial balance of 500

    // Simulate a series of transactions
    recursive_transaction(customer1, 2000); // Deposit 2000 into customer1's account
    recursive_transaction(customer2, 1500); // Deposit 1500 into customer2's account
    recursive_transaction(customer1, 1000); // Withdraw 1000 from customer1's account
    recursive_transaction(customer2, 500); // Withdraw 500 from customer2's account

    // Display the final balances of the customers
    display_balance(customer1);
    display_balance(customer2);

    return 0;
}