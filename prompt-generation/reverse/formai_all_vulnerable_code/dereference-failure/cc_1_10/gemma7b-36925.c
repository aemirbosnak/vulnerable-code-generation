//Gemma-7B DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct MemoryManager {
    Node** head;
    int size;
} MemoryManager;

MemoryManager* mm_init(int size) {
    MemoryManager* mm = (MemoryManager*)malloc(sizeof(MemoryManager));
    mm->head = NULL;
    mm->size = size;
    return mm;
}

void mm_insert(MemoryManager* mm, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (mm->head == NULL) {
        mm->head = newNode;
    } else {
        Node* tail = mm->head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void mm_free(MemoryManager* mm, int data) {
    Node* node = mm->head;
    while (node) {
        if (node->data == data) {
            free(node);
            node = NULL;
        } else {
            node = node->next;
        }
    }
}

int main() {
    MemoryManager* mm = mm_init(MAX_SIZE);
    mm_insert(mm, 10);
    mm_insert(mm, 20);
    mm_insert(mm, 30);
    mm_insert(mm, 40);
    mm_insert(mm, 50);
    mm_free(mm, 30);
    mm_free(mm, 20);

    return 0;
}