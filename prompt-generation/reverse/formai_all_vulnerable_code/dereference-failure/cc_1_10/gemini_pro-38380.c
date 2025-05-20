//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare the blockchain
struct Blockchain {
    int size;
    struct Block *head;
};

// Declare the block
struct Block {
    int index;
    char *timestamp;
    char *data;
    struct Block *previous;
};

// Create a new blockchain
struct Blockchain *create_blockchain() {
    struct Blockchain *blockchain = (struct Blockchain *)malloc(sizeof(struct Blockchain));
    blockchain->size = 0;
    blockchain->head = NULL;
    return blockchain;
}

// Create a new block
struct Block *create_block(char *data) {
    struct Block *block = (struct Block *)malloc(sizeof(struct Block));
    block->index = 0;
    block->timestamp = (char *)malloc(sizeof(time_t));
    time_t t = time(NULL);
    strftime(block->timestamp, sizeof(time_t), "%Y-%m-%d %H:%M:%S", localtime(&t));
    block->data = (char *)malloc(strlen(data) + 1);
    strcpy(block->data, data);
    block->previous = NULL;
    return block;
}

// Add a block to the blockchain
void add_block(struct Blockchain *blockchain, struct Block *block) {
    if (blockchain->size == 0) {
        blockchain->head = block;
    } else {
        block->previous = blockchain->head;
        blockchain->head = block;
    }
    blockchain->size++;
}

// Print the blockchain
void print_blockchain(struct Blockchain *blockchain) {
    struct Block *current_block = blockchain->head;
    while (current_block != NULL) {
        printf("Block %d:\n", current_block->index);
        printf("Timestamp: %s\n", current_block->timestamp);
        printf("Data: %s\n", current_block->data);
        printf("Previous Hash: %s\n", current_block->previous == NULL ? "NULL" : current_block->previous->data);
        printf("\n");
        current_block = current_block->previous;
    }
}

// Main function
int main() {
    // Create a new blockchain
    struct Blockchain *blockchain = create_blockchain();

    // Add some blocks to the blockchain
    add_block(blockchain, create_block("Hello, world!"));
    add_block(blockchain, create_block("This is a decentralized digital diary."));
    add_block(blockchain, create_block("I can write anything I want here."));

    // Print the blockchain
    print_blockchain(blockchain);

    return 0;
}