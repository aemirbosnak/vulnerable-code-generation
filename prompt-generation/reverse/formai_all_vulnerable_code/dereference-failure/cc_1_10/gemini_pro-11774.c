//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
struct QueueNode {
    int data;
    struct QueueNode *next;
};

// Define the structure of a queue
struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Create a new queue
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == NULL);
}

// Enqueue an element into the queue
void enqueue(struct Queue *queue, int data) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }

    struct QueueNode *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    int data = temp->data;
    free(temp);

    return data;
}

// Print the elements of the queue
void printQueue(struct Queue *queue) {
    struct QueueNode *temp = queue->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Destroy the queue
void destroyQueue(struct Queue *queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }

    free(queue);
}

// Main function
int main() {
    // Create a queue
    struct Queue *queue = createQueue();

    // Enqueue some elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the elements of the queue
    printf("Queue: ");
    printQueue(queue);

    // Dequeue some elements from the queue
    int data1 = dequeue(queue);
    int data2 = dequeue(queue);

    // Print the elements of the queue
    printf("Queue after dequeueing two elements: ");
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}