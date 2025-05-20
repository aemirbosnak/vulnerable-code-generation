//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int compress(Node* head) {
    int size = 0;
    Node* current = head;

    while (current) {
        size++;
        current = current->next;
    }

    int blocks = size / MAX_SIZE + 1;
    int offset = size % MAX_SIZE;

    head = malloc(blocks * sizeof(Node));

    current = head;
    current->data = offset;

    int i = 0;
    while (i < blocks - 1) {
        current->next = malloc(MAX_SIZE * sizeof(Node));
        current = current->next;
        current->data = i + 1;
        i++;
    }

    current->next = NULL;

    return blocks;
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 1;

    head->next = malloc(sizeof(Node));
    head->next->data = 2;

    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 3;

    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 4;

    int blocks = compress(head);

    printf("Number of blocks: %d\n", blocks);

    return 0;
}