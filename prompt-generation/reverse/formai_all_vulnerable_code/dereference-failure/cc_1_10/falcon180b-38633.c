//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to check if the queue is full
bool isFull(Queue* q) {
    return false;
}

// Function to add an element to the back of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
}

// Function to print the queue
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    Node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    printQueue(q);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    printQueue(q);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    printQueue(q);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    printQueue(q);
    return 0;
}