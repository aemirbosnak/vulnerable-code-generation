//FormAI DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a struct for a queue using a linked list
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Declare functions for initializing, adding and deleting nodes from the queue
void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(queue->rear) {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    if(!queue->front) {
        queue->front = queue->rear;
    }
}

void dequeue(struct Queue* queue) {
    if(!queue->front) {
        return;
    }
    struct Node* node = queue->front;
    queue->front = queue->front->next;
    if(!queue->front) {
        queue->rear = NULL;
    }
    free(node);
}

// Declare a function to print the queue
void printQueue(struct Queue* queue) {
    printf("Queue: ");
    struct Node* node = queue->front;
    while(node) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Initialize a queue
    struct Queue queue;
    initializeQueue(&queue);
    
    // Enqueue some elements
    enqueue(&queue, 5);
    printQueue(&queue);
    enqueue(&queue, 10);
    printQueue(&queue);
    enqueue(&queue, 15);
    printQueue(&queue);
    
    // Dequeue an element
    dequeue(&queue);
    printQueue(&queue);
    
    // Enqueue another element
    enqueue(&queue, 20);
    printQueue(&queue);
    
    // Dequeue all elements
    while(queue.front) {
        dequeue(&queue);
        printQueue(&queue);
    }
    
    return 0;
}