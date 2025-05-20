//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertNode(Node* head, char data) {
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

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    char previousChar = '\0';
    int count = 0;

    while (current) {
        if (previousChar == current->data) {
            count++;
        } else {
            if (previousChar) {
                insertNode(head, previousChar + count - 1);
            }
            previousChar = current->data;
            count = 1;
        }
        previous = current;
        current = current->next;
    }

    if (previousChar) {
        insertNode(head, previousChar + count - 1);
    }
}

int main() {
    Node* head = NULL;
    insertNode(head, 'a');
    insertNode(head, 'a');
    insertNode(head, 'b');
    insertNode(head, 'b');
    insertNode(head, 'c');
    insertNode(head, 'c');

    compress(head);

    Node* iter = head;
    while (iter) {
        printf("%c ", iter->data);
        iter = iter->next;
    }

    return 0;
}