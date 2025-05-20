//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 10

// Define the structure of a queue
typedef struct {
    int front;
    int rear;
    int size;
    int *array;
} Queue;

// Initialize a queue
Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->array = (int*)malloc(sizeof(int) * MAX_SIZE);
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->size == 0;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return queue->size == MAX_SIZE;
}

// Add an element to the queue
void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = data;
    queue->size++;
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return data;
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->array[i]);
}

// Driver code
int main() {
    Queue *queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    enqueue(queue, 6);
    enqueue(queue, 7);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}