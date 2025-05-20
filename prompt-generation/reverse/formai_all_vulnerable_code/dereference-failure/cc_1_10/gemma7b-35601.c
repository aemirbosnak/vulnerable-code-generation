//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

struct customer {
  char name[50];
  int account_number;
  double balance;
  struct customer* next;
};

struct customer* create_customer(char* name, int account_number, double balance) {
  struct customer* new_customer = malloc(sizeof(struct customer));
  strcpy(new_customer->name, name);
  new_customer->account_number = account_number;
  new_customer->balance = balance;
  new_customer->next = NULL;

  return new_customer;
}

struct customer* add_customer(struct customer* head, char* name, int account_number, double balance) {
  struct customer* new_customer = create_customer(name, account_number, balance);

  if (head == NULL) {
    head = new_customer;
  } else {
    struct customer* tail = head;
    while (tail->next != NULL) {
      tail = tail->next;
    }
    tail->next = new_customer;
  }

  return head;
}

void print_customers(struct customer* head) {
  struct customer* current = head;
  while (current) {
    printf("%s, %d, %lf\n", current->name, current->account_number, current->balance);
    current = current->next;
  }
}

int main() {
  struct customer* head = NULL;
  head = add_customer(head, "John Doe", 12345, 1000);
  head = add_customer(head, "Jane Doe", 67890, 2000);
  head = add_customer(head, "Bill Smith", 32148, 3000);

  print_customers(head);

  return 0;
}