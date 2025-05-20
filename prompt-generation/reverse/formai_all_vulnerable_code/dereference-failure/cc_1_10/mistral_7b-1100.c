//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define TURING_SIZE 1000

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *current = NULL;

void allocateMemory(int size) {
    void *memory = malloc(size);

    if (memory == NULL) {
        printf("Error: Insufficient memory.\n");
        exit(1);
    }

    printf("Successfully allocated memory of size %d bytes at address %p.\n", size, memory);
}

void freeMemory(void *ptr) {
    free(ptr);

    printf("Successfully freed memory at address %p.\n", ptr);
}

void initializeList() {
    head = (Node *) malloc(sizeof(Node));

    if (head == NULL) {
        printf("Error: Insufficient memory.\n");
        exit(1);
    }

    head->data = 0;
    head->next = NULL;
    tail = head;
}

void appendToList(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Error: Insufficient memory.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    tail->next = newNode;
    tail = newNode;
}

void printList() {
    current = head;

    printf("List contents:\n");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int i;

    allocateMemory(sizeof(int) * TURING_SIZE);

    initializeList();

    for (i = 0; i < TURING_SIZE; i++) {
        appendToList(i);
    }

    printList();

    while (head != NULL) {
        current = head;
        head = head->next;
        freeMemory(current);
    }

    freeMemory(head);

    printf("Successfully freed all allocated memory.\n");

    return 0;
}