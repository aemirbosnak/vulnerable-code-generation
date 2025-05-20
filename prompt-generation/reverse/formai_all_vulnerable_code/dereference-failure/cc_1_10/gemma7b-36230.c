//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insert(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next) = newNode;
    }
}

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;

    char previousChar = '\0';
    int count = 1;

    while (current) {
        if (previousChar == current->data) {
            count++;
        } else {
            if (previousChar) {
                insert(head, previousChar + count - 1);
            }
            previousChar = current->data;
            count = 1;
        }

        current = current->next;
    }

    if (previousChar) {
        insert(head, previousChar + count - 1);
    }
}

int main() {
    Node* head = NULL;

    insert(&head, 'a');
    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'c');
    insert(&head, 'c');

    compress(head);

    Node* traversal = head;

    while (traversal) {
        printf("%c ", traversal->data);
        traversal = traversal->next;
    }

    return 0;
}