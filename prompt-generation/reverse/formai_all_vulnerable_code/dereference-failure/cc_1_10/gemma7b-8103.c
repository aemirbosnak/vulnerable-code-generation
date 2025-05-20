//Gemma-7B DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void enqueue(Queue* queue, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

void dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return;
    }

    Node* oldHead = queue->head;
    queue->head = queue->head->next;

    free(oldHead);
}

int main() {
    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    dequeue(queue);
    dequeue(queue);

    printf("Elements in the queue:");
    for (Node* node = queue->head; node; node = node->next) {
        printf(" %d", node->data);
    }

    free(queue);

    return 0;
}