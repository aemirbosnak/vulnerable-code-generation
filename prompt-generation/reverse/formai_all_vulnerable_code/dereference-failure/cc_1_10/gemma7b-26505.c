//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Node* insertAtTail(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void compress(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            insertAtTail(previous, count);
            previous = current;
            count = 1;
        }
        current = current->next;
    }

    insertAtTail(previous, count);
}

int main() {
    struct Node* head = insertAtTail(NULL, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 3);

    compress(head);

    struct Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}