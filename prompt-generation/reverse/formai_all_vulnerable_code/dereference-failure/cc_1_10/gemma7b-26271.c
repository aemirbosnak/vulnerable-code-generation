//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertNode(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    char previousData = '\0';
    int count = 0;

    while (current) {
        if (previousData == current->data && count > 0) {
            printf("%c%d ", previousData, count);
            count = 0;
        } else {
            previousData = current->data;
            count++;
        }

        current = current->next;
    }

    if (count > 0) {
        printf("%c%d ", previousData, count);
    }
}

int main() {
    Node* head = insertNode(NULL, 'a');
    insertNode(head, 'a');
    insertNode(head, 'b');
    insertNode(head, 'a');
    insertNode(head, 'b');
    insertNode(head, 'c');

    compress(head);

    return 0;
}