//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10
#define DEFAULT_VALUE 0

// Linked list node structure
typedef struct {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new queue
Queue* newQueue() {
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

// Function to get the size of the queue
int size(Queue* queue) {
    return queue->size;
}

// Function to enqueue an element
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

// Function to dequeue an element
int dequeue(Queue* queue) {
    int data;
    Node* node = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    data = node->data;
    queue->front = node->next;
    free(node);
    queue->size--;
    return data;
}

// Function to display the queue
void display(Queue* queue) {
    Node* node = queue->front;
    printf("Queue: ");
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = newQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    printf("Size of the queue: %d\n", size(queue));
    return 0;
}