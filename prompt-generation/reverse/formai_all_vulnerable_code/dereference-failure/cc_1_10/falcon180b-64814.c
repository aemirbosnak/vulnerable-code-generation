//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure definition
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
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

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    int data = -1;

    if (!isEmpty(queue)) {
        Node* temp = queue->front;
        data = temp->data;
        queue->front = temp->next;

        if (queue->front == NULL) {
            queue->rear = NULL;
        }

        free(temp);
    }

    return data;
}

// Function to print the elements of the queue
void printQueue(Queue* queue) {
    Node* temp = queue->front;

    printf("Queue: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printQueue(queue);

    int dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);

    printQueue(queue);

    return 0;
}