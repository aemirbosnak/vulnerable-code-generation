//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

// Define the account structure
typedef struct account {
    int id;
    float balance;
    pthread_mutex_t lock;
} account_t;

// Define the bank structure
typedef struct bank {
    account_t *accounts;
    int num_accounts;
    pthread_mutex_t lock;
} bank_t;

// Create a new bank
bank_t *bank_create(int num_accounts) {
    bank_t *bank = malloc(sizeof(bank_t));
    bank->accounts = malloc(sizeof(account_t) * num_accounts);
    bank->num_accounts = num_accounts;
    pthread_mutex_init(&bank->lock, NULL);
    for (int i = 0; i < num_accounts; i++) {
        bank->accounts[i].id = i;
        bank->accounts[i].balance = 0.0f;
        pthread_mutex_init(&bank->accounts[i].lock, NULL);
    }
    return bank;
}

// Destroy a bank
void bank_destroy(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        pthread_mutex_destroy(&bank->accounts[i].lock);
    }
    pthread_mutex_destroy(&bank->lock);
    free(bank->accounts);
    free(bank);
}

// Get the balance of an account
float account_get_balance(bank_t *bank, int account_id) {
    pthread_mutex_lock(&bank->accounts[account_id].lock);
    float balance = bank->accounts[account_id].balance;
    pthread_mutex_unlock(&bank->accounts[account_id].lock);
    return balance;
}

// Deposit money into an account
void account_deposit(bank_t *bank, int account_id, float amount) {
    pthread_mutex_lock(&bank->accounts[account_id].lock);
    bank->accounts[account_id].balance += amount;
    pthread_mutex_unlock(&bank->accounts[account_id].lock);
}

// Withdraw money from an account
void account_withdraw(bank_t *bank, int account_id, float amount) {
    pthread_mutex_lock(&bank->accounts[account_id].lock);
    if (bank->accounts[account_id].balance >= amount) {
        bank->accounts[account_id].balance -= amount;
    }
    pthread_mutex_unlock(&bank->accounts[account_id].lock);
}

// Transfer money from one account to another
void account_transfer(bank_t *bank, int from_account_id, int to_account_id, float amount) {
    pthread_mutex_lock(&bank->accounts[from_account_id].lock);
    pthread_mutex_lock(&bank->accounts[to_account_id].lock);
    if (bank->accounts[from_account_id].balance >= amount) {
        bank->accounts[from_account_id].balance -= amount;
        bank->accounts[to_account_id].balance += amount;
    }
    pthread_mutex_unlock(&bank->accounts[to_account_id].lock);
    pthread_mutex_unlock(&bank->accounts[from_account_id].lock);
}

// Create a new thread to perform a banking operation
void *banking_operation(void *args) {
    bank_t *bank = (bank_t *)args;

    // Get the operation type
    int operation_type = rand() % 4;

    // Get the account IDs
    int account_id1 = rand() % bank->num_accounts;
    int account_id2 = rand() % bank->num_accounts;

    // Get the amount
    float amount = (float)(rand() % 1000) / 100.0f;

    // Perform the operation
    switch (operation_type) {
        case 0:
            account_deposit(bank, account_id1, amount);
            break;
        case 1:
            account_withdraw(bank, account_id1, amount);
            break;
        case 2:
            account_transfer(bank, account_id1, account_id2, amount);
            break;
        case 3:
            account_get_balance(bank, account_id1);
            break;
    }

    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    // Create a new bank
    bank_t *bank = bank_create(10);

    // Create a thread pool
    pthread_t threads[10];

    // Create the threads
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, banking_operation, bank);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the bank
    bank_destroy(bank);

    return 0;
}