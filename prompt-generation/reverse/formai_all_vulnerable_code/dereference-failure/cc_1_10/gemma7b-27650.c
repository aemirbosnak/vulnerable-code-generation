//Gemma-7B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct MemoryManager {
    Node* head;
    int size;
    int capacity;
} MemoryManager;

MemoryManager* createMemoryManager(int capacity) {
    MemoryManager* manager = malloc(sizeof(MemoryManager));
    manager->head = NULL;
    manager->size = 0;
    manager->capacity = capacity;
    return manager;
}

void addToMemoryManager(MemoryManager* manager, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (manager->head == NULL) {
        manager->head = newNode;
    } else {
        manager->head->next = newNode;
    }

    manager->size++;
}

void freeMemoryManager(MemoryManager* manager) {
    Node* current = manager->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    free(manager);
}

int main() {
    MemoryManager* manager = createMemoryManager(10);
    addToMemoryManager(manager, 10);
    addToMemoryManager(manager, 20);
    addToMemoryManager(manager, 30);

    freeMemoryManager(manager);

    return 0;
}