//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the account structure
typedef struct {
    int balance;
    pthread_mutex_t lock;
} account_t;

// Create an account
account_t* create_account(int initial_balance) {
    account_t* account = malloc(sizeof(account_t));
    account->balance = initial_balance;
    pthread_mutex_init(&account->lock, NULL);
    return account;
}

// Deposit money into an account
void deposit(account_t* account, int amount) {
    pthread_mutex_lock(&account->lock);
    account->balance += amount;
    pthread_mutex_unlock(&account->lock);
}

// Withdraw money from an account
void withdraw(account_t* account, int amount) {
    pthread_mutex_lock(&account->lock);
    if (account->balance >= amount) {
        account->balance -= amount;
    }
    pthread_mutex_unlock(&account->lock);
}

// Get the balance of an account
int get_balance(account_t* account) {
    pthread_mutex_lock(&account->lock);
    int balance = account->balance;
    pthread_mutex_unlock(&account->lock);
    return balance;
}

// Create a thread function to simulate a user making transactions
void* user_thread(void* arg) {
    account_t* account = (account_t*)arg;

    // Simulate 1000 transactions
    for (int i = 0; i < 1000; i++) {
        // Randomly choose whether to deposit or withdraw money
        int amount = rand() % 100;
        if (rand() % 2 == 0) {
            deposit(account, amount);
        } else {
            withdraw(account, amount);
        }
    }

    return NULL;
}

// Main function
int main() {
    // Create an account with an initial balance of $1000
    account_t* account = create_account(1000);

    // Create 10 threads to simulate users making transactions
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, user_thread, (void*)account);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Get the final balance of the account
    int final_balance = get_balance(account);

    // Print the final balance
    printf("Final balance: %d\n", final_balance);

    // Free the account
    free(account);

    return 0;
}