//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertNode(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void traverseNode(Node* head) {
    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }
}

void compress(Node** head) {
    Node* current = *head;
    Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            insertNode(head, previous->data);
            insertNode(head, count);
            previous = current;
            count = 1;
        }
    }

    insertNode(head, previous->data);
    insertNode(head, count);
}

int main() {
    Node* head = NULL;
    insertNode(&head, 'a');
    insertNode(&head, 'a');
    insertNode(&head, 'b');
    insertNode(&head, 'b');
    insertNode(&head, 'c');
    insertNode(&head, 'c');

    traverseNode(head);

    compress(&head);

    traverseNode(head);

    return 0;
}