//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

typedef struct customer {
  char name[50];
  int account_number;
  double balance;
  struct customer *next;
} customer;

typedef struct transaction {
  int transaction_id;
  char description[200];
  double amount;
  struct transaction *next;
} transaction;

customer *head = NULL;
transaction *tail = NULL;

void add_customer(char *name, int account_number, double balance) {
  customer *new_customer = (customer *)malloc(sizeof(customer));
  strcpy(new_customer->name, name);
  new_customer->account_number = account_number;
  new_customer->balance = balance;
  new_customer->next = NULL;

  if (head == NULL) {
    head = new_customer;
  } else {
    tail->next = new_customer;
    tail = new_customer;
  }
}

void add_transaction(char *description, double amount) {
  transaction *new_transaction = (transaction *)malloc(sizeof(transaction));
  new_transaction->transaction_id = tail->transaction_id + 1;
  strcpy(new_transaction->description, description);
  new_transaction->amount = amount;
  new_transaction->next = NULL;

  if (tail == NULL) {
    tail = new_transaction;
  } else {
    tail->next = new_transaction;
    tail = new_transaction;
  }
}

void print_customer_list() {
  customer *current_customer = head;
  while (current_customer) {
    printf("%s (%d) - Balance: %.2lf\n", current_customer->name, current_customer->account_number, current_customer->balance);
    current_customer = current_customer->next;
  }
}

void print_transaction_list() {
  transaction *current_transaction = tail;
  while (current_transaction) {
    printf("%d - %s - %.2lf\n", current_transaction->transaction_id, current_transaction->description, current_transaction->amount);
    current_transaction = current_transaction->next;
  }
}

int main() {
  add_customer("John Doe", 123456, 1000.0);
  add_customer("Jane Doe", 654912, 2000.0);
  add_customer("Peter Pan", 321549, 3000.0);

  add_transaction("Bought groceries", 500.0);
  add_transaction("Paid rent", 200.0);
  add_transaction("Sent money to Jane", 300.0);

  print_customer_list();
  print_transaction_list();

  return 0;
}