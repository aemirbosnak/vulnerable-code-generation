//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 10

typedef struct Transaction {
  char name[20];
  int amount;
  struct Transaction* next;
} Transaction;

Transaction* createTransaction(char* name, int amount) {
  Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
  strcpy(newTransaction->name, name);
  newTransaction->amount = amount;
  newTransaction->next = NULL;
  return newTransaction;
}

void addTransaction(Transaction* head, char* name, int amount) {
  Transaction* newTransaction = createTransaction(name, amount);
  if (head == NULL) {
    head = newTransaction;
  } else {
    newTransaction->next = head;
    head = newTransaction;
  }
}

int calculateTotal(Transaction* head) {
  int total = 0;
  Transaction* currentTransaction = head;
  while (currentTransaction) {
    total += currentTransaction->amount;
    currentTransaction = currentTransaction->next;
  }
  return total;
}

int main() {
  Transaction* head = NULL;
  addTransaction(head, "Buy groceries", 50);
  addTransaction(head, "Pay rent", -20);
  addTransaction(head, "Get a paycheck", 100);
  addTransaction(head, "Go out to eat", -30);

  int total = calculateTotal(head);
  printf("Total: $%d\n", total);

  return 0;
}