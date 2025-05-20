//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert_at_tail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

void compress(Node* head) {
    int count = 1;
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            insert_at_tail(previous, count);
            previous = current;
            count = 1;
        }
    }

    insert_at_tail(previous, count);

    printf("Compressed list:\n");
    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Node* head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);

    compress(head);

    return 0;
}