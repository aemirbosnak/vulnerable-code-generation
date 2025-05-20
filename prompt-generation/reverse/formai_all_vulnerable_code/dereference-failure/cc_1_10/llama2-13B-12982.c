//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdlib.h>
#include <stdio.h>

#define MAGIC_NUMBER 42

struct Node {
    int data;
    struct Node* next;
};

void* mem_alloc(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return mem;
}

void mem_free(void* mem) {
    free(mem);
    printf("Memory freed: %p\n", mem);
}

int main() {
    struct Node* head = NULL;

    // Create a linked list of integers
    for (int i = 0; i < 10; i++) {
        struct Node* new_node = mem_alloc(sizeof(struct Node));
        new_node->data = i * MAGIC_NUMBER;
        new_node->next = head;
        head = new_node;
    }

    // Double the size of the linked list
    for (int i = 0; i < 10; i++) {
        struct Node* new_node = mem_alloc(sizeof(struct Node));
        new_node->data = head->data * MAGIC_NUMBER;
        new_node->next = head->next;
        head->next = new_node;
        head = new_node;
    }

    // Free the memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        mem_free(temp);
    }

    return 0;
}