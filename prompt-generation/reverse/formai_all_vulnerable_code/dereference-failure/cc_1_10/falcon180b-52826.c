//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define structure for the queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int value) {
    Node* temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    if (isEmpty(queue)) {
        queue->front = temp;
    }
    else {
        queue->rear->next = temp;
    }
    queue->rear = temp;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    int value;
    Node* temp = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(0);
    }
    value = temp->data;
    queue->front = temp->next;
    free(temp);
    if (isEmpty(queue)) {
        queue->rear = NULL;
    }
    return value;
}

// Function to display the elements in the queue
void display(Queue* queue) {
    Node* temp = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    return 0;
}