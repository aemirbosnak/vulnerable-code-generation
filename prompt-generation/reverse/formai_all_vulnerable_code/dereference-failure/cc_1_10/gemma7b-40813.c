//Gemma-7B DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct MemMan {
    Node* head;
    int size;
    int alloc_size;
} MemMan;

MemMan* mem_manager_init(int size) {
    MemMan* mem_manager = malloc(sizeof(MemMan));
    mem_manager->head = NULL;
    mem_manager->size = size;
    mem_manager->alloc_size = 0;
    return mem_manager;
}

void mem_manager_insert(MemMan* mem_manager, void* data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = mem_manager->head;
    mem_manager->head = new_node;
    mem_manager->alloc_size++;
}

void mem_manager_free(MemMan* mem_manager, void* data) {
    Node* prev_node = NULL;
    Node* current_node = mem_manager->head;
    while (current_node) {
        if (current_node->data == data) {
            if (prev_node) {
                prev_node->next = current_node->next;
            } else {
                mem_manager->head = current_node->next;
            }
            free(current_node);
            mem_manager->alloc_size--;
            return;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
    return;
}

int main() {
    MemMan* mem_manager = mem_manager_init(MAX_SIZE);

    void* data1 = malloc(10);
    mem_manager_insert(mem_manager, data1);

    void* data2 = malloc(20);
    mem_manager_insert(mem_manager, data2);

    mem_manager_free(mem_manager, data1);

    void* data3 = malloc(30);
    mem_manager_insert(mem_manager, data3);

    mem_manager_free(mem_manager, data2);

    printf("Number of allocated nodes: %d\n", mem_manager->alloc_size);

    return 0;
}