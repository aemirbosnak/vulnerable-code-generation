//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            if (previous) {
                insertAtTail(head, count);
            }
            previous = current;
            count = 1;
        }
        current = current->next;
    }

    insertAtTail(head, count);
}

int main() {
    Node* head = insertAtTail(NULL, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    compress(head);

    Node* iter = head;
    while (iter) {
        printf("%d ", iter->data);
        iter = iter->next;
    }

    printf("\n");

    return 0;
}