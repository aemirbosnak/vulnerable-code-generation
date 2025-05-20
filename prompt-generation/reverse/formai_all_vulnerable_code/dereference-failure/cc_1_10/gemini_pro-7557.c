//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int account_number;
  double balance;
} customer;

customer *create_customer(char *name, int account_number, double balance) {
  customer *new_customer = malloc(sizeof(customer));
  new_customer->name = strdup(name);
  new_customer->account_number = account_number;
  new_customer->balance = balance;
  return new_customer;
}

void destroy_customer(customer *customer) {
  free(customer->name);
  free(customer);
}

void print_customer(customer *customer) {
  printf("Name: %s\n", customer->name);
  printf("Account Number: %d\n", customer->account_number);
  printf("Balance: %.2f\n", customer->balance);
}

int main() {
  customer *customers[100];
  int num_customers = 0;

  // Create some customers
  customers[num_customers++] = create_customer("Alice", 123456789, 1000.00);
  customers[num_customers++] = create_customer("Bob", 987654321, 500.00);
  customers[num_customers++] = create_customer("Charlie", 112233445, 250.00);

  // Print the customers
  for (int i = 0; i < num_customers; i++) {
    print_customer(customers[i]);
  }

  // Destroy the customers
  for (int i = 0; i < num_customers; i++) {
    destroy_customer(customers[i]);
  }

  return 0;
}