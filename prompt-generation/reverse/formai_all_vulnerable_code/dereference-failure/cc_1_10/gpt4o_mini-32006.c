//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue Node Structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue Structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue(Queue* queue, int data) {
    Node* temp = newNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        queue->size++;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
    queue->size++;
    printf("Enqueued: %d\n", data);
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = queue->front->data;
    Node* temp = queue->front;

    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    
    free(temp);
    queue->size--;
    printf("Dequeued: %d\n", data);
    return data;
}

// Function to get the front item of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

// Function to count the number of items in the queue
int queueSize(Queue* queue) {
    return queue->size;
}

// Function to print the queue
void printQueue(Queue* queue) {
    Node* temp = queue->front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    Queue* queue = createQueue();

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printQueue(queue);

    // Dequeue elements
    dequeue(queue);
    printQueue(queue);

    // Peek at the front element
    printf("Front element: %d\n", peek(queue));

    // Check queue size
    printf("Queue size: %d\n", queueSize(queue));

    // Enqueue more elements
    enqueue(queue, 40);
    enqueue(queue, 50);
    printQueue(queue);

    // Final dequeue operations
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);

    // Free allocated memory
    free(queue);

    return 0;
}