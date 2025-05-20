//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the queue
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

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q)) {
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
    int data;
    Node* temp = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    data = temp->data;
    q->front = temp->next;
    free(temp);
    q->size--;
    return data;
}

// Function to print the contents of the queue
void printQueue(Queue* q) {
    Node* temp = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);
    dequeue(q);
    dequeue(q);
    printQueue(q);
    dequeue(q);
    printQueue(q);
    return 0;
}