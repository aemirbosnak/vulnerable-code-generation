//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new Queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to get the size of the queue
int getSize(Queue* q) {
    return q->size;
}

// Function to enqueue an element
void enqueue(Queue* q, int value) {
    Node* temp = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue Underflow\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    printf("Dequeued: %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to get the front element
int front(Queue* q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return q->front->data;
}

// Function to get the rear element
int rear(Queue* q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return q->rear->data;
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    
    printf("Queue Operations Demonstration\n");
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    
    printf("Front element: %d\n", front(q));
    printf("Rear element: %d\n", rear(q));
    
    dequeue(q);
    displayQueue(q);
    
    enqueue(q, 40);
    enqueue(q, 50);
    displayQueue(q);
    
    dequeue(q);
    enqueue(q, 60);
    displayQueue(q);
    
    printf("Final Queue Size: %d\n", getSize(q));
    
    // Clean up the Queue
    while (!isEmpty(q)) {
        dequeue(q);
    }
    
    free(q);
    return 0;
}