//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define the customer struct
typedef struct customer {
  int account_number;
  char *name;
  double balance;
} customer;

// Define the bank struct
typedef struct bank {
  int num_customers;
  customer *customers;
} bank;

// Create a new bank
bank *create_bank() {
  bank *b = malloc(sizeof(bank));
  b->num_customers = 0;
  b->customers = NULL;
  return b;
}

// Add a new customer to the bank
void add_customer(bank *b, int account_number, char *name, double balance) {
  b->num_customers++;
  b->customers = realloc(b->customers, b->num_customers * sizeof(customer));
  customer *c = &b->customers[b->num_customers - 1];
  c->account_number = account_number;
  c->name = name;
  c->balance = balance;
}

// Get a customer by their account number
customer *get_customer(bank *b, int account_number) {
  for (int i = 0; i < b->num_customers; i++) {
    if (b->customers[i].account_number == account_number) {
      return &b->customers[i];
    }
  }
  return NULL;
}

// Deposit money into a customer's account
void deposit(bank *b, int account_number, double amount) {
  customer *c = get_customer(b, account_number);
  if (c != NULL) {
    c->balance += amount;
  }
}

// Withdraw money from a customer's account
void withdraw(bank *b, int account_number, double amount) {
  customer *c = get_customer(b, account_number);
  if (c != NULL) {
    if (c->balance >= amount) {
      c->balance -= amount;
    }
  }
}

// Print the details of all customers in the bank
void print_customers(bank *b) {
  for (int i = 0; i < b->num_customers; i++) {
    printf("Customer %d:\n", i + 1);
    printf("Account number: %d\n", b->customers[i].account_number);
    printf("Name: %s\n", b->customers[i].name);
    printf("Balance: %.2f\n\n", b->customers[i].balance);
  }
}

// Destroy the bank
void destroy_bank(bank *b) {
  for (int i = 0; i < b->num_customers; i++) {
    free(b->customers[i].name);
  }
  free(b->customers);
  free(b);
}

int main() {
  // Create a new bank
  bank *b = create_bank();

  // Add some customers to the bank
  add_customer(b, 12345, "John Smith", 1000);
  add_customer(b, 67890, "Jane Doe", 2000);
  add_customer(b, 112233, "Bill Jones", 3000);

  // Deposit some money into John Smith's account
  deposit(b, 12345, 500);

  // Withdraw some money from Jane Doe's account
  withdraw(b, 67890, 300);

  // Print the details of all customers in the bank
  print_customers(b);

  // Destroy the bank
  destroy_bank(b);

  return 0;
}