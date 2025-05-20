//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of customers and accounts
#define MAX_CUSTOMERS 100
#define MAX_ACCOUNTS 10

// Define the account types
enum account_type {
  SAVINGS,
  CHECKING,
  LOAN
};

// Define the customer struct
typedef struct customer {
  char name[50];
  int age;
  int num_accounts;
  struct account *accounts[MAX_ACCOUNTS];
} customer;

// Define the account struct
typedef struct account {
  enum account_type type;
  double balance;
} account;

// Define the bank struct
typedef struct bank {
  customer customers[MAX_CUSTOMERS];
  int num_customers;
} bank;

// Create a new bank
bank *create_bank() {
  bank *new_bank = malloc(sizeof(bank));
  if (new_bank == NULL) {
    return NULL;
  }

  new_bank->num_customers = 0;

  return new_bank;
}

// Add a new customer to the bank
int add_customer(bank *bank, customer *new_customer) {
  if (bank->num_customers >= MAX_CUSTOMERS) {
    return -1;
  }

  bank->customers[bank->num_customers++] = *new_customer;

  return 0;
}

// Find a customer by name
customer *find_customer(bank *bank, char *name) {
  for (int i = 0; i < bank->num_customers; i++) {
    if (strcmp(bank->customers[i].name, name) == 0) {
      return &bank->customers[i];
    }
  }

  return NULL;
}

// Create a new account for a customer
int add_account(customer *customer, account *new_account) {
  if (customer->num_accounts >= MAX_ACCOUNTS) {
    return -1;
  }

  customer->accounts[customer->num_accounts++] = new_account;

  return 0;
}

// Find an account by type
account *find_account(customer *customer, enum account_type type) {
  for (int i = 0; i < customer->num_accounts; i++) {
    if (customer->accounts[i]->type == type) {
      return customer->accounts[i];
    }
  }

  return NULL;
}

// Deposit money into an account
int deposit(account *account, double amount) {
  if (amount <= 0) {
    return -1;
  }

  account->balance += amount;

  return 0;
}

// Withdraw money from an account
int withdraw(account *account, double amount) {
  if (amount <= 0 || amount > account->balance) {
    return -1;
  }

  account->balance -= amount;

  return 0;
}

// Transfer money between accounts
int transfer(account *from_account, account *to_account, double amount) {
  if (amount <= 0 || amount > from_account->balance) {
    return -1;
  }

  from_account->balance -= amount;
  to_account->balance += amount;

  return 0;
}

// Print the customer's account balances
void print_balances(customer *customer) {
  printf("Customer: %s\n", customer->name);
  for (int i = 0; i < customer->num_accounts; i++) {
    printf("  %s: $%.2f\n", customer->accounts[i]->type == SAVINGS ? "Savings" : customer->accounts[i]->type == CHECKING ? "Checking" : "Loan", customer->accounts[i]->balance);
  }
}

// Run the banking system
int main() {
  // Create a new bank
  bank *bank = create_bank();

  // Add some customers to the bank
  customer alice = {"Alice", 25, 0, NULL};
  add_customer(bank, &alice);
  customer bob = {"Bob", 30, 0, NULL};
  add_customer(bank, &bob);

  // Add some accounts to the customers
  account alice_savings = {SAVINGS, 1000.00};
  add_account(&alice, &alice_savings);
  account alice_checking = {CHECKING, 500.00};
  add_account(&alice, &alice_checking);
  account bob_savings = {SAVINGS, 2000.00};
  add_account(&bob, &bob_savings);
  account bob_checking = {CHECKING, 1000.00};
  add_account(&bob, &bob_checking);
  account bob_loan = {LOAN, 5000.00};
  add_account(&bob, &bob_loan);

  // Deposit some money into the accounts
  deposit(&alice_savings, 100.00);
  deposit(&alice_checking, 50.00);
  deposit(&bob_savings, 200.00);
  deposit(&bob_checking, 100.00);

  // Withdraw some money from the accounts
  withdraw(&alice_checking, 25.00);
  withdraw(&bob_savings, 100.00);

  // Transfer some money between accounts
  transfer(&alice_savings, &alice_checking, 100.00);
  transfer(&bob_checking, &bob_loan, 200.00);

  // Print the customer's account balances
  print_balances(&alice);
  print_balances(&bob);

  return 0;
}