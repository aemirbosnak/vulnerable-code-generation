//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 100

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Create a new queue
Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Check if the queue is empty
bool isEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int data) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int data = queue->front->data;
    QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

// Get the front element of the queue
int getFront(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->front->data;
}

// Get the rear element of the queue
int getRear(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->rear->data;
}

// Print the queue
void printQueue(Queue *queue) {
    QueueNode *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Destroy the queue
void destroyQueue(Queue *queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

int main() {
    Queue *queue = createQueue();

    // Enqueue some elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Get the front element of the queue
    printf("Front element: %d\n", getFront(queue));

    // Get the rear element of the queue
    printf("Rear element: %d\n", getRear(queue));

    // Dequeue an element from the queue
    int data = dequeue(queue);
    printf("Dequeued element: %d\n", data);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}