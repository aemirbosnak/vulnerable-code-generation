//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10
#define MAX_TRANSACTIONS 20

typedef struct Customer {
  char name[50];
  int account_number;
  double balance;
  struct Customer *next;
} Customer;

typedef struct Transaction {
  char description[50];
  double amount;
  struct Transaction *next;
} Transaction;

Customer *head_customer = NULL;
Transaction *head_transaction = NULL;

void add_customer(char *name, int account_number, double balance) {
  Customer *new_customer = (Customer *)malloc(sizeof(Customer));
  strcpy(new_customer->name, name);
  new_customer->account_number = account_number;
  new_customer->balance = balance;
  new_customer->next = NULL;

  if (head_customer == NULL) {
    head_customer = new_customer;
  } else {
    head_customer->next = new_customer;
  }
}

void add_transaction(char *description, double amount) {
  Transaction *new_transaction = (Transaction *)malloc(sizeof(Transaction));
  strcpy(new_transaction->description, description);
  new_transaction->amount = amount;
  new_transaction->next = NULL;

  if (head_transaction == NULL) {
    head_transaction = new_transaction;
  } else {
    head_transaction->next = new_transaction;
  }
}

void print_customer_list() {
  Customer *current_customer = head_customer;
  while (current_customer) {
    printf("Name: %s, Account Number: %d, Balance: %.2lf\n", current_customer->name, current_customer->account_number, current_customer->balance);
    current_customer = current_customer->next;
  }
}

void print_transaction_list() {
  Transaction *current_transaction = head_transaction;
  while (current_transaction) {
    printf("Description: %s, Amount: %.2lf\n", current_transaction->description, current_transaction->amount);
    current_transaction = current_transaction->next;
  }
}

int main() {
  add_customer("John Doe", 123456, 1000.0);
  add_customer("Jane Doe", 654821, 2000.0);
  add_transaction("Bought groceries", 500.0);
  add_transaction("Paid rent", 200.0);

  print_customer_list();
  print_transaction_list();

  return 0;
}