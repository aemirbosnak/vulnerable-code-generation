//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct account {
  int number;
  double balance;
  struct account *next;
} account;

account *head = NULL;

void create_account(int number, double balance) {
  account *new_account = (account *)malloc(sizeof(account));
  new_account->number = number;
  new_account->balance = balance;
  new_account->next = NULL;

  if (head == NULL) {
    head = new_account;
  } else {
    account *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_account;
  }
}

void print_all_accounts() {
  account *current = head;
  while (current != NULL) {
    printf("Account number: %d\n", current->number);
    printf("Balance: %.2f\n", current->balance);
    printf("\n");
    current = current->next;
  }
}

void withdraw_money(int number, double amount) {
  account *current = head;
  while (current != NULL) {
    if (current->number == number) {
      if (current->balance >= amount) {
        current->balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", current->balance);
      } else {
        printf("Insufficient funds.\n");
      }
      return;
    }
    current = current->next;
  }
  printf("Account not found.\n");
}

void deposit_money(int number, double amount) {
  account *current = head;
  while (current != NULL) {
    if (current->number == number) {
      current->balance += amount;
      printf("Deposit successful. New balance: %.2f\n", current->balance);
      return;
    }
    current = current->next;
  }
  printf("Account not found.\n");
}

void delete_account(int number) {
  account *current = head;
  account *previous = NULL;
  while (current != NULL) {
    if (current->number == number) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
  printf("Account not found.\n");
}

int main() {
  srand(time(NULL));

  // Create some random accounts
  for (int i = 0; i < 10; i++) {
    int number = rand() % 1000000;
    double balance = (double)(rand() % 10000) / 100;
    create_account(number, balance);
  }

  // Print all accounts
  print_all_accounts();

  // Withdraw some money from a random account
  int number = rand() % 1000000;
  double amount = (double)(rand() % 10000) / 100;
  withdraw_money(number, amount);

  // Deposit some money into a random account
  number = rand() % 1000000;
  amount = (double)(rand() % 10000) / 100;
  deposit_money(number, amount);

  // Delete a random account
  number = rand() % 1000000;
  delete_account(number);

  // Print all accounts again
  print_all_accounts();

  return 0;
}