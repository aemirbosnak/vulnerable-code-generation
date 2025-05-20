//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void compress(Node** head) {
    Node* current = *head;
    Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            if (previous) {
                insertNode(head, previous->data + count - 1);
            }
            previous = current;
            count = 1;
        }
        current = current->next;
    }

    if (previous) {
        insertNode(head, previous->data + count - 1);
    }
}

int main() {
    Node* head = NULL;
    insertNode(&head, 'a');
    insertNode(&head, 'a');
    insertNode(&head, 'b');
    insertNode(&head, 'b');
    insertNode(&head, 'c');
    insertNode(&head, 'c');

    compress(&head);

    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}