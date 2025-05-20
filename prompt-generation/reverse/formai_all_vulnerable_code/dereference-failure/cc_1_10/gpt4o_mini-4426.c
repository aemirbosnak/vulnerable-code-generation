//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definition of the queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to enqueue data into the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
    printf("Enqueued: %d\n", data);
}

// Function to dequeue data from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Unable to dequeue.\n");
        return -1; // Error signal
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    if (isEmpty(queue)) {
        queue->rear = NULL; // Queue is now empty
    }
    printf("Dequeued: %d\n", data);
    return data;
}

// Function to peek at the front element of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Nothing to peek at.\n");
        return -1; // Error signal
    }
    return queue->front->data;
}

// Function to display the queue contents
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to clean up the queue
void destroyQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// Main function to run the queue operations
int main() {
    Queue* queue = createQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    displayQueue(queue);
    
    printf("Front element is: %d\n", peek(queue));
    
    dequeue(queue);
    displayQueue(queue);
    
    enqueue(queue, 40);
    enqueue(queue, 50);
    displayQueue(queue);

    printf("Front element is: %d\n", peek(queue));
    
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    
    displayQueue(queue);
    
    // Attempt to dequeue from an empty queue
    dequeue(queue);
    
    // Clean up
    destroyQueue(queue);
    return 0;
}