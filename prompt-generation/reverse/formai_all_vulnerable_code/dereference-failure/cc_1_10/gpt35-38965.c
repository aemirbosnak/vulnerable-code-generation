//FormAI DATASET v1.0 Category: Banking Record System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a structure for a bank account
typedef struct {
    int account_number;
    double balance;
    pthread_mutex_t lock;
} Account;

// Define an enum for transaction types
typedef enum {
    DEPOSIT,
    WITHDRAW
} Transaction_Type;

// Define a structure for a transaction
typedef struct {
    Account *account;
    Transaction_Type type;
    double amount;
} Transaction;

// Function to create a new account
Account *create_account(int account_number, double balance) {
    Account *account = malloc(sizeof(Account));
    account->account_number = account_number;
    account->balance = balance;
    pthread_mutex_init(&account->lock, NULL);
    return account;
}

// Function to make a deposit or withdrawal
void *make_transaction(void *arg) {
    Transaction *transaction = (Transaction*)arg;
    pthread_mutex_lock(&transaction->account->lock);
    if (transaction->type == DEPOSIT) {
        transaction->account->balance += transaction->amount;
    } else if (transaction->type == WITHDRAW) {
        transaction->account->balance -= transaction->amount;
    }
    printf("Account %d balance: $%.2f\n", transaction->account->account_number, transaction->account->balance);
    pthread_mutex_unlock(&transaction->account->lock);
    return NULL;
}

int main() {
    // Create two bank accounts
    Account *account1 = create_account(1001, 5000);
    Account *account2 = create_account(1002, 3000);

    // Create two deposit transactions
    Transaction deposit1 = {account1, DEPOSIT, 1000};
    Transaction deposit2 = {account2, DEPOSIT, 500};

    // Create two withdrawal transactions
    Transaction withdrawal1 = {account1, WITHDRAW, 200};
    Transaction withdrawal2 = {account2, WITHDRAW, 400};

    // Create four threads to execute the transactions
    pthread_t threads[4];
    pthread_create(&threads[0], NULL, make_transaction, &deposit1);
    pthread_create(&threads[1], NULL, make_transaction, &deposit2);
    pthread_create(&threads[2], NULL, make_transaction, &withdrawal1);
    pthread_create(&threads[3], NULL, make_transaction, &withdrawal2);

    // Wait for all threads to finish
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the memory used by the accounts
    free(account1);
    free(account2);

    return 0;
}