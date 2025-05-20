//FormAI DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// C Queue Implementation
typedef struct {
    int* data;      // Data array
    int front;      // Index of the front of the queue
    int rear;       // Index of the rear of the queue
    int size;       // Number of elements in the queue
} CQueue;

// Function prototypes
void initQueue(CQueue* queue);
void enqueue(CQueue* queue, int val);
int dequeue(CQueue* queue);
int isFull(CQueue* queue);
int isEmpty(CQueue* queue);

// Function to initialize the queue
void initQueue(CQueue* queue) {
    queue->data = (int*) malloc(sizeof(int) * MAX_SIZE);
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// Function to check if queue is full
int isFull(CQueue* queue) {
    return (queue->size == MAX_SIZE);
}

// Function to check if queue is empty
int isEmpty(CQueue* queue) {
    return (queue->size == 0);
}

// Function to add an element to the queue
void enqueue(CQueue* queue, int val) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = val;
    queue->size++;
}

// Function to remove an element from the queue
int dequeue(CQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    queue->size--;
    return val;
}

int main() {
    CQueue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);

    if (!isEmpty(&queue)) {
        printf("Queue contains: ");
        while (!isEmpty(&queue)) {
            printf("%d ", dequeue(&queue));
        }
        printf("\n");
    }

    free(queue.data);
    return 0;
}