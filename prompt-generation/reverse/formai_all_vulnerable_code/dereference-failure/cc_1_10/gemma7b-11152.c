//Gemma-7B DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    void* data;
} Node;

typedef struct MemoryManager {
    Node* head;
    int size;
    int capacity;
} MemoryManager;

MemoryManager* mem_manager_init(int capacity) {
    MemoryManager* manager = malloc(sizeof(MemoryManager));
    manager->head = NULL;
    manager->size = 0;
    manager->capacity = capacity;
    return manager;
}

void mem_manager_insert(MemoryManager* manager, void* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = manager->head;
    manager->head = newNode;
    manager->size++;
}

void mem_manager_free(MemoryManager* manager, void* data) {
    Node* prev = NULL;
    Node* current = manager->head;
    while (current) {
        if (current->data == data) {
            if (prev) {
                prev->next = current->next;
            } else {
                manager->head = current->next;
            }
            free(current);
            manager->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
    return;
}

int main() {
    MemoryManager* manager = mem_manager_init(10);
    mem_manager_insert(manager, "a");
    mem_manager_insert(manager, "b");
    mem_manager_insert(manager, "c");
    mem_manager_free(manager, "b");
    mem_manager_free(manager, "a");
    mem_manager_free(manager, "c");
    return 0;
}