//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
void display(Queue* queue);

int main() {
    Queue* queue = createQueue();

    // Test enqueue function
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    display(queue);

    // Test dequeue function
    int data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    display(queue);

    // Test enqueue and dequeue functions
    enqueue(queue, 4);
    enqueue(queue, 5);
    display(queue);
    data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    display(queue);

    return 0;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
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

// Function to remove and return the front element of the queue
int dequeue(Queue* queue) {
    Node* frontNode = queue->front;
    int data = frontNode->data;

    if (queue->front!= NULL) {
        queue->front = queue->front->next;
    }

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(frontNode);
    return data;
}

// Function to display the current state of the queue
void display(Queue* queue) {
    Node* temp = queue->front;

    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}