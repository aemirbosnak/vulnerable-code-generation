//FormAI DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structs for transaction and block
typedef struct {
    int amount;
    char sender[20];
    char receiver[20];
} Transaction;

typedef struct {
    int index;
    char prevHash[65];
    char currHash[65];
    Transaction* transactions[10];
    int numTransactions;
} Block;

// function to calculate hash value of a block
// using SHA-256 algorithm
char* calculateHash(Block* block) {
    // implementation details
}

int main() {
    // initialize blockchain
    int numBlocks = 0;
    Block* blockchain[50];

    // initialize genesis block
    Block* genesis = malloc(sizeof(Block));
    strcpy(genesis->prevHash, "");
    genesis->index = 0;
    genesis->numTransactions = 0;
    blockchain[numBlocks++] = genesis;

    // prompt user for transactions
    Transaction* tx;
    char choice = 'y';
    while (choice == 'y') {
        tx = malloc(sizeof(Transaction));
        printf("Enter amount: ");
        scanf("%d", &tx->amount);
        printf("Enter sender name: ");
        scanf("%s", tx->sender);
        printf("Enter receiver name: ");
        scanf("%s", tx->receiver);

        // create new block and add transaction
        Block* newBlock = malloc(sizeof(Block));
        newBlock->index = numBlocks;
        strcpy(newBlock->prevHash, blockchain[numBlocks-1]->currHash);
        newBlock->numTransactions = 1;
        newBlock->transactions[0] = tx;

        // calculate hash of new block and add to blockchain
        strcpy(newBlock->currHash, calculateHash(newBlock));
        blockchain[numBlocks++] = newBlock;

        printf("Do you want to add another transaction? (y/n): ");
        scanf(" %c", &choice);
    }

    // print out all blocks in blockchain
    printf("Blockchain:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block #%d\n", i);
        printf("\tIndex: %d\n", blockchain[i]->index);
        printf("\tPrevious Hash: %s\n", blockchain[i]->prevHash);
        printf("\tCurrent Hash: %s\n", blockchain[i]->currHash);
        printf("\tTransactions:\n");

        for (int j = 0; j < blockchain[i]->numTransactions; j++) {
            printf("\t\tAmount: %d\n", blockchain[i]->transactions[j]->amount);
            printf("\t\tSender: %s\n", blockchain[i]->transactions[j]->sender);
            printf("\t\tReceiver: %s\n", blockchain[i]->transactions[j]->receiver);
        }
    }

    return 0;
}