//FormAI DATASET v1.0 Category: Banking Record System ; Style: multi-threaded
#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>

#define MAX_RECORDS 1000000

typedef struct record_t {
    int accountId;
    double balance;
} Record;

Record *records[MAX_RECORDS];

void *transferMoney(void *arg) {
    int *params = (int *) arg;
    int sender = params[0], recipient = params[1];
    double amount = *(double *) &params[2];

    // Lock the records
    while(pthread_mutex_lock(&records[sender]) != 0);
    while(pthread_mutex_lock(&records[recipient]) != 0);

    // Transfer money between accounts
    records[sender]->balance -= amount;
    records[recipient]->balance += amount;

    // Unlock the records
    pthread_mutex_unlock(&records[sender]);
    pthread_mutex_unlock(&records[recipient]);

    return NULL;
}

int main() {
    // Initialize records
    for (int i = 0; i < MAX_RECORDS; i++) {
        records[i] = (Record *) malloc(sizeof(Record));
        records[i]->accountId = i + 1;
        records[i]->balance = 0;
        pthread_mutex_init(&records[i], NULL);
    }

    // Transfer some money between accounts
    int params1[] = {0, 1, sizeof(double)};
    int params2[] = {2, 3, sizeof(double)};
    double amount1 = 1000.0, amount2 = 500.0;
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, transferMoney, (void *)params1);
    pthread_create(&thread2, NULL, transferMoney, (void *)params2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Check account balances
    printf("Account 1 balance: %lf\n", records[0]->balance);
    printf("Account 2 balance: %lf\n", records[1]->balance);
    printf("Account 3 balance: %lf\n", records[2]->balance);
    printf("Account 4 balance: %lf\n", records[3]->balance);

    // Free memory and destroy mutexes
    for (int i = 0; i < MAX_RECORDS; i++) {
        free(records[i]);
        pthread_mutex_destroy(&records[i]);
    }

    return 0;
}