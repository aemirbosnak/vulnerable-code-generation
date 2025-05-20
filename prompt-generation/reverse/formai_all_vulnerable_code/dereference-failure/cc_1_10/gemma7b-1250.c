//Gemma-7B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct MemoryManager {
    Node* head;
    Node* tail;
    int size;
    int capacity;
};

void* mm_alloc(struct MemoryManager* mm, int size) {
    if (mm->size == mm->capacity) {
        return NULL;
    }

    Node* newNode = (Node*)malloc(sizeof(Node) + size);
    newNode->data = 0;
    newNode->next = NULL;

    if (mm->head == NULL) {
        mm->head = newNode;
        mm->tail = newNode;
    } else {
        mm->tail->next = newNode;
        mm->tail = newNode;
    }

    mm->size++;

    return (void*)newNode;
}

void mm_free(struct MemoryManager* mm, void* ptr) {
    Node* node = (Node*)ptr;

    if (node == mm->head) {
        mm->head = node->next;
    } else {
        Node* previous = mm->head;
        while (previous->next != node) {
            previous = previous->next;
        }
        previous->next = node->next;
    }

    free(node);
    mm->size--;
}

int main() {
    struct MemoryManager* mm = malloc(sizeof(struct MemoryManager));
    mm->size = 0;
    mm->capacity = 10;
    mm->head = NULL;
    mm->tail = NULL;

    void* ptr1 = mm_alloc(mm, 20);
    void* ptr2 = mm_alloc(mm, 30);
    void* ptr3 = mm_alloc(mm, 40);

    mm_free(mm, ptr2);

    printf("Size: %d\n", mm->size);

    return 0;
}