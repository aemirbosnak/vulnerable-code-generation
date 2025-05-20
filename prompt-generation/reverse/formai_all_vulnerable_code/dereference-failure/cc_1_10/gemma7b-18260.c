//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM_TRANSACTIONS 100

typedef struct Transaction {
  char *name;
  double amount;
  double category;
  struct Transaction *next;
} Transaction;

Transaction *transactions = NULL;

void addTransaction(char *name, double amount, double category) {
  Transaction *newTransaction = malloc(sizeof(Transaction));
  newTransaction->name = strdup(name);
  newTransaction->amount = amount;
  newTransaction->category = category;
  newTransaction->next = NULL;

  if (transactions == NULL) {
    transactions = newTransaction;
  } else {
    transactions->next = newTransaction;
    transactions = newTransaction;
  }
}

double calculateTotalAmount(double category) {
  double totalAmount = 0.0;
  Transaction *currentTransaction = transactions;

  while (currentTransaction) {
    if (currentTransaction->category == category) {
      totalAmount += currentTransaction->amount;
    }
    currentTransaction = currentTransaction->next;
  }

  return totalAmount;
}

int main() {
  addTransaction("Groceries", 50.0, 1);
  addTransaction("Dining out", 20.0, 2);
  addTransaction("Electronics", 100.0, 3);
  addTransaction("Clothing", 25.0, 4);

  double totalAmount = calculateTotalAmount(2);

  printf("Total amount for category 2: $%.2lf\n", totalAmount);

  return 0;
}