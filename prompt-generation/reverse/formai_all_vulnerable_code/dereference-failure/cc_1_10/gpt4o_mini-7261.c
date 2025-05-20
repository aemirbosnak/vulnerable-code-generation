//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to enqueue an element
void enqueueRecursive(Queue* queue, int data) {
    // Base case: if the queue is empty
    if (queue->rear == NULL) {
        Node* newNode = createNode(data);
        queue->front = queue->rear = newNode;
        return;
    }
    // Recursive case
    queue->rear->next = createNode(data);
    queue->rear = queue->rear->next;
}

// Recursive function to dequeue an element
int dequeueRecursive(Queue* queue) {
    // Base case: if the queue is empty
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    Node* temp = queue->front;
    int data = temp->data;

    // If there's only one node
    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    
    free(temp);
    return data;
}

// Recursive function to display the queue
void displayQueueRecursive(Node* front) {
    // Base case: if reached the end of the queue
    if (front == NULL) {
        return;
    }
    printf("%d ", front->data);
    displayQueueRecursive(front->next);
}

// Function to display the queue using recursion
void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    displayQueueRecursive(queue->front);
    printf("\n");
}

// A recursive function to free the queue
void freeQueueRecursive(Node* front) {
    // Base case: if the list is empty
    if (front == NULL) {
        return;
    }
    // Recursive case: free the current node, then the rest
    freeQueueRecursive(front->next);
    free(front);
}

// Main function to demonstrate the queue operations
int main() {
    Queue* queue = createQueue();
    
    enqueueRecursive(queue, 1);
    enqueueRecursive(queue, 2);
    enqueueRecursive(queue, 3);
    enqueueRecursive(queue, 4);
    enqueueRecursive(queue, 5);
    
    displayQueue(queue);

    printf("Dequeued: %d\n", dequeueRecursive(queue));
    displayQueue(queue);
    
    printf("Dequeued: %d\n", dequeueRecursive(queue));
    displayQueue(queue);
    
    printf("Dequeued: %d\n", dequeueRecursive(queue));
    displayQueue(queue);
    
    printf("Dequeued: %d\n", dequeueRecursive(queue));
    displayQueue(queue);
    
    printf("Dequeued: %d\n", dequeueRecursive(queue));
    displayQueue(queue);
    
    printf("Dequeued: %d\n", dequeueRecursive(queue)); // Should show queue is empty

    enqueueRecursive(queue, 6);
    displayQueue(queue);

    // Free the queue
    freeQueueRecursive(queue->front);
    free(queue);
    
    return 0;
}