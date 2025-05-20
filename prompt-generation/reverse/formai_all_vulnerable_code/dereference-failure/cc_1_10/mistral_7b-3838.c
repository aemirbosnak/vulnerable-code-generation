//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define QUEUE_SIZE 10

typedef struct Node {
    uint8_t data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    Node *buffer;
    size_t size;
    size_t count;
} CircularQueue;

void initQueue(CircularQueue *queue) {
    queue->buffer = malloc(QUEUE_SIZE * sizeof(Node));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = QUEUE_SIZE;
    queue->count = 0;
}

int isFull(CircularQueue *queue) {
    return queue->count == queue->size;
}

int isEmpty(CircularQueue *queue) {
    return queue->front == NULL;
}

void enqueue(CircularQueue *queue, uint8_t data) {
    if (isFull(queue)) {
        fprintf(stderr, "Queue is full!\n");
        return;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->count++;
}

uint8_t dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty!\n");
        return 0;
    }

    uint8_t data = queue->front->data;
    Node *temp = queue->front;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    queue->count--;

    return data;
}

void printQueue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    Node *current = queue->front;
    printf("Queue: [");
    while (current != NULL) {
        printf("%u, ", current->data);
        current = current->next;
    }
    printf("\b\b]");
}

int main() {
    CircularQueue queue;
    initQueue(&queue);

    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 15);

    printf("Queue: ");
    printQueue(&queue);

    uint8_t data = dequeue(&queue);
    printf("Dequeued: %u\n", data);

    enqueue(&queue, 20);

    printf("Queue: ");
    printQueue(&queue);

    return 0;
}