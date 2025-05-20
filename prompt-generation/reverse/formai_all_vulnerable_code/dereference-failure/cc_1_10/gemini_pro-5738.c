//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
  char *name;
  double balance;
  struct account *next;
} account_t;

account_t *create_account(char *name, double balance) {
  account_t *account = malloc(sizeof(account_t));
  account->name = strdup(name);
  account->balance = balance;
  account->next = NULL;
  return account;
}

void destroy_account(account_t *account) {
  free(account->name);
  free(account);
}

account_t *insert_account(account_t *head, account_t *account) {
  if (head == NULL) {
    return account;
  } else {
    account->next = head;
    return account;
  }
}

account_t *find_account(account_t *head, char *name) {
  while (head != NULL) {
    if (strcmp(head->name, name) == 0) {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

void deposit(account_t *account, double amount) {
  account->balance += amount;
}

void withdraw(account_t *account, double amount) {
  if (amount <= account->balance) {
    account->balance -= amount;
  }
}

void transfer(account_t *from, account_t *to, double amount) {
  if (amount <= from->balance) {
    from->balance -= amount;
    to->balance += amount;
  }
}

void print_account(account_t *account) {
  printf("%s: %f\n", account->name, account->balance);
}

void print_accounts(account_t *head) {
  while (head != NULL) {
    print_account(head);
    head = head->next;
  }
}

int main() {
  account_t *head = NULL;

  head = insert_account(head, create_account("John Doe", 1000.0));
  head = insert_account(head, create_account("Jane Doe", 2000.0));
  head = insert_account(head, create_account("Bob Smith", 3000.0));

  print_accounts(head);

  deposit(find_account(head, "John Doe"), 500.0);
  withdraw(find_account(head, "Jane Doe"), 200.0);
  transfer(find_account(head, "Bob Smith"), find_account(head, "John Doe"), 100.0);

  print_accounts(head);

  destroy_account(find_account(head, "John Doe"));
  destroy_account(find_account(head, "Jane Doe"));
  destroy_account(find_account(head, "Bob Smith"));

  return 0;
}