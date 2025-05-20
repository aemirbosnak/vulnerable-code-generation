//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to enqueue an item
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an item
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    int data = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    return data;
}

// Function to print the queue
void printQueue(struct Queue* q) {
    struct Node* node = q->front;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    initQueue(q);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Queue is:\n");
    printQueue(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Queue is:\n");
    printQueue(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Queue is:\n");
    printQueue(q);

    return 0;
}