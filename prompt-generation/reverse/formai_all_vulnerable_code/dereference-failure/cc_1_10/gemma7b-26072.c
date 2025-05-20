//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 4096

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void compress(Node* head) {
    Node* current = head;
    int count = 0;
    int previousData = -1;
    Node* previousNode = NULL;

    while (current) {
        if (previousData == current->data) {
            count++;
        } else {
            if (previousNode) {
                previousNode->next = malloc(sizeof(Node));
                previousNode->next->data = count;
                previousNode->next->next = NULL;
            }
            previousData = current->data;
            count = 1;
            previousNode = current;
        }
        current = current->next;
    }

    if (previousNode) {
        previousNode->next = malloc(sizeof(Node));
        previousNode->next->data = count;
        previousNode->next->next = NULL;
    }
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 1;

    head->next = malloc(sizeof(Node));
    head->next->data = 1;

    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 2;

    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 2;

    head->next->next->next->next = malloc(sizeof(Node));
    head->next->next->next->next->data = 3;

    compress(head);

    return 0;
}