//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

typedef struct customer {
  char name[50];
  int account_number;
  double balance;
  struct customer* next;
} customer;

customer* create_customer(char* name, int account_number, double balance) {
  customer* new_customer = (customer*)malloc(sizeof(customer));
  strcpy(new_customer->name, name);
  new_customer->account_number = account_number;
  new_customer->balance = balance;
  new_customer->next = NULL;
  return new_customer;
}

void deposit(customer* customer, double amount) {
  customer->balance += amount;
}

void withdraw(customer* customer, double amount) {
  if (amount <= customer->balance) {
    customer->balance -= amount;
  } else {
    printf("Insufficient funds.\n");
  }
}

void transfer(customer* customer1, customer* customer2, double amount) {
  if (amount <= customer1->balance) {
    deposit(customer2, amount);
    withdraw(customer1, amount);
  } else {
    printf("Insufficient funds.\n");
  }
}

int main() {
  customer* head = NULL;
  customer* tail = NULL;

  // Create a few customers
  customer* new_customer1 = create_customer("John Doe", 123456, 1000.0);
  customer* new_customer2 = create_customer("Jane Doe", 654321, 2000.0);
  customer* new_customer3 = create_customer("Peter Pan", 984123, 3000.0);

  // Add customers to the list
  if (head == NULL) {
    head = new_customer1;
    tail = new_customer1;
  } else {
    tail->next = new_customer2;
    tail = new_customer2;
  }
  tail->next = new_customer3;

  // Deposit money
  deposit(new_customer2, 500.0);

  // Withdraw money
  withdraw(new_customer1, 200.0);

  // Transfer money
  transfer(new_customer2, new_customer3, 200.0);

  // Print customer balances
  customer* current_customer = head;
  while (current_customer) {
    printf("Name: %s, Account Number: %d, Balance: %f\n", current_customer->name, current_customer->account_number, current_customer->balance);
    current_customer = current_customer->next;
  }

  return 0;
}