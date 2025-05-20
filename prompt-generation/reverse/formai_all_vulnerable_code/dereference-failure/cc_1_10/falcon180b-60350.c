//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a queue
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Initialize an empty queue
void init(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Remove an element from the front of the queue
int dequeue(Queue* queue) {
    int data;
    Node* temp = queue->front;
    data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

// Display the contents of the queue
void display(Queue* queue) {
    Node* temp = queue->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue queue;
    init(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);
    printf("Dequeued element: %d\n", dequeue(&queue));
    display(&queue);
    return 0;
}