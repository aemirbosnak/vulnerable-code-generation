//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define the structure of a queue node
typedef struct {
    int data;
    struct node* next;
} Node;

// Define the structure of a queue
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to check if the queue is full
bool isFull(Queue* queue) {
    return queue->size == MAX_SIZE;
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, int data) {
    Node* node = createNode(data);
    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    return data;
}

// Function to display the elements of the queue
void display(Queue* queue) {
    Node* temp = queue->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    return 0;
}