//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure representing a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure representing the queue
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

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
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

// Enqueue function to add an element to the queue
void enqueue(Queue* q, int value) {
    Node* newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    printf("Enqueued: %d\n", value);
}

// Dequeue function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1; // Indicates failure
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    printf("Dequeued: %d\n", value);
    return value; // Return the dequeued value
}

// Function to peek the front element of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, nothing to peek.\n");
        return -1; // Indicates failure
    }
    return q->front->data; // Return the front value
}

// Function to display the queue elements
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is currently empty.\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the Queue implementation
int main() {
    Queue* q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    displayQueue(q);
    
    printf("Front element is: %d\n", peek(q));
    
    dequeue(q);
    
    displayQueue(q);
    
    enqueue(q, 40);
    enqueue(q, 50);
    
    displayQueue(q);
    
    printf("Front element is: %d\n", peek(q));
    
    while(!isEmpty(q)) {
        dequeue(q);
    }
    
    displayQueue(q);
    
    free(q); // Free the queue memory
    return 0;
}