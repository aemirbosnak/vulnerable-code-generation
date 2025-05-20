//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
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
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    Node* tempNode = queue->front;
    int data = tempNode->data;
    queue->front = tempNode->next;
    free(tempNode);
    if (isEmpty(queue)) {
        queue->rear = NULL;
    }
    return data;
}

// Display the elements in the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    Node* tempNode = queue->front;
    printf("Queue: ");
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    enqueue(queue, 40);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
    return 0;
}