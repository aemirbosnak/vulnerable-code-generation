//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CLIENTS 5
#define MAX_TRANSACTIONS 3

typedef struct {
    int client_id;
    double transaction_amount;
} Transaction;

typedef struct {
    double balance;
    pthread_mutex_t lock;
} BankAccount;

BankAccount account;

void* client_actions(void* arg) {
    Transaction* transaction = (Transaction*)arg;
    
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        double amount = transaction->transaction_amount;
        
        // Simulate random transactions
        if (rand() % 2 == 0) { // Deposit
            pthread_mutex_lock(&account.lock);
            account.balance += amount;
            printf("Client %d deposited: $%.2f. New balance: $%.2f\n", 
                   transaction->client_id, amount, account.balance);
            pthread_mutex_unlock(&account.lock);
        } else { // Withdraw
            pthread_mutex_lock(&account.lock);
            if (account.balance >= amount) {
                account.balance -= amount;
                printf("Client %d withdrew: $%.2f. New balance: $%.2f\n", 
                       transaction->client_id, amount, account.balance);
            } else {
                printf("Client %d attempted to withdraw: $%.2f. Insufficient funds. Current balance: $%.2f\n", 
                       transaction->client_id, amount, account.balance);
            }
            pthread_mutex_unlock(&account.lock);
        }
        
        sleep(rand() % 3); // Simulate different transaction times
    }
    
    free(transaction);
    return NULL;
}

int main() {
    srand(time(NULL));
    
    pthread_t clients[MAX_CLIENTS];
    account.balance = 1000.0; // Initial balance
    pthread_mutex_init(&account.lock, NULL);
    
    for (int i = 0; i < MAX_CLIENTS; i++) {
        Transaction* transaction = (Transaction*)malloc(sizeof(Transaction));
        transaction->client_id = i + 1;
        transaction->transaction_amount = (rand() % 100) + 1; // Transaction amount between 1 and 100
        
        if (pthread_create(&clients[i], NULL, client_actions, transaction) != 0) {
            fprintf(stderr, "Error creating thread for client %d\n", i + 1);
            free(transaction);
        }
    }
    
    for (int i = 0; i < MAX_CLIENTS; i++) {
        pthread_join(clients[i], NULL);
    }
    
    printf("Final balance in the account: $%.2f\n", account.balance);
    pthread_mutex_destroy(&account.lock);
    return 0;
}