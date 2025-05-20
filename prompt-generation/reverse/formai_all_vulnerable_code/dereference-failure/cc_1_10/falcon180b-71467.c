//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
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
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to enqueue an element
void enqueue(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to dequeue an element
int dequeue(Queue* q) {
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    free(temp);
    return value;
}

// Function to display the queue
void display(Queue* q) {
    Node* temp = q->front;
    printf("Queue: ");
    while (temp!= NULL) {
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
    display(q);
    int value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    return 0;
}