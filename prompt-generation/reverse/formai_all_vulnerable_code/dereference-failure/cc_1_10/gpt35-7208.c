//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 5

// Use a custom structure to share data between threads
typedef struct {
    int id;
    double balance;
} Account;

// Mutex to protect balance during deposits and withdrawals
pthread_mutex_t mutex;

// Thread function to deposit money into an account
void *deposit(void *acc) {
    Account *account = (Account*) acc;
    double amount = (double) rand() / RAND_MAX * 1000;
    pthread_mutex_lock(&mutex);
    account->balance += amount;
    printf("Thread %d deposited $%.2f, new balance is $%.2f\n",
        account->id, amount, account->balance);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

// Thread function to withdraw money from an account
void *withdraw(void *acc) {
    Account *account = (Account*) acc;
    double amount = (double) rand() / RAND_MAX * 500;
    pthread_mutex_lock(&mutex);
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Thread %d withdrew $%.2f, new balance is $%.2f\n",
            account->id, amount, account->balance);
    } else {
        printf("Thread %d tried to withdraw $%.2f, insufficient funds ($%.2f)\n",
            account->id, amount, account->balance);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    Account accounts[THREADS];
    int i;
    pthread_mutex_init(&mutex, NULL);
    // Initialize accounts with random starting balance
    for (i = 0; i < THREADS; i++) {
        accounts[i].id = i;
        accounts[i].balance = (double) rand() / RAND_MAX * 5000;
    }
    // Create deposit and withdrawal threads
    for (i = 0; i < THREADS; i += 2) {
        pthread_create(&threads[i], NULL, deposit, &accounts[i]);
        pthread_create(&threads[i+1], NULL, withdraw, &accounts[i+1]);
    }
    // Wait for threads to finish
    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}