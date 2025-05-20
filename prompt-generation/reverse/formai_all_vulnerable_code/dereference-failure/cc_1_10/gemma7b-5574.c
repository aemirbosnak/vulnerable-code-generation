//Gemma-7B DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdlib.h>

#define MAX_ALLOCATIONS 10

typedef struct Node {
    struct Node* next;
    void* data;
} Node;

Node* head = NULL;

void* alloc(size_t size) {
    if (head == NULL) {
        head = (Node*)malloc(sizeof(Node));
        head->next = NULL;
        head->data = (void*)malloc(size);
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->next = head;
        head = newNode;
        newNode->data = (void*)malloc(size);
    }

    return head->data;
}

void free(void* ptr) {
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        if (current->data == ptr) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }

            free(current->data);
            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    alloc(10);
    alloc(20);
    alloc(30);

    free(alloc(40));
    free(alloc(50));

    return 0;
}