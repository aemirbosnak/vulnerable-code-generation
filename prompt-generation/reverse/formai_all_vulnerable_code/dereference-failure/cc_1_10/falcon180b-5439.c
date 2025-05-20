//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function to add an element to the end of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->front->data;
    Node* tempNode = queue->front;
    queue->front = queue->front->next;
    free(tempNode);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

// Function to display the contents of the queue
void display(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
    } else {
        Node* currentNode = queue->front;
        while (currentNode!= NULL) {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    return 0;
}