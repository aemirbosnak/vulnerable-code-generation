//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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
            if (previous) {
                insertAtTail(head, count - 1);
            }
            previous = current;
            count = 1;
        }
        current = current->next;
    }

    if (previous) {
        insertAtTail(head, count - 1);
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 'a');
    insertAtTail(&head, 'a');
    insertAtTail(&head, 'b');
    insertAtTail(&head, 'b');
    insertAtTail(&head, 'c');

    compress(head);

    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}