//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: creative
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
    int count = 1;
    char currentData = head->data;
    Node* current = head->next;

    while (current) {
        if (currentData == current->data) {
            count++;
        } else {
            insertNode(head, currentData);
            insertNode(head, count);
            currentData = current->data;
            count = 1;
        }
        current = current->next;
    }

    insertNode(head, currentData);
    insertNode(head, count);
}

int main() {
    Node* head = insertNode(NULL, 'a');
    insertNode(head, 'a');
    insertNode(head, 'b');
    insertNode(head, 'b');
    insertNode(head, 'c');

    compress(head);

    head = head->next->next;
    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }

    return 0;
}