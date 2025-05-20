//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_TRANSACTIONS 100

typedef struct {
  int amount;
  char description[100];
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int num_transactions = 0;

sem_t mutex;

void *add_transaction(void *args) {
  sem_wait(&mutex);
  Transaction *transaction = (Transaction *)args;
  transactions[num_transactions++] = *transaction;
  sem_post(&mutex);
  return NULL;
}

void *print_transactions(void *args) {
  while (1) {
    sem_wait(&mutex);
    for (int i = 0; i < num_transactions; i++) {
      printf("%d %s\n", transactions[i].amount, transactions[i].description);
    }
    sem_post(&mutex);
    sleep(1);
  }
  return NULL;
}

int main() {
  sem_init(&mutex, 0, 1);

  pthread_t add_thread, print_thread;
  pthread_create(&add_thread, NULL, add_transaction, NULL);
  pthread_create(&print_thread, NULL, print_transactions, NULL);

  pthread_join(add_thread, NULL);
  pthread_join(print_thread, NULL);

  sem_destroy(&mutex);
  return 0;
}