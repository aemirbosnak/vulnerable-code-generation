//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct {
    int account_number;
    float balance;
} Account;

typedef struct {
    Account *accounts;
    int num_accounts;
    pthread_mutex_t lock;
} Bank;

void* create_account(void* arg) {
    Bank *bank = (Bank*)arg;
    int i;
    for (i=0; i<NUM_THREADS; i++) {
        Account account;
        account.account_number = i+1;
        account.balance = 0.0f;
        bank->accounts[i] = account;
    }
    return NULL;
}

void* deposit(void* arg) {
    Bank *bank = (Bank*)arg;
    int i;
    for (i=0; i<NUM_THREADS; i++) {
        Account account = bank->accounts[i];
        float amount = (float)rand() / RAND_MAX * 100;
        account.balance += amount;
        printf("Deposited $%.2f to account %d\n", amount, account.account_number);
    }
    return NULL;
}

void* withdraw(void* arg) {
    Bank *bank = (Bank*)arg;
    int i;
    for (i=0; i<NUM_THREADS; i++) {
        Account account = bank->accounts[i];
        float amount = (float)rand() / RAND_MAX * 100;
        if (account.balance >= amount) {
            account.balance -= amount;
            printf("Withdrew $%.2f from account %d\n", amount, account.account_number);
        }
    }
    return NULL;
}

void* print_balance(void* arg) {
    Bank *bank = (Bank*)arg;
    int i;
    for (i=0; i<NUM_THREADS; i++) {
        Account account = bank->accounts[i];
        printf("Account %d has $%.2f balance\n", account.account_number, account.balance);
    }
    return NULL;
}

int main() {
    Bank bank;
    bank.num_accounts = NUM_THREADS;
    bank.accounts = malloc(sizeof(Account)*NUM_THREADS);
    pthread_mutex_init(&bank.lock, NULL);
    pthread_t threads[NUM_THREADS];
    int i;
    for (i=0; i<NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, create_account, (void*)&bank);
    }
    for (i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_lock(&bank.lock);
    print_balance((void*)&bank);
    pthread_mutex_unlock(&bank.lock);
    return 0;
}