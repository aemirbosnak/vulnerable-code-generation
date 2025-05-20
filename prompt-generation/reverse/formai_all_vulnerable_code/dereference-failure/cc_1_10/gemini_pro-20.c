//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer {
    char *name;
    int account_number;
    double balance;
} Customer;

typedef struct Bank {
    Customer *customers;
    int num_customers;
} Bank;

Bank *create_bank() {
    Bank *bank = malloc(sizeof(Bank));
    bank->customers = NULL;
    bank->num_customers = 0;
    return bank;
}

void destroy_bank(Bank *bank) {
    for (int i = 0; i < bank->num_customers; i++) {
        free(bank->customers[i].name);
    }
    free(bank->customers);
    free(bank);
}

Customer *create_customer(char *name, int account_number, double balance) {
    Customer *customer = malloc(sizeof(Customer));
    customer->name = strdup(name);
    customer->account_number = account_number;
    customer->balance = balance;
    return customer;
}

void destroy_customer(Customer *customer) {
    free(customer->name);
    free(customer);
}

void add_customer(Bank *bank, Customer *customer) {
    bank->customers = realloc(bank->customers, (bank->num_customers + 1) * sizeof(Customer));
    bank->customers[bank->num_customers++] = *customer;
}

Customer *find_customer(Bank *bank, int account_number) {
    for (int i = 0; i < bank->num_customers; i++) {
        if (bank->customers[i].account_number == account_number) {
            return &bank->customers[i];
        }
    }
    return NULL;
}

void deposit(Customer *customer, double amount) {
    customer->balance += amount;
}

void withdraw(Customer *customer, double amount) {
    if (amount <= customer->balance) {
        customer->balance -= amount;
    }
}

void transfer(Bank *bank, int from_account_number, int to_account_number, double amount) {
    Customer *from_customer = find_customer(bank, from_account_number);
    Customer *to_customer = find_customer(bank, to_account_number);
    if (from_customer && to_customer) {
        withdraw(from_customer, amount);
        deposit(to_customer, amount);
    }
}

void print_customer(Customer *customer) {
    printf("Name: %s\n", customer->name);
    printf("Account number: %d\n", customer->account_number);
    printf("Balance: %.2f\n", customer->balance);
}

void print_bank(Bank *bank) {
    for (int i = 0; i < bank->num_customers; i++) {
        print_customer(&bank->customers[i]);
        printf("\n");
    }
}

int main() {
    Bank *bank = create_bank();

    Customer *customer1 = create_customer("John Doe", 123456789, 1000.00);
    add_customer(bank, customer1);

    Customer *customer2 = create_customer("Jane Doe", 987654321, 2000.00);
    add_customer(bank, customer2);

    deposit(customer1, 500.00);
    withdraw(customer2, 300.00);

    transfer(bank, 123456789, 987654321, 200.00);

    print_bank(bank);

    destroy_customer(customer1);
    destroy_customer(customer2);
    destroy_bank(bank);

    return 0;
}