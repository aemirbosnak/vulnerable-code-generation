//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int peek(Queue* queue);
int isEmpty(Queue* queue);
void display(Queue* queue);

// Create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    printf("Element %d enqueued to the queue\n", data);
}

// Remove an element from the front of the queue
int dequeue(Queue* queue) {
    Node* node = queue->front;
    int data = node->data;
    queue->front = node->next;
    free(node);
    printf("Element %d dequeued from the queue\n", data);
    return data;
}

// Return the front element of the queue without removing it
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Display the elements of the queue
void display(Queue* queue) {
    Node* node = queue->front;
    printf("Queue elements: ");
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    printf("Front element: %d\n", peek(queue));
    dequeue(queue);
    dequeue(queue);
    display(queue);
    printf("Front element: %d\n", peek(queue));
    return 0;
}