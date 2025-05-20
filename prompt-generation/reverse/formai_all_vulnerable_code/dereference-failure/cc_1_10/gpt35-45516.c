//FormAI DATASET v1.0 Category: Queue ; Style: happy
// Let's create a happy C Queue example program!
// First, we need to include some headers
#include <stdio.h>
#include <stdlib.h>

// Let's define our queue data structure using a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Initialize queue
void init(Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Check if queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d was added to the queue!\n", data);
}

// Remove an element from the front of the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue!\n");
        return -1;
    }

    Node* nodeToDelete = queue->front;
    int data = nodeToDelete->data;

    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(nodeToDelete);
    printf("%d was removed from the queue!\n", data);
    return data;
}

// Peek at the front element of the queue without removing it
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot peek!\n");
        return -1;
    }

    int data = queue->front->data;
    printf("%d is at the front of the queue!\n", data);
    return data;
}

int main() {
    Queue queue;
    init(&queue);

    // We'll enqueue a few numbers
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    // Now let's dequeue a few numbers
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    // Peek at the front of the queue
    peek(&queue);

    // Let's dequeue the remaining numbers
    dequeue(&queue);
    dequeue(&queue);

    // Try to dequeue an empty queue (this will print an error message)
    dequeue(&queue);

    return 0;
}