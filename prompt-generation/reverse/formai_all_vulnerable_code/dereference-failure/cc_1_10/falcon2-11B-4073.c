//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
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

// Function to remove an element from the front of the queue
int dequeue(struct Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    free(temp);
    q->size--;
    return data;
}

// Function to display the elements in the queue
void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    printf("Elements in the queue are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if the queue is empty
bool isQueueEmpty(struct Queue* q) {
    return (q->size == 0);
}

// Function to get the size of the queue
int getQueueSize(struct Queue* q) {
    return q->size;
}

// Function to destroy the queue
void destroyQueue(struct Queue* q) {
    while (q->size!= 0) {
        dequeue(q);
    }
    free(q);
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    printf("Size of the queue: %d\n", getQueueSize(q));
    dequeue(q);
    displayQueue(q);
    destroyQueue(q);
    return 0;
}