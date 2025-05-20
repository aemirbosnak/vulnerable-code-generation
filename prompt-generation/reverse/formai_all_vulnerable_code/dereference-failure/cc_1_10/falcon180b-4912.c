//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a queue
typedef struct queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->front->data;
    Node* tempNode = queue->front;
    queue->front = queue->front->next;
    free(tempNode);
    queue->size--;
    return data;
}

// Function to display the elements of the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    Node* tempNode = queue->front;
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
    int dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);
    display(queue);
    enqueue(queue, 40);
    display(queue);
    return 0;
}