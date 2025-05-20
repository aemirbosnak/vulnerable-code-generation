//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Structure of a queue node
struct QueueNode {
    int data;
    struct QueueNode *next;
};

// Structure of a queue
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

    if (isEmpty(queue)) {
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
    } else {
        struct QueueNode *temp = queue->front;
        int data = temp->data;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}

// Get the front element of the queue
int getFront(struct Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    } else {
        return queue->front->data;
    }
}

// Get the rear element of the queue
int getRear(struct Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    } else {
        return queue->rear->data;
    }
}

// Print the queue
void printQueue(struct Queue *queue) {
    struct QueueNode *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Get the size of the queue
int getSize(struct Queue *queue) {
    int size = 0;
    struct QueueNode *temp = queue->front;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

int main() {
    // Create a queue
    struct Queue *queue = createQueue();

    // Enqueue elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Get the front element of the queue
    printf("Front element: %d\n", getFront(queue));

    // Get the rear element of the queue
    printf("Rear element: %d\n", getRear(queue));

    // Get the size of the queue
    printf("Size of the queue: %d\n", getSize(queue));

    // Dequeue elements from the queue
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));

    // Print the queue
    printQueue(queue);

    return 0;
}