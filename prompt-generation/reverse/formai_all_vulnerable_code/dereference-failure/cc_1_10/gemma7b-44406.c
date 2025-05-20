//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void enqueue(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int dequeue(Node** head) {
    if (*head == NULL) {
        return -1;
    }

    int data = (*head)->data;
    *head = (*head)->next;

    return data;
}

int main() {
    Node* head = NULL;

    enqueue(&head, 10);
    enqueue(&head, 20);
    enqueue(&head, 30);
    enqueue(&head, 40);
    enqueue(&head, 50);

    printf("Elements of the queue:");
    for (Node* node = head; node; node = node->next) {
        printf(" %d", node->data);
    }

    printf("\n");

    int data = dequeue(&head);
    if (data != -1) {
        printf("Data removed: %d", data);
    }

    data = dequeue(&head);
    if (data != -1) {
        printf("Data removed: %d", data);
    }

    data = dequeue(&head);
    if (data != -1) {
        printf("Data removed: %d", data);
    }

    data = dequeue(&head);
    if (data != -1) {
        printf("Data removed: %d", data);
    }

    printf("\n");

    printf("Elements of the queue after removal:");
    for (Node* node = head; node; node = node->next) {
        printf(" %d", node->data);
    }

    return 0;
}