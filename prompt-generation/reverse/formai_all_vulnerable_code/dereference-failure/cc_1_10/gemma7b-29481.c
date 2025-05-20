//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_ACCOUNT_NUMBER_LENGTH 20

typedef struct Account {
  char name[MAX_NAME_LENGTH];
  int account_number;
  double balance;
  struct Account* next;
} Account;

Account* insert_account(Account* head, char* name, int account_number, double balance) {
  Account* new_account = malloc(sizeof(Account));

  new_account->name[0] = '\0';
  strncpy(new_account->name, name, MAX_NAME_LENGTH - 1);

  new_account->account_number = account_number;
  new_account->balance = balance;

  new_account->next = NULL;

  if (head == NULL) {
    head = new_account;
  } else {
    head->next = new_account;
  }

  return head;
}

int main() {
  Account* head = NULL;

  insert_account(&head, "John Doe", 123456, 1000.0);
  insert_account(&head, "Jane Doe", 546213, 2000.0);
  insert_account(&head, "Peter Pan", 785421, 3000.0);

  Account* current_account = head;

  while (current_account) {
    printf("Name: %s, Account Number: %d, Balance: %.2lf\n", current_account->name, current_account->account_number, current_account->balance);

    current_account = current_account->next;
  }

  return 0;
}