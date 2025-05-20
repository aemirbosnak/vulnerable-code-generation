//Gemma-7B DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
    struct Node* next;
    char* data;
} Node;

Node* head = NULL;

void insert(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = strdup(data);
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
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert("John");
    insert("Mary");
    insert("Bob");

    traverse();

    free(head);
    head = NULL;

    insert("Alice");
    insert("Tom");

    traverse();

    return 0;
}