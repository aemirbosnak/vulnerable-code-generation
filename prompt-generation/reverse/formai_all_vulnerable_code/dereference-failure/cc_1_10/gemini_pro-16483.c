//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define the Queue structure
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Create a new queue
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
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
    Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    return data;
}

// Print the queue
void printQueue(Queue *queue) {
    Node *temp = queue->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Free the queue
void freeQueue(Queue *queue) {
    Node *temp = queue->front;

    while (temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }

    free(queue);
}

// Main function
int main() {
    // Create a new queue
    Queue *queue = createQueue();

    // Enqueue some elements into the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Dequeue some elements from the queue
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Free the queue
    freeQueue(queue);

    return 0;
}