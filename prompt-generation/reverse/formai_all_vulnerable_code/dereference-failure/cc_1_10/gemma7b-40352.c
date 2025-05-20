//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
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

void traverseList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = insertAtTail(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    head = insertAtTail(head, 40);
    head = insertAtTail(head, 50);

    traverseList(head);

    // Compression algorithm starts here

    Node* current = head;
    Node* previous = NULL;
    int count = 0;

    while (current) {
        int data = current->data;
        current = current->next;

        if (previous && data == previous->data) {
            count++;
        } else {
            if (previous) {
                printf("%d ", count);
            }
            previous = insertAtTail(head, data);
            count = 1;
        }
    }

    printf("%d ", count);

    return 0;
}