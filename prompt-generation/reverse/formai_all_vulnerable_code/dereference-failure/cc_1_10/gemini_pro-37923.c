//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a customer struct
typedef struct customer {
  char name[50];
  char address[100];
  char phone[15];
  int balance;
} customer;

// Define a bank struct
typedef struct bank {
  char name[50];
  char address[100];
  char phone[15];
  customer customers[100];
  int num_customers;
} bank;

// Create a new bank
bank *create_bank(char *name, char *address, char *phone) {
  bank *new_bank = (bank *)malloc(sizeof(bank));
  strcpy(new_bank->name, name);
  strcpy(new_bank->address, address);
  strcpy(new_bank->phone, phone);
  new_bank->num_customers = 0;
  return new_bank;
}

// Add a new customer to a bank
void add_customer(bank *bank, customer *new_customer) {
  bank->customers[bank->num_customers] = *new_customer;
  bank->num_customers++;
}

// Get a customer by their name
customer *get_customer_by_name(bank *bank, char *name) {
  for (int i = 0; i < bank->num_customers; i++) {
    if (strcmp(bank->customers[i].name, name) == 0) {
      return &bank->customers[i];
    }
  }
  return NULL;
}

// Deposit money into a customer's account
void deposit_money(customer *customer, int amount) {
  customer->balance += amount;
}

// Withdraw money from a customer's account
void withdraw_money(customer *customer, int amount) {
  if (amount <= customer->balance) {
    customer->balance -= amount;
  } else {
    printf("Insufficient funds\n");
  }
}

// Print a customer's information
void print_customer(customer *customer) {
  printf("Name: %s\n", customer->name);
  printf("Address: %s\n", customer->address);
  printf("Phone: %s\n", customer->phone);
  printf("Balance: %d\n", customer->balance);
}

// Print a bank's information
void print_bank(bank *bank) {
  printf("Name: %s\n", bank->name);
  printf("Address: %s\n", bank->address);
  printf("Phone: %s\n", bank->phone);
  printf("Number of customers: %d\n", bank->num_customers);
}

// Main function
int main() {
  // Create a new bank
  bank *bank = create_bank("First Bank", "123 Main Street", "555-1212");

  // Add some customers to the bank
  customer customer1 = {"John Smith", "123 Elm Street", "555-1213", 1000};
  add_customer(bank, &customer1);
  customer customer2 = {"Jane Doe", "456 Oak Street", "555-1214", 2000};
  add_customer(bank, &customer2);
  customer customer3 = {"Bill Jones", "789 Pine Street", "555-1215", 3000};
  add_customer(bank, &customer3);

  // Print the bank's information
  print_bank(bank);

  // Get a customer by their name
  customer *customer = get_customer_by_name(bank, "John Smith");

  // Print the customer's information
  print_customer(customer);

  // Deposit money into the customer's account
  deposit_money(customer, 100);

  // Print the customer's information again
  print_customer(customer);

  // Withdraw money from the customer's account
  withdraw_money(customer, 200);

  // Print the customer's information again
  print_customer(customer);

  return 0;
}