//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMORY_SIZE 10

struct MemoryItem {
    char data[MAX_MEMORY_SIZE];
    struct MemoryItem* next;
};

typedef struct MemoryItem MemoryItem;

void initializeMemory(MemoryItem** head) {
    *head = NULL;
}

void addMemoryItem(MemoryItem** head, char* data) {
    MemoryItem* new_item = malloc(sizeof(MemoryItem));
    new_item->next = NULL;
    memcpy(new_item->data, data, MAX_MEMORY_SIZE);

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

int searchMemory(MemoryItem* head, char* data) {
    for (MemoryItem* item = head; item; item = item->next) {
        if (memcmp(item->data, data, MAX_MEMORY_SIZE) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    MemoryItem* head = NULL;
    initializeMemory(&head);

    // Add some memory items
    addMemoryItem(&head, "abc");
    addMemoryItem(&head, "123");
    addMemoryItem(&head, "xyz");

    // Search for a memory item
    if (searchMemory(head, "123")) {
        printf("Item found!\n");
    } else {
        printf("Item not found.\n");
    }

    return 0;
}