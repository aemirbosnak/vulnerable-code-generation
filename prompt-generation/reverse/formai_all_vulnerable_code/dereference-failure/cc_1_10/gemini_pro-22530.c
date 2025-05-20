//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the bank account structure
typedef struct {
  char *name;
  int account_number;
  double balance;
} bank_account;

// Create a new bank account
bank_account *create_account(char *name, int account_number, double balance) {
  bank_account *account = malloc(sizeof(bank_account));
  account->name = strdup(name);
  account->account_number = account_number;
  account->balance = balance;
  return account;
}

// Print a bank account
void print_account(bank_account *account) {
  printf("Name: %s\n", account->name);
  printf("Account Number: %d\n", account->account_number);
  printf("Balance: %f\n", account->balance);
}

// Deposit money into a bank account
void deposit(bank_account *account, double amount) {
  account->balance += amount;
}

// Withdraw money from a bank account
void withdraw(bank_account *account, double amount) {
  if (amount <= account->balance) {
    account->balance -= amount;
  } else {
    printf("Insufficient funds\n");
  }
}

// Transfer money from one bank account to another
void transfer(bank_account *from_account, bank_account *to_account, double amount) {
  if (amount <= from_account->balance) {
    from_account->balance -= amount;
    to_account->balance += amount;
  } else {
    printf("Insufficient funds\n");
  }
}

// Close a bank account
void close_account(bank_account *account) {
  free(account->name);
  free(account);
}

// Read a bank account from a file
bank_account *read_account(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }
  char name[256];
  int account_number;
  double balance;
  fscanf(file, "%s %d %lf", name, &account_number, &balance);
  fclose(file);
  return create_account(name, account_number, balance);
}

// Write a bank account to a file
void write_account(char *filename, bank_account *account) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    return;
  }
  fprintf(file, "%s %d %lf", account->name, account->account_number, account->balance);
  fclose(file);
}

// Main function
int main() {
  // Create three bank accounts
  bank_account *account1 = create_account("John Doe", 123456789, 1000.0);
  bank_account *account2 = create_account("Jane Doe", 987654321, 2000.0);
  bank_account *account3 = create_account("John Smith", 1122334455, 3000.0);

  // Print the three bank accounts
  print_account(account1);
  print_account(account2);
  print_account(account3);

  // Deposit money into account1
  deposit(account1, 500.0);

  // Withdraw money from account2
  withdraw(account2, 300.0);

  // Transfer money from account3 to account2
  transfer(account3, account2, 1000.0);

  // Close account1
  close_account(account1);

  // Read account1 from a file
  bank_account *account1_new = read_account("account1.txt");

  // Write account1_new to a file
  write_account("account1_new.txt", account1_new);

  // Free the bank accounts
  free(account1_new);
  free(account2);
  free(account3);

  return 0;
}