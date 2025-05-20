//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to get the size of the queue
int getSize(Queue* q) {
    return q->size;
}

// Function to enqueue an element
void enqueue(Queue* q, int value) {
    Node* newNode = createNode(value);
    if (q->rear) {
        q->rear->next = newNode;
    } else {
        q->front = newNode;
    }
    q->rear = newNode;
    q->size++;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Indicating queue is empty
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; // If the queue is now empty
    }
    free(temp);
    q->size--;
    printf("Dequeued: %d\n", data);
    return data;
}

// Function to peek at the front element
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        return -1;
    }
    return q->front->data;
}

// Function to display the elements of the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the queue operations
int main() {
    Queue* q = createQueue();

    // Enqueue some elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    // Display the queue
    displayQueue(q);
    
    // Peek at the front element
    printf("Front element: %d\n", peek(q));

    // Dequeue some elements
    dequeue(q);
    displayQueue(q);
    
    dequeue(q);
    displayQueue(q);
    
    // Show the current state of queue
    printf("Final state of queue:\n");
    displayQueue(q);

    // Cleanup remaining elements
    while (!isEmpty(q)) {
        dequeue(q);
    }
    
    // Clean up queue structure
    free(q);
    return 0;
}