//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define the structure of the queue
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Create a new queue
Queue* createQueue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Add an element to the rear of the queue
void enqueue(Queue *queue, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
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

// Remove an element from the front of the queue
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

// Print the contents of the queue
void printQueue(Queue *queue) {
    Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Destroy the queue
void destroyQueue(Queue *queue) {
    Node *temp;
    while (queue->front != NULL) {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

int main() {
    // Create a new queue
    Queue *queue = createQueue();

    // Enqueue some elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the contents of the queue
    printQueue(queue);

    // Dequeue some elements from the queue
    dequeue(queue);
    dequeue(queue);

    // Print the contents of the queue
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}