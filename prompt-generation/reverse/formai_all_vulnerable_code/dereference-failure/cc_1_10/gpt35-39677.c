//FormAI DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

bool isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

void enqueue(Queue *queue, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty");
        return -1;
    } else {
        int value = queue->front->value;
        Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        return value;
    }
}

void printQueue(Queue *queue) {
    printf("[");
    Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("]\n");
}

int main() {
    Queue *queue = createQueue();
    printf("Queue created.\n\n");

    enqueue(queue, 5);
    printf("Enqueued 5 to the queue.\n");
    printQueue(queue);
    printf("\n");

    enqueue(queue, 10);
    printf("Enqueued 10 to the queue.\n");
    printQueue(queue);
    printf("\n");

    dequeue(queue);
    printf("Dequeued from the queue.\n");
    printQueue(queue);
    printf("\n");

    enqueue(queue, 15);
    printf("Enqueued 15 to the queue.\n");
    printQueue(queue);
    printf("\n");

    printf("Done.\n");

    return 0;
}