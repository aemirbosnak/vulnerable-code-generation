//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            insert(previous, count);
            previous = current;
            count = 1;
        }
        current = current->next;
    }

    insert(previous, count);
}

int main() {
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 3);
    insert(&head, 3);

    compress(head);

    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}