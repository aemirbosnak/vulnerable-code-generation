//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to initialize a new queue
Queue* createQueue(void) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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

// Function to remove and return the element at the front of the queue
int dequeue(Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue->front->data;

    if (queue->size == 1) {
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
        queue->size--;
    } else {
        queue->front = queue->front->next;
        queue->size--;
    }

    return data;
}

// Function to display all elements in the queue
void displayQueue(Queue* queue) {
    Node* currentNode = queue->front;

    while (currentNode!= NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main(void) {
    Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    displayQueue(queue);

    printf("Front element: %d\n", dequeue(queue));
    displayQueue(queue);

    printf("Rear element: %d\n", dequeue(queue));
    displayQueue(queue);

    printf("Front element: %d\n", dequeue(queue));
    displayQueue(queue);

    printf("Front element: %d\n", dequeue(queue));
    displayQueue(queue);

    printf("Front element: %d\n", dequeue(queue));
    displayQueue(queue);

    return 0;
}