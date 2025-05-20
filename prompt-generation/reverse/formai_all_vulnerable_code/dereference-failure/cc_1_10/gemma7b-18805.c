//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC 10

typedef struct Node {
    struct Node* next;
    int data;
} Node;

Node* head = NULL;

void allocate(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }
}

void freeNode(int data) {
    Node* prev = NULL;
    Node* current = head;

    while (current) {
        if (current->data == data) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Error: Node not found.\n");
}

int main() {
    allocate(10);
    allocate(20);
    allocate(30);

    freeNode(20);

    printf("Head: %p\n", head);

    return 0;
}