//Gemma-7B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdlib.h>

#define MAX_ALLOCATIONS 10

typedef struct Node {
    struct Node* next;
    void* data;
} Node;

void* my_malloc(int size) {
    Node* newNode = NULL;

    if (size <= 0) {
        return NULL;
    }

    if (newNode == NULL) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->data = malloc(size);
    } else {
        newNode->next = (Node*)malloc(sizeof(Node));
        newNode->next->next = NULL;
        newNode->next->data = malloc(size);
    }

    return newNode->data;
}

void my_free(void* ptr) {
    Node* current = NULL;
    Node* previous = NULL;

    if (ptr == NULL) {
        return;
    }

    current = (Node*)ptr;

    if (previous == NULL) {
        free(current->data);
        free(current);
    } else {
        free(current->data);
        free(current);
        previous->next = current->next;
    }
}

int main() {
    void* test_ptr = my_malloc(10);
    my_free(test_ptr);

    return 0;
}