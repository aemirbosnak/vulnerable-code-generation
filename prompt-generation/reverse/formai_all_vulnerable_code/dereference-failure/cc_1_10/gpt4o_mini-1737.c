//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5
#define NUM_TRANSACTIONS 10
#define INITIAL_BALANCE 1000

typedef struct {
    int thread_id;
    int transaction_type; // 0 for deposit, 1 for withdrawal
    int amount;
} Transaction;

typedef struct {
    int balance;
    pthread_mutex_t mutex;
} BankAccount;

BankAccount account;

void* performTransaction(void* arg) {
    Transaction* transaction = (Transaction*)arg;

    // Lock the mutex to ensure thread-safe access to the bank account
    pthread_mutex_lock(&account.mutex);

    if (transaction->transaction_type == 0) {
        printf("Thread %d is depositing %d. Initial balance: %d\n", 
                transaction->thread_id, 
                transaction->amount, 
                account.balance);
        account.balance += transaction->amount;
        printf("Thread %d completed deposit. New balance: %d\n", 
                transaction->thread_id, 
                account.balance);
    } else {
        if (account.balance >= transaction->amount) {
            printf("Thread %d is withdrawing %d. Initial balance: %d\n", 
                   transaction->thread_id, 
                   transaction->amount, 
                   account.balance);
            account.balance -= transaction->amount;
            printf("Thread %d completed withdrawal. New balance: %d\n", 
                   transaction->thread_id, 
                   account.balance);
        } else {
            printf("Thread %d attempted to withdraw %d but insufficient funds. Balance: %d\n", 
                    transaction->thread_id, 
                    transaction->amount, 
                    account.balance);
        }
    }

    // Unlock the mutex
    pthread_mutex_unlock(&account.mutex);

    free(transaction);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Initialize the bank account and mutex
    account.balance = INITIAL_BALANCE;
    pthread_mutex_init(&account.mutex, NULL);

    // Create threads for transactions
    for (int i = 0; i < NUM_THREADS; i++) {
        Transaction* transaction = malloc(sizeof(Transaction));
        transaction->thread_id = i;
        transaction->transaction_type = rand() % 2; // Randomly select deposit (0) or withdrawal (1)
        transaction->amount = (rand() % 200) + 1; // Amount between 1 and 200

        if (pthread_create(&threads[i], NULL, performTransaction, transaction) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            free(transaction);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
        }
    }

    // Clean up
    pthread_mutex_destroy(&account.mutex);
    printf("Final balance: %d\n", account.balance);
    return 0;
}