//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Account structure
typedef struct account {
    int account_number;
    double balance;
    pthread_mutex_t lock;
} account_t;

// Bank structure
typedef struct bank {
    int num_accounts;
    account_t* accounts;
    pthread_mutex_t bank_lock;
} bank_t;

// Create a new bank
bank_t* create_bank(int num_accounts) {
    bank_t* bank = malloc(sizeof(bank_t));
    bank->num_accounts = num_accounts;
    bank->accounts = malloc(sizeof(account_t) * num_accounts);
    for (int i = 0; i < num_accounts; i++) {
        bank->accounts[i].account_number = i;
        bank->accounts[i].balance = 0;
        pthread_mutex_init(&bank->accounts[i].lock, NULL);
    }
    pthread_mutex_init(&bank->bank_lock, NULL);
    return bank;
}

// Deposit money into an account
void deposit(bank_t* bank, int account_number, double amount) {
    pthread_mutex_lock(&bank->bank_lock);
    pthread_mutex_lock(&bank->accounts[account_number].lock);
    bank->accounts[account_number].balance += amount;
    pthread_mutex_unlock(&bank->accounts[account_number].lock);
    pthread_mutex_unlock(&bank->bank_lock);
}

// Withdraw money from an account
void withdraw(bank_t* bank, int account_number, double amount) {
    pthread_mutex_lock(&bank->bank_lock);
    pthread_mutex_lock(&bank->accounts[account_number].lock);
    if (bank->accounts[account_number].balance >= amount) {
        bank->accounts[account_number].balance -= amount;
    }
    pthread_mutex_unlock(&bank->accounts[account_number].lock);
    pthread_mutex_unlock(&bank->bank_lock);
}

// Transfer money from one account to another
void transfer(bank_t* bank, int from_account_number, int to_account_number, double amount) {
    pthread_mutex_lock(&bank->bank_lock);
    pthread_mutex_lock(&bank->accounts[from_account_number].lock);
    pthread_mutex_lock(&bank->accounts[to_account_number].lock);
    if (bank->accounts[from_account_number].balance >= amount) {
        bank->accounts[from_account_number].balance -= amount;
        bank->accounts[to_account_number].balance += amount;
    }
    pthread_mutex_unlock(&bank->accounts[to_account_number].lock);
    pthread_mutex_unlock(&bank->accounts[from_account_number].lock);
    pthread_mutex_unlock(&bank->bank_lock);
}

// Get the balance of an account
double get_balance(bank_t* bank, int account_number) {
    pthread_mutex_lock(&bank->bank_lock);
    pthread_mutex_lock(&bank->accounts[account_number].lock);
    double balance = bank->accounts[account_number].balance;
    pthread_mutex_unlock(&bank->accounts[account_number].lock);
    pthread_mutex_unlock(&bank->bank_lock);
    return balance;
}

// Print the balances of all accounts
void print_balances(bank_t* bank) {
    pthread_mutex_lock(&bank->bank_lock);
    for (int i = 0; i < bank->num_accounts; i++) {
        pthread_mutex_lock(&bank->accounts[i].lock);
        printf("Account %d: %.2f\n", bank->accounts[i].account_number, bank->accounts[i].balance);
        pthread_mutex_unlock(&bank->accounts[i].lock);
    }
    pthread_mutex_unlock(&bank->bank_lock);
}

// Destroy a bank
void destroy_bank(bank_t* bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        pthread_mutex_destroy(&bank->accounts[i].lock);
    }
    pthread_mutex_destroy(&bank->bank_lock);
    free(bank->accounts);
    free(bank);
}

int main() {
    // Create a bank with 10 accounts
    bank_t* bank = create_bank(10);

    // Create 10 threads to perform banking operations
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, (void*)deposit, (void*)bank);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the balances of all accounts
    print_balances(bank);

    // Destroy the bank
    destroy_bank(bank);

    return 0;
}