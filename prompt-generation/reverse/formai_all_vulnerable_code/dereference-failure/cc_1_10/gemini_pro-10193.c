//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list representing a bank account
typedef struct account {
  int account_number;
  char *name;
  double balance;
  struct account *next;
} account_t;

// A linked list of bank accounts
typedef struct bank {
  account_t *head;
  account_t *tail;
} bank_t;

// Create a new bank
bank_t *create_bank() {
  bank_t *bank = malloc(sizeof(bank_t));
  bank->head = NULL;
  bank->tail = NULL;
  return bank;
}

// Add an account to the bank
void add_account(bank_t *bank, int account_number, char *name, double balance) {
  account_t *new_account = malloc(sizeof(account_t));
  new_account->account_number = account_number;
  new_account->name = strdup(name);
  new_account->balance = balance;
  new_account->next = NULL;

  if (bank->head == NULL) {
    bank->head = new_account;
    bank->tail = new_account;
  } else {
    bank->tail->next = new_account;
    bank->tail = new_account;
  }
}

// Find an account by account number
account_t *find_account(bank_t *bank, int account_number) {
  account_t *current = bank->head;
  while (current != NULL) {
    if (current->account_number == account_number) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Deposit money into an account
void deposit(account_t *account, double amount) {
  account->balance += amount;
}

// Withdraw money from an account
void withdraw(account_t *account, double amount) {
  if (account->balance >= amount) {
    account->balance -= amount;
  } else {
    printf("Insufficient funds\n");
  }
}

// Transfer money between two accounts
void transfer(bank_t *bank, int from_account_number, int to_account_number, double amount) {
  account_t *from_account = find_account(bank, from_account_number);
  account_t *to_account = find_account(bank, to_account_number);

  if (from_account != NULL && to_account != NULL) {
    if (from_account->balance >= amount) {
      from_account->balance -= amount;
      to_account->balance += amount;
    } else {
      printf("Insufficient funds\n");
    }
  } else {
    printf("Invalid account number\n");
  }
}

// Print the balance of an account
void print_balance(account_t *account) {
  printf("Account number: %d\n", account->account_number);
  printf("Name: %s\n", account->name);
  printf("Balance: %.2f\n", account->balance);
}

// Print all accounts in the bank
void print_accounts(bank_t *bank) {
  account_t *current = bank->head;
  while (current != NULL) {
    print_balance(current);
    current = current->next;
  }
}

// Free the memory used by the bank
void free_bank(bank_t *bank) {
  account_t *current = bank->head;
  while (current != NULL) {
    account_t *next = current->next;
    free(current->name);
    free(current);
    current = next;
  }
  free(bank);
}

int main() {
  // Create a new bank
  bank_t *bank = create_bank();

  // Add some accounts to the bank
  add_account(bank, 12345, "John Doe", 1000.00);
  add_account(bank, 54321, "Jane Smith", 2000.00);
  add_account(bank, 67890, "Bob Jones", 3000.00);

  // Print all accounts in the bank
  print_accounts(bank);

  // Deposit money into an account
  deposit(find_account(bank, 12345), 500.00);

  // Withdraw money from an account
  withdraw(find_account(bank, 54321), 300.00);

  // Transfer money between two accounts
  transfer(bank, 67890, 12345, 200.00);

  // Print all accounts in the bank
  print_accounts(bank);

  // Free the memory used by the bank
  free_bank(bank);

  return 0;
}