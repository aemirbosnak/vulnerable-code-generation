//FormAI DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct CircularQueue {
    Node *head;
    Node *tail;
    int size;
} CircularQueue;

void enqueue(CircularQueue *queue, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = queue->head;

    if (queue->head == NULL && queue->tail == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;
}

int dequeue(CircularQueue *queue) {
    if (queue->head == NULL && queue->tail == NULL) {
        printf("Error: Queue is empty");
        return -1;
    }

    int dequeuedValue = queue->head->value;
    Node *temp = queue->head;

    if (queue->head == queue->tail) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = queue->head->next;
        queue->tail->next = queue->head;
    }

    free(temp);
    queue->size--;

    return dequeuedValue;
}

void printQueue(CircularQueue *queue) {
    if (queue->head == NULL && queue->tail == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Printing Queue: ");
    Node *currentNode = queue->head;

    do {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    } while(currentNode != queue->head);

    printf("\n");
}

int main() {
    CircularQueue myQueue = {NULL, NULL, 0};

    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);
    enqueue(&myQueue, 4);
    printQueue(&myQueue);

    dequeue(&myQueue);
    printQueue(&myQueue);

    enqueue(&myQueue, 5);
    printQueue(&myQueue);

    dequeue(&myQueue);
    dequeue(&myQueue);
    printQueue(&myQueue);

    return 0;
}