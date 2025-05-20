//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
typedef struct node {
    int data;
    struct node* next;
} node;

// Queue structure
typedef struct queue {
    node* front;
    node* rear;
} queue;

// Function to initialize queue
queue* initQueue(int size) {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to enqueue an element
void enqueue(queue* q, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->front->data;
    node* temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

// Function to display the queue
void displayQueue(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue* q = initQueue(5);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    displayQueue(q);
    printf("Dequeue: %d\n", dequeue(q));
    displayQueue(q);
    printf("Dequeue: %d\n", dequeue(q));
    displayQueue(q);

    free(q);

    return 0;
}