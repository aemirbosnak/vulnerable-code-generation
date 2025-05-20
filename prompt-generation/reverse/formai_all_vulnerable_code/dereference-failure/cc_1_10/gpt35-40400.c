//FormAI DATASET v1.0 Category: Data recovery tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DataBlock {
    int id;
    char data[512];
    struct DataBlock* next;
};

// function to append a new block
void appendBlock(struct DataBlock** headRef, int id, char* data) {
    struct DataBlock* newBlock = (struct DataBlock*)malloc(sizeof(struct DataBlock));
    newBlock->id = id;
    strcpy(newBlock->data, data);
    newBlock->next = NULL;
    struct DataBlock* lastBlock = *headRef;
    if (*headRef == NULL) {
        *headRef = newBlock;
        return;
    }
    while (lastBlock->next != NULL) {
        lastBlock = lastBlock->next;
    }
    lastBlock->next = newBlock;
}

// function to traverse the linked list and print the blocks
void printBlocks(struct DataBlock* head) {
    while (head != NULL) {
        printf("Block ID: %d\n", head->id);
        printf("Data: %s\n", head->data);
        head = head->next;
    }
}

// function to search for a particular block by id
struct DataBlock* searchBlock(struct DataBlock* head, int id) {
    struct DataBlock* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// function to delete a block by id
void deleteBlock(struct DataBlock** headRef, int id) {
    struct DataBlock* temp = *headRef, *prev;
    if (temp != NULL && temp->id == id) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    struct DataBlock* head = NULL;

    // Adding blocks
    appendBlock(&head, 1, "Hello World!");
    appendBlock(&head, 2, "This is a test.");
    appendBlock(&head, 3, "How are you?");

    // Printing blocks
    printf("All blocks:\n");
    printBlocks(head);

    // Searching for a block
    printf("\nBlock with ID 2:\n");
    struct DataBlock* block = searchBlock(head, 2);
    if (block != NULL) {
        printf("Block found.\n");
        printf("Data: %s\n", block->data);
    }
    else {
        printf("Block not found.\n");
    }

    // Deleting a block
    printf("\nDeleting block with ID 2.\n");
    deleteBlock(&head, 2);
    printf("All blocks after deletion:\n");
    printBlocks(head);

    return 0;
}