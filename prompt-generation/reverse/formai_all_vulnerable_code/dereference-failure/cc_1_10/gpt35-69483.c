//FormAI DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define struct to store transaction data
typedef struct Transaction {
    int id;
    char* sender;
    char* receiver;
    float amount;
} Transaction;

// Define function to create a new transaction
Transaction* createTransaction(int id, char* sender, char* receiver, float amount) {
    Transaction* transaction = (Transaction*)malloc(sizeof(Transaction));
    transaction->id = id;
    transaction->sender = sender;
    transaction->receiver = receiver;
    transaction->amount = amount;
    return transaction;
}

int main() {
    // Initialize seed for random number generator
    srand(time(NULL));

    // Initialize array to store transactions
    Transaction* transactions[5];

    // Generate 5 random transactions
    for (int i = 0; i < 5; i++) {
        int id = i + 1;
        char* sender = "Alice";
        char* receiver = "Bob";
        float amount = (float)(rand() % 1000) / 100;
        transactions[i] = createTransaction(id, sender, receiver, amount);
    }

    // Print out each transaction
    for (int i = 0; i < 5; i++) {
        Transaction* transaction = transactions[i];
        printf("Transaction %d: %s sent %.2f ETH to %s\n", transaction->id, transaction->sender, transaction->amount, transaction->receiver);
    }

    // Free memory used for transactions
    for (int i = 0; i < 5; i++) {
        free(transactions[i]);
    }

    return 0;
}