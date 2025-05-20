//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of customers and accounts
#define MAX_CUSTOMERS 10
#define MAX_ACCOUNTS 10

// Define the account types
#define SAVINGS_ACCOUNT 1
#define CHECKING_ACCOUNT 2

// Define the customer structure
typedef struct customer {
  char name[50];
  int account_number;
  int account_type;
  double balance;
} customer;

// Define the account structure
typedef struct account {
  int account_number;
  int account_type;
  double balance;
} account;

// Define the banking system structure
typedef struct banking_system {
  customer customers[MAX_CUSTOMERS];
  account accounts[MAX_ACCOUNTS];
  int num_customers;
  int num_accounts;
} banking_system;

// Create a new banking system
banking_system* create_banking_system() {
  banking_system* bs = (banking_system*)malloc(sizeof(banking_system));
  bs->num_customers = 0;
  bs->num_accounts = 0;
  return bs;
}

// Add a new customer to the banking system
void add_customer(banking_system* bs, customer* c) {
  bs->customers[bs->num_customers++] = *c;
}

// Add a new account to the banking system
void add_account(banking_system* bs, account* a) {
  bs->accounts[bs->num_accounts++] = *a;
}

// Find a customer by their name
customer* find_customer_by_name(banking_system* bs, char* name) {
  for (int i = 0; i < bs->num_customers; i++) {
    if (strcmp(bs->customers[i].name, name) == 0) {
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

// Print the balance of an account
void print_account_balance(banking_system* bs, int account_number) {
  account* a = find_account_by_account_number(bs, account_number);
  if (a != NULL) {
    printf("The balance of account %d is %f\n", a->account_number, a->balance);
  }
}

// Print the list of all customers
void print_list_of_customers(banking_system* bs) {
  for (int i = 0; i < bs->num_customers; i++) {
    printf("Customer %d: %s\n", i + 1, bs->customers[i].name);
  }
}

// Print the list of all accounts
void print_list_of_accounts(banking_system* bs) {
  for (int i = 0; i < bs->num_accounts; i++) {
    printf("Account %d: %s, Balance: %f\n", bs->accounts[i].account_number, bs->accounts[i].account_type == SAVINGS_ACCOUNT ? "Savings Account" : "Checking Account", bs->accounts[i].balance);
  }
}

// Main function
int main() {
  // Create a new banking system
  banking_system* bs = create_banking_system();

  // Add some customers to the banking system
  customer c1 = {"Alice", 123456, SAVINGS_ACCOUNT, 1000.0};
  add_customer(bs, &c1);
  customer c2 = {"Bob", 654321, CHECKING_ACCOUNT, 500.0};
  add_customer(bs, &c2);

  // Add some accounts to the banking system
  account a1 = {123456, SAVINGS_ACCOUNT, 1000.0};
  add_account(bs, &a1);
  account a2 = {654321, CHECKING_ACCOUNT, 500.0};
  add_account(bs, &a2);

  // Deposit money into an account
  deposit_money(bs, 123456, 100.0);

  // Withdraw money from an account
  withdraw_money(bs, 654321, 200.0);

  // Transfer money between two accounts
  transfer_money(bs, 123456, 654321, 300.0);

  // Print the balance of an account
  print_account_balance(bs, 123456);

  // Print the list of all customers
  print_list_of_customers(bs);

  // Print the list of all accounts
  print_list_of_accounts(bs);

  return 0;
}