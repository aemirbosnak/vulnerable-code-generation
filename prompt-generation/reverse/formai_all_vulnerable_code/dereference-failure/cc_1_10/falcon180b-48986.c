//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the queue structure
typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

// Function to create a new node
Node* newNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new queue
Queue* newQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Function to add an element to the rear of the queue
void enqueue(Queue *queue, int data) {
    Node *node = newNode(data);
    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue *queue) {
    int data;
    Node *node = queue->front;
    data = node->data;
    queue->front = node->next;
    free(node);
    queue->size--;
    return data;
}

// Function to display the elements of the queue
void display(Queue *queue) {
    Node *node = queue->front;
    printf("Queue: ");
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to test the implementation
int main() {
    Queue *queue = newQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    int data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    display(queue);
    data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    display(queue);
    data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    display(queue);
    return 0;
}