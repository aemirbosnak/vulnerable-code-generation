//Gemma-7B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct MemoryManager {
    Node* head;
    Node* tail;
    int size;
    int capacity;
} MemoryManager;

MemoryManager* createManager(int capacity) {
    MemoryManager* manager = (MemoryManager*)malloc(sizeof(MemoryManager));
    manager->head = NULL;
    manager->tail = NULL;
    manager->size = 0;
    manager->capacity = capacity;

    return manager;
}

void addToManager(MemoryManager* manager, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (manager->head == NULL) {
        manager->head = newNode;
        manager->tail = newNode;
    } else {
        manager->tail->next = newNode;
        manager->tail = newNode;
    }

    manager->size++;
}

void freeManager(MemoryManager* manager) {
    Node* current = manager->head;
    Node* next = NULL;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }

    free(manager);
}

int main() {
    MemoryManager* manager = createManager(10);

    addToManager(manager, 10);
    addToManager(manager, 20);
    addToManager(manager, 30);
    addToManager(manager, 40);

    freeManager(manager);

    return 0;
}