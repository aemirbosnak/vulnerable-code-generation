//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for a queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to get the size of the queue
int getSize(Queue* queue) {
    return queue->size;
}

// Function to enqueue an element
void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        exit(EXIT_FAILURE); // Exit for simplicity; in practice return an error code or similar
    }
    Node* temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    if (isEmpty(queue)) {
        queue->rear = NULL; // Reset rear when the queue becomes empty
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to peek at the front element
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot peek.\n");
        exit(EXIT_FAILURE);
    }
    return queue->front->data;
}

// Function to free the queue memory
void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function for testing the queue implementation
int main() {
    Queue* queue = createQueue();
    printf("Queue created successfully!\n");

    enqueue(queue, 10);
    displayQueue(queue);
    enqueue(queue, 20);
    displayQueue(queue);
    enqueue(queue, 30);
    displayQueue(queue);

    printf("Peek: %d\n", peek(queue));

    dequeue(queue);
    displayQueue(queue);
    dequeue(queue);
    displayQueue(queue);
    dequeue(queue);
    displayQueue(queue);

    // Trying to dequeue from an empty queue
    dequeue(queue);

    freeQueue(queue); // Free allocated memory
    return 0;
}