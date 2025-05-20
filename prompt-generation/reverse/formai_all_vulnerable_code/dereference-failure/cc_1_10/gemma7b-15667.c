//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define CURRENCY_LIMIT 1000000

typedef struct Transaction {
  char *name;
  int amount;
  struct Transaction *next;
} Transaction;

Transaction *createTransaction(char *name, int amount) {
  Transaction *newTransaction = malloc(sizeof(Transaction));
  newTransaction->name = strdup(name);
  newTransaction->amount = amount;
  newTransaction->next = NULL;
  return newTransaction;
}

void addTransaction(Transaction *head, char *name, int amount) {
  Transaction *newTransaction = createTransaction(name, amount);
  if (head == NULL) {
    head = newTransaction;
  } else {
    head->next = newTransaction;
  }
  head = newTransaction;
}

int calculateTotalAmount(Transaction *head) {
  int totalAmount = 0;
  while (head) {
    totalAmount += head->amount;
    head = head->next;
  }
  return totalAmount;
}

int main() {
  Transaction *head = NULL;

  // Add some transactions
  addTransaction(head, "Buy groceries", 50);
  addTransaction(head, "Sell stocks", -20);
  addTransaction(head, "Go to the movies", 25);

  // Calculate the total amount
  int totalAmount = calculateTotalAmount(head);

  // Print the total amount
  printf("Total amount: %d\n", totalAmount);

  return 0;
}