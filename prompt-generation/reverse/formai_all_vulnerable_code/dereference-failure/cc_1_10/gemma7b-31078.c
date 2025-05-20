//Gemma-7B DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdlib.h>
#include <stdio.h>

#define MAX_ALLOC 10

typedef struct Node {
    struct Node* next;
    int data;
} Node;

Node* head = NULL;

void insert(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }
}

void traverse() {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    traverse();

    free(head);
    head = NULL;

    insert(50);
    insert(60);

    traverse();

    return 0;
}