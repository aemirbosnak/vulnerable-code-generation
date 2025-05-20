//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define RAM_SIZE 1024

typedef struct MemoryBlock {
    int data[RAM_SIZE];
    struct MemoryBlock* next;
} MemoryBlock;

MemoryBlock* head = NULL;

void addToRam(int data) {
    MemoryBlock* newBlock = malloc(sizeof(MemoryBlock));
    newBlock->data[0] = data;
    newBlock->next = NULL;

    if (head == NULL) {
        head = newBlock;
    } else {
        head->next = newBlock;
        head = newBlock;
    }
}

void ramUsage() {
    MemoryBlock* currentBlock = head;
    int usedRam = 0;

    while (currentBlock) {
        for (int i = 0; i < RAM_SIZE; i++) {
            if (currentBlock->data[i] != 0) {
                usedRam++;
            }
        }
        currentBlock = currentBlock->next;
    }

    printf("Used RAM: %d/%d\n", usedRam, RAM_SIZE);
}

int main() {
    addToRam(10);
    addToRam(20);
    addToRam(30);
    addToRam(40);

    ramUsage();

    return 0;
}