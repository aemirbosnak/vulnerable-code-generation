//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 10

struct Transaction {
  char name[50];
  int amount;
  char type;
  struct Transaction* next;
};

struct BankingRecord {
  struct Transaction* head;
  int numTransactions;
  int totalBalance;
};

void addTransaction(struct BankingRecord* record, char* name, int amount, char type) {
  struct Transaction* newTransaction = malloc(sizeof(struct Transaction));
  strcpy(newTransaction->name, name);
  newTransaction->amount = amount;
  newTransaction->type = type;
  newTransaction->next = NULL;

  if (record->head == NULL) {
    record->head = newTransaction;
  } else {
    record->head->next = newTransaction;
  }

  record->numTransactions++;
  record->totalBalance += amount;
}

int main() {
  struct BankingRecord* record = malloc(sizeof(struct BankingRecord));
  record->head = NULL;
  record->numTransactions = 0;
  record->totalBalance = 0;

  addTransaction(record, "John Doe", 100, 'D');
  addTransaction(record, "Jane Doe", 50, 'W');
  addTransaction(record, "Peter Pan", 20, 'D');

  printf("Total balance: %d\n", record->totalBalance);
  printf("Number of transactions: %d\n", record->numTransactions);

  return 0;
}