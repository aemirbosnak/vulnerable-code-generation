//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Queue structure definition
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!newQueue) {
        printf("Memory error\n");
        return NULL;
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->front->data;
    struct Node* tempNode = queue->front;
    queue->front = queue->front->next;
    free(tempNode);
    return data;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    struct Node* tempNode = queue->front;
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    int dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);
    display(queue);
    return 0;
}