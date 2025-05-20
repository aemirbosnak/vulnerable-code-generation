//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Structure to represent the queue
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Function to create a new node
Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Function to enqueue an element
void enqueue(Queue *queue, int value) {
    Node *newNode = createNode(value);
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->rear->next = queue->front; // Circular link
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int value = queue->front->data;
    Node *temp = queue->front;

    if (queue->front == queue->rear) {
        // Only one element was present
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        // More than one element in the queue
        queue->front = queue->front->next;
        queue->rear->next = queue->front; // Maintain circular link
    }
    free(temp);
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to peek at the front element
int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->front->data;
}

// Function to display the queue elements
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    Node *current = queue->front;
    printf("Queue elements: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

// Function to free the queue
void freeQueue(Queue *queue) {
    if (isEmpty(queue)) {
        free(queue);
        return;
    }
    Node *current = queue->front;
    Node *temp;
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != queue->front);
    free(queue);
}

// Main function to demonstrate the queue operations
int main() {
    Queue *myQueue = createQueue();
    
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    
    display(myQueue);
    
    printf("Element at the front: %d\n", peek(myQueue));
    
    dequeue(myQueue);
    display(myQueue);
    
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);  // Testing underflow condition
    
    freeQueue(myQueue);
    return 0;
}