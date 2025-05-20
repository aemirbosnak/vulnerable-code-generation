//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10
#define MAX_TRANSACTIONS 100

typedef struct Customer {
  char name[20];
  int account_number;
  double balance;
} Customer;

typedef struct Transaction {
  char description[50];
  double amount;
  struct Customer *customer;
} Transaction;

Customer customers[MAX_CUSTOMERS];
Transaction transactions[MAX_TRANSACTIONS];

void initializeCustomers() {
  for (int i = 0; i < MAX_CUSTOMERS; i++) {
    customers[i].account_number = -1;
  }
}

void addCustomer(char *name, int account_number, double balance) {
  for (int i = 0; i < MAX_CUSTOMERS; i++) {
    if (customers[i].account_number == -1) {
      customers[i].account_number = account_number;
      strcpy(customers[i].name, name);
      customers[i].balance = balance;
      return;
    }
  }

  // Error: no space for new customer
  printf("Error: Unable to add customer.\n");
}

void viewCustomerTransactions(int account_number) {
  for (int i = 0; i < MAX_TRANSACTIONS; i++) {
    if (transactions[i].customer->account_number == account_number) {
      printf("%s - %lf\n", transactions[i].description, transactions[i].amount);
    }
  }
}

int main() {
  initializeCustomers();

  // Add some customers
  addCustomer("John Doe", 123456, 1000.0);
  addCustomer("Jane Doe", 654321, 500.0);

  // View customer transactions
  viewCustomerTransactions(123456);

  return 0;
}