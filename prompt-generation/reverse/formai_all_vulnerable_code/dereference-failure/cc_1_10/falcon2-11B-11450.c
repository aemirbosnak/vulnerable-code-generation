//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to add an element to the queue
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
}

// Function to remove an element from the queue
void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
}

// Function to print the queue
void printQueue(struct Queue* q) {
    struct Node* temp = q->front;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    initQueue(q);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printQueue(q);
    printf("\n");

    dequeue(q);
    printQueue(q);
    printf("\n");

    dequeue(q);
    dequeue(q);

    printf("Queue is empty\n");

    return 0;
}