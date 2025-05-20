//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
typedef struct {
    int data;
    struct node* next;
} Node;

// Define the structure of the queue
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new empty queue
Queue* newQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->size == 0;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* node = newNode(data);
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
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    queue->size--;
    return data;
}

// Function to display the elements of the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
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
    Queue* queue = newQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    return 0;
}