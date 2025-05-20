//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10

struct customer {
  char name[20];
  int account_number;
  double balance;
  struct customer* next;
};

void add_customer(struct customer** head) {
  struct customer* new_customer = malloc(sizeof(struct customer));
  printf("Enter name: ");
  scanf("%s", new_customer->name);
  printf("Enter account number: ");
  scanf("%d", &new_customer->account_number);
  printf("Enter initial balance: ");
  scanf("%lf", &new_customer->balance);
  new_customer->next = NULL;

  if (*head == NULL) {
    *head = new_customer;
  } else {
    (*head)->next = new_customer;
  }
}

void print_customers(struct customer* head) {
  while (head) {
    printf("Name: %s, Account Number: %d, Balance: %.2lf\n", head->name, head->account_number, head->balance);
    head = head->next;
  }
}

void deposit(struct customer* head) {
  int account_number;
  double amount;

  printf("Enter account number: ");
  scanf("%d", &account_number);
  printf("Enter deposit amount: ");
  scanf("%lf", &amount);

  struct customer* current_customer = head;
  while (current_customer) {
    if (current_customer->account_number == account_number) {
      current_customer->balance += amount;
      printf("Deposit successful.\n");
      break;
    }
    current_customer = current_customer->next;
  }

  if (current_customer == NULL) {
    printf("Account not found.\n");
  }
}

void withdraw(struct customer* head) {
  int account_number;
  double amount;

  printf("Enter account number: ");
  scanf("%d", &account_number);
  printf("Enter withdrawal amount: ");
  scanf("%lf", &amount);

  struct customer* current_customer = head;
  while (current_customer) {
    if (current_customer->account_number == account_number) {
      if (current_customer->balance - amount >= 0) {
        current_customer->balance -= amount;
        printf("Withdrawal successful.\n");
        break;
      } else {
        printf("Insufficient funds.\n");
      }
    }
    current_customer = current_customer->next;
  }

  if (current_customer == NULL) {
    printf("Account not found.\n");
  }
}

int main() {
  struct customer* head = NULL;

  // Add customers
  add_customer(&head);
  add_customer(&head);
  add_customer(&head);

  // Print customers
  print_customers(head);

  // Deposit
  deposit(head);

  // Withdraw
  withdraw(head);

  // Print customers after transactions
  print_customers(head);

  return 0;
}