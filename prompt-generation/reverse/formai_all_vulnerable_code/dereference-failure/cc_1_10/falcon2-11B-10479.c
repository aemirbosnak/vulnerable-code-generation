//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the Node structure for the queue
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Define the Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to initialize a new Queue
Queue* newQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to insert an element at the rear of the Queue
void enqueue(Queue* q, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Function to delete an element from the front of the Queue
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = q->front->value;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return value;
}

// Function to display the Queue
void display(Queue* q) {
    Node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if the Queue is empty
bool isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to check if the Queue is full
bool isFull(Queue* q) {
    return q->size == 10;
}

// Function to check if the Queue is sorted
bool isSorted(Queue* q) {
    // TODO: Implement sorting algorithm
}

int main() {
    Queue* q = newQueue();

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    enqueue(q, 20);

    display(q);

    int value = dequeue(q);
    printf("Dequeued element: %d\n", value);

    display(q);

    return 0;
}