//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue node
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize a queue
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to enqueue an item to the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an item from the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("The queue is empty\n");
        return -1;
    }

    int data = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

// Function to print the items in the queue
void printQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("The queue is empty\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue:\n");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to destroy a queue
void destroyQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp!= NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    q->front = NULL;
    q->rear = NULL;
}

int main() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    initQueue(q);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Queue:\n");
    printQueue(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Queue:\n");
    printQueue(q);

    destroyQueue(q);

    return 0;
}