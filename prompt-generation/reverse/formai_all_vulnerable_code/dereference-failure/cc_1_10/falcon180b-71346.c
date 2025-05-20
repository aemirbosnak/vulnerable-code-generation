//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} node;

// Queue structure definition
typedef struct {
    node* front;
    node* rear;
    int count;
} queue;

// Function to create an empty queue
queue* createQueue() {
    queue* q = (queue*)malloc(sizeof(queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(queue* q) {
    return q->front == NULL;
}

// Function to add an element to the rear of the queue
void enqueue(queue* q, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
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
int dequeue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    q->count--;
    return data;
}

// Function to display the elements of the queue
void display(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    enqueue(q, 40);
    display(q);
    return 0;
}