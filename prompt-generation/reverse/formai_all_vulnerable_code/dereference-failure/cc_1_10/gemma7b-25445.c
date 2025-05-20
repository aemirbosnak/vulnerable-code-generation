//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }

    int data = queue->front->data;
    free(queue->front);
    queue->front = queue->front->next;
    queue->size--;

    return data;
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Front: %d\n", queue->front->data);
    printf("Rear: %d\n", queue->rear->data);
    printf("Size: %d\n", queue->size);

    int data = dequeue(queue);
    printf("Dequeued data: %d\n", data);

    printf("Front: %d\n", queue->front->data);
    printf("Rear: %d\n", queue->rear->data);
    printf("Size: %d\n", queue->size);

    return 0;
}