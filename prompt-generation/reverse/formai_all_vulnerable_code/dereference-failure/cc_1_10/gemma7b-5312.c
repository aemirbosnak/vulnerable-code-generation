//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10

struct customer {
  char name[20];
  int account_no;
  double balance;
  struct customer* next;
};

struct customer* create_customer(char* name, int account_no, double balance) {
  struct customer* new_customer = (struct customer*)malloc(sizeof(struct customer));
  strcpy(new_customer->name, name);
  new_customer->account_no = account_no;
  new_customer->balance = balance;
  new_customer->next = NULL;
  return new_customer;
}

struct customer* add_customer(struct customer* head, char* name, int account_no, double balance) {
  struct customer* new_customer = create_customer(name, account_no, balance);
  if (head == NULL) {
    head = new_customer;
  } else {
    struct customer* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_customer;
  }
  return head;
}

double get_balance(struct customer* head, int account_no) {
  struct customer* temp = head;
  while (temp) {
    if (temp->account_no == account_no) {
      return temp->balance;
    }
    temp = temp->next;
  }
  return -1;
}

void transfer_money(struct customer* head, int account_no1, int account_no2, double amount) {
  double balance1 = get_balance(head, account_no1);
  double balance2 = get_balance(head, account_no2);

  if (balance1 >= amount && balance2 > 0) {
    balance1 -= amount;
    balance2 += amount;

    struct customer* temp = head;
    while (temp) {
      if (temp->account_no == account_no1) {
        temp->balance = balance1;
      }
      if (temp->account_no == account_no2) {
        temp->balance = balance2;
      }
      temp = temp->next;
    }
  }
}

int main() {
  struct customer* head = NULL;

  add_customer(head, "John Doe", 1234, 1000);
  add_customer(head, "Jane Doe", 5678, 2000);
  add_customer(head, "Peter Pan", 9012, 3000);

  transfer_money(head, 1234, 5678, 500);

  double balance = get_balance(head, 5678);

  printf("Balance of account no. 5678: %.2lf\n", balance);

  return 0;
}