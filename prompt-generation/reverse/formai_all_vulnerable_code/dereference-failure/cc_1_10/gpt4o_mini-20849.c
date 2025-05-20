//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a Queue Node
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Define the structure for Queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

// Function prototypes
Queue* createQueue();
bool isEmpty(Queue* queue);
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int peek(Queue* queue);
void displayQueue(Queue* queue);
void freeQueue(Queue* queue);

int main() {
    Queue* queue = createQueue();
    
    printf("Queue created successfully!\n");
    
    // Enqueue elements
    for (int i = 1; i <= 5; i++) {
        printf("Enqueuing %d\n", i);
        enqueue(queue, i);
        displayQueue(queue);
    }

    // Peek the front element
    printf("Front item is %d\n", peek(queue));

    // Dequeue elements
    while (!isEmpty(queue)) {
        printf("Dequeuing %d\n", dequeue(queue));
        displayQueue(queue);
    }

    // Free allocated memory for the queue
    freeQueue(queue);
    
    printf("Queue freed successfully!\n");
    
    return 0;
}

// Function to create a Queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    
    if (!queue) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue(Queue* queue, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }

    queue->rear = newNode;
    queue->size++;
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }

    QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
    return data;
}

// Function to get the front item of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    
    return queue->front->data;
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    QueueNode* temp = queue->front;
    printf("Queue: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the allocated memory for the queue
void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    
    free(queue);
}