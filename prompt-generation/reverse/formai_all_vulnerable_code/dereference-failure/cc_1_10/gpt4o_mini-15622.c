//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for queue
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failure!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create and initialize a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failure!\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
bool isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
    printf("Enqueued: %d | Current Queue Size: %d\n", data, queue->size);
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // An indicator of failure to dequeue
    }
    Node* temp = queue->front;
    int dequeuedData = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL; // Queue is now empty
    }
    free(temp);
    queue->size--;
    printf("Dequeued: %d | Current Queue Size: %d\n", dequeuedData, queue->size);
    return dequeuedData;
}

// Function to get the front element of the queue
int peekQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty! No front element.\n");
        return -1; // An indicator of empty queue
    }
    return queue->front->data;
}

// Function to display the elements of the queue
void displayQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty! Nothing to display.\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue elements: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function for testing the queue implementation
int main() {
    Queue* queue = createQueue();
    
    // Adding elements to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    
    // Displaying the current state of the queue
    displayQueue(queue);
    
    // Accessing the front element
    printf("Front element: %d\n", peekQueue(queue));

    // Removing some elements from the queue
    dequeue(queue);
    dequeue(queue);
    
    // Displaying the current state of the queue again
    displayQueue(queue);
    
    // Accessing the front element again
    printf("Front element: %d\n", peekQueue(queue));

    // Final dequeuing actions
    dequeue(queue);
    dequeue(queue);
    
    // Attempting to dequeue from an empty queue
    dequeue(queue);
    
    // Clean up queue memory
    free(queue);
    
    return 0;
}