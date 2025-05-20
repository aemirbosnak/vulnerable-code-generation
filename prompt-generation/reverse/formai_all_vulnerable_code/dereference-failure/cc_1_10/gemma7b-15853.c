//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertNode(Node* head, int data) {
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

int compress(Node* head) {
    int count = 0;
    Node* current = head;

    while (current) {
        int consecutive = 1;
        Node* previous = current;

        while (previous->next && previous->next->data == current->data) {
            consecutive++;
            previous = previous->next;
        }

        if (consecutive > 1) {
            insertNode(head, consecutive - 1);
            count++;
        }

        current = current->next;
    }

    return count;
}

int main() {
    Node* head = insertNode(NULL, 1);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 3);

    int count = compress(head);

    printf("Number of nodes compressed: %d\n", count);

    return 0;
}