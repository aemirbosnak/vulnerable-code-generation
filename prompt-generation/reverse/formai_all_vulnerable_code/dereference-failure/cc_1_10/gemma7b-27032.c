//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

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

int compress(Node* head) {
    int count = 0;
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        int runs = 1;
        while (previous && current->data == previous->data) {
            runs++;
            previous = previous->next;
        }

        if (runs > 1) {
            insertAtTail(head, runs);
            count++;
        }

        previous = current;
        current = current->next;
    }

    return count;
}

int main() {
    Node* head = insertAtTail(NULL, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    int count = compress(head);

    printf("Number of nodes reduced: %d\n", count);

    return 0;
}