//Gemma-7B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct MemoryManager {
    Node* head;
    int size;
    int capacity;
};

void* mm_alloc(struct MemoryManager* mm, int size) {
    if (mm->size >= mm->capacity) {
        return NULL;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = size;
    newNode->next = mm->head;
    mm->head = newNode;
    mm->size++;

    return (void*)newNode;
}

void mm_free(struct MemoryManager* mm, void* ptr) {
    Node* node = (Node*)ptr;

    if (node == mm->head) {
        mm->head = node->next;
    } else {
        Node* prev = mm->head;
        while (prev->next && prev->next != node) {
            prev = prev->next;
        }

        prev->next = node->next;
    }

    free(node);
    mm->size--;
}

int main() {
    struct MemoryManager* mm = (struct MemoryManager*)malloc(sizeof(struct MemoryManager));
    mm->head = NULL;
    mm->size = 0;
    mm->capacity = 10;

    void* ptr1 = mm_alloc(mm, 20);
    void* ptr2 = mm_alloc(mm, 30);
    void* ptr3 = mm_alloc(mm, 40);

    mm_free(mm, ptr2);

    void* ptr4 = mm_alloc(mm, 50);

    free(mm);

    return 0;
}