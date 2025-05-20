//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Data structure for queue element
struct QueueNode {
    int data;
};

// Data structure for queue
struct Queue {
    struct QueueNode *nodes;
    int front;
    int rear;
    int size;
};

// Initialize a new queue
struct Queue* createQueue(int size) {
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->nodes = malloc(sizeof(struct QueueNode) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Check if queue is full
int isFull(struct Queue *queue) {
    return (queue->rear == queue->size - 1);
}

// Check if queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Add an element to the queue
void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }
    struct QueueNode *node = malloc(sizeof(struct QueueNode));
    node->data = data;
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear += 1;
    }
    queue->nodes[queue->rear] = *node;
}

// Remove an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int dequeuedItem = queue->nodes[queue->front].data;
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front += 1;
    }
    return dequeuedItem;
}

// Display all elements in the queue
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->nodes[i].data);
    }
    printf("\n");
}

int main() {
    // Create queue with size 5
    struct Queue *queue = createQueue(5);

    // Enqueue elements to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Display all elements in the queue
    display(queue);

    // Dequeue an element from the queue
    int dequeuedItem = dequeue(queue);
    printf("Dequeued item: %d\n", dequeuedItem);

    // Display all elements in the queue
    display(queue);

    // Enqueue another element to the queue
    enqueue(queue, 60);

    // Display all elements in the queue
    display(queue);

    return 0;
}