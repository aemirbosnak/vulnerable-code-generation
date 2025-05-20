//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure to represent the queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to initialize the queue
struct Queue* initQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to push an element to the queue
void push(struct Queue* queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        return;
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
}

// Function to pop an element from the queue
int pop(struct Queue* queue) {
    int data = -1;

    if (queue->front == NULL) {
        return data;
    }

    data = queue->front->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(queue->front);
    return data;
}

// Function to display the queue
void displayQueue(struct Queue* queue) {
    struct QueueNode* current = queue->front;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = initQueue(5);

    if (queue == NULL) {
        printf("Queue creation failed\n");
        return 1;
    }

    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    push(queue, 4);
    push(queue, 5);

    printf("Queue before popping: ");
    displayQueue(queue);

    int poppedData = pop(queue);
    printf("Popped data: %d\n", poppedData);

    printf("Queue after popping: ");
    displayQueue(queue);

    return 0;
}