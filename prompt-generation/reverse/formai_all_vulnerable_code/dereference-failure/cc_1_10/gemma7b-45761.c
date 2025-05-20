//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct Account {
  char name[50];
  int account_number;
  double balance;
  struct Account* next;
};

void addAccount(struct Account** head) {
  struct Account* newAccount = malloc(sizeof(struct Account));
  printf("Enter account name: ");
  scanf("%s", newAccount->name);
  printf("Enter account number: ");
  scanf("%d", &newAccount->account_number);
  printf("Enter initial balance: ");
  scanf("%lf", &newAccount->balance);
  newAccount->next = *head;
  *head = newAccount;
}

void printAccounts(struct Account* head) {
  while (head) {
    printf("Account name: %s\n", head->name);
    printf("Account number: %d\n", head->account_number);
    printf("Balance: %.2lf\n", head->balance);
    printf("\n");
    head = head->next;
  }
}

int main() {
  struct Account* head = NULL;
  int choice;

  while (1) {
    printf("1. Add Account\n");
    printf("2. Print Accounts\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addAccount(&head);
        break;
      case 2:
        printAccounts(head);
        break;
      default:
        exit(1);
    }
  }

  return 0;
}