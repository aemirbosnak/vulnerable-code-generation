//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the structure of the queue
typedef struct {
    int data;
    int position;
} QueueElement;

// Define the structure of the queue
typedef struct {
    QueueElement *elements;
    int front;
    int rear;
    int size;
} Queue;

// Initialize the queue
void initQueue(Queue *queue) {
    queue->elements = (QueueElement *)malloc(MAX_SIZE * sizeof(QueueElement));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->size == MAX_SIZE);
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->elements[queue->rear].data = data;
    queue->elements[queue->rear].position = queue->size;
    queue->size++;
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->elements[queue->front].data;
    int position = queue->elements[queue->front].position;
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    queue->size--;
    return data;
}

// Display the contents of the queue
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\t", queue->elements[i].data);
    }
    printf("\n");
}

// Main function
int main() {
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);
    dequeue(&queue);
    display(&queue);
    dequeue(&queue);
    display(&queue);
    dequeue(&queue);
    display(&queue);
    return 0;
}