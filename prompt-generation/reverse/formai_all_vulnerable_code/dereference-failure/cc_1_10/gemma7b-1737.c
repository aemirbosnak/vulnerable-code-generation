//Gemma-7B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct MemMan {
    Node* head;
    int size;
    int alloc_size;
    int used_size;
} MemMan;

MemMan* mem_manager(int size) {
    MemMan* mem = (MemMan*)malloc(sizeof(MemMan));
    mem->head = NULL;
    mem->size = size;
    mem->alloc_size = 0;
    mem->used_size = 0;
    return mem;
}

void insert(MemMan* mem, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (mem->head == NULL) {
        mem->head = new_node;
    } else {
        mem->head->next = new_node;
    }

    mem->alloc_size++;
    mem->used_size++;
}

void print_list(MemMan* mem) {
    Node* current = mem->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    MemMan* mem = mem_manager(10);

    insert(mem, 10);
    insert(mem, 20);
    insert(mem, 30);
    insert(mem, 40);
    insert(mem, 50);

    print_list(mem);

    free(mem);
    return 0;
}