//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// A node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// A queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    if (newQueue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

// Function to display the queue
void displayQueue(struct Queue* queue) {
    struct Node* temp = queue->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    displayQueue(queue);
    printf("Dequeueing...\n");
    printf("%d", dequeue(queue));
    printf("Dequeueing...\n");
    printf("%d", dequeue(queue));
    printf("Dequeueing...\n");
    printf("%d", dequeue(queue));
    printf("Dequeueing...\n");
    printf("%d", dequeue(queue));
    printf("Dequeueing...\n");
    printf("%d", dequeue(queue));
    printf("Dequeueing...\n");
    printf("%d", dequeue(queue));
    printf("Dequeueing...\n");
    printf("%d", dequeue(queue));
    printf("Dequeueing...\n");
    printf("%d", dequeue(queue));
    displayQueue(queue);
    return 0;
}