//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the queue

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct {
    Node* front;
    Node* rear;
    int count;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    if (q->front == NULL)
        return true;
    else
        return false;
}

// Function to check if the queue is full
bool isFull(Queue* q) {
    if (q->count == MAX_SIZE)
        return true;
    else
        return false;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->count--;
    return data;
}

// Function to display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    Node* temp = q->front;
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
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    return 0;
}