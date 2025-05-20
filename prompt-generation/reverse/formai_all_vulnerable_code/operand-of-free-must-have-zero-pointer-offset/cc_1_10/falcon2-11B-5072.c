//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to insert an element at the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    // If the queue is empty, make the new node the front
    if (queue->size == 0) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    queue->size++;
}

// Function to remove and return the element at the front of the queue
int dequeue(Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    int data = queue->front->data;
    
    // If the queue has only one element, make the front the rear
    if (queue->size == 1) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    
    queue->size--;
    
    return data;
}

// Function to print the elements of the queue
void printQueue(Queue* queue) {
    Node* temp = queue->front;
    
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to destroy the queue and free its memory
void destroyQueue(Queue* queue) {
    Node* temp = queue->front;
    Node* next;
    
    while (temp!= NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(queue);
}

int main() {
    Queue* queue = createQueue();
    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    
    printQueue(queue);
    
    printf("Front element: %d\n", dequeue(queue));
    printf("Rear element: %d\n", dequeue(queue));
    
    destroyQueue(queue);
    
    return 0;
}