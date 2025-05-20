//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
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

// Function to enqueue an element to the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    queue->size++;
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    int data = -1;
    
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return data;
    }
    
    data = queue->front->data;
    
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    
    free(queue->front);
    queue->size--;
    
    return data;
}

// Function to display the elements in the queue
void displayQueue(Queue* queue) {
    Node* current = queue->front;
    
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}

// Main function
int main() {
    Queue* queue = createQueue();
    
    // Enqueue elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    
    // Display elements in the queue
    displayQueue(queue);
    
    // Dequeue elements
    int data = dequeue(queue);
    data = dequeue(queue);
    data = dequeue(queue);
    data = dequeue(queue);
    
    // Display elements in the queue after dequeue
    displayQueue(queue);
    
    return 0;
}