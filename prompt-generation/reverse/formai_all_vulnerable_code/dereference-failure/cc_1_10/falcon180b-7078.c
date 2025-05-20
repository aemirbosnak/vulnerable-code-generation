//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

// Function to display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements:\n");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    display(q);
    printf("Dequeued element: %d\n", dequeue(q));
    return 0;
}