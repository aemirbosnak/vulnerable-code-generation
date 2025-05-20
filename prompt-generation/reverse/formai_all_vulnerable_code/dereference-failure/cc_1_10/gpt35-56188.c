//FormAI DATASET v1.0 Category: Educational ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

// declaring the struct for decentralized data storage
struct block {
    int data;           // data stored in the block
    struct block *ptr;  // pointer to the next block in the chain
}*head;


// function to add a new block to the chain
void addBlock(int data) {
    struct block *newBlock = malloc(sizeof(struct block));
    newBlock->data = data;
    newBlock->ptr = head;
    head = newBlock;
}

// function to print all the blocks in the chain
void printChain() {
    struct block *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->ptr;
    }
    printf("NULL\n");
}

// function to find the length of the chain
int chainLength() {
    int length = 0;
    struct block *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->ptr;
    }
    return length;
}

int main() {
    // creating a decentralized chain of data blocks
    head = NULL;
    addBlock(10);
    addBlock(20);
    addBlock(30);
    addBlock(40);
    
    // printing the chain
    printf("Decentralized chain of data blocks:\n");
    printChain();
    
    // printing the length of the chain
    int length = chainLength();
    printf("Length of the chain: %d\n", length);
    
    return 0;
}