//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure for the queue itself
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Failed to allocate memory for new node.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("Error: Failed to allocate memory for new queue.\n");
        exit(1);
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove the element from the front of the queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Error: Queue is empty.\n");
        exit(1);
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

// Function to display the elements in the queue
void display(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue elements: ");
        Node* tempNode = queue->front;
        while (tempNode!= NULL) {
            printf("%d ", tempNode->data);
            tempNode = tempNode->next;
        }
        printf("\n");
    }
}

// Main function to test the queue implementation
int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    int dequeuedData = dequeue(queue);
    printf("Dequeued element: %d\n", dequeuedData);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    return 0;
}