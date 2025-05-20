//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int front, rear, capacity;
    int *array;
} Queue;

// Create a new queue
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == queue->capacity - 1);
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->array[queue->rear] = item;
        printf("%d inserted\n", item);
    }
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return (-1);
    }
    else {
        int item = queue->array[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
            queue->front = queue->rear = -1;
        printf("%d deleted\n", item);
        return (item);
    }
}

// Display the queue
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    else {
        printf("Queue: ");
        for (int i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->array[i]);
        printf("\n");
    }
}

// Get the front element of the queue
int front(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return (-1);
    }
    else
        return (queue->array[queue->front]);
}

// Get the rear element of the queue
int rear(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return (-1);
    }
    else
        return (queue->array[queue->rear]);
}

// Driver code to test the Queue implementation
int main() {
    Queue *queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    enqueue(queue, 50);
    display(queue);
    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));
    return 0;
}