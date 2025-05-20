//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>

// Define a structure to hold a node in the queue
struct QueueNode {
    int value;
    struct QueueNode* next;
};

// Define a structure to hold the queue itself
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
    int size;
};

// Function prototypes
void enqueue(struct Queue*, int);
int dequeue(struct Queue*);
void display(struct Queue*);

int main() {

    // Create a new queue object
    struct Queue* myQueue = malloc(sizeof(struct Queue));
    if (!myQueue) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the queue
    myQueue->front = NULL;
    myQueue->rear = NULL;
    myQueue->size = 0;

    // Add some elements to the queue
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);

    // Display the contents of the queue
    display(myQueue);

    // Remove the first element from the queue
    int element = dequeue(myQueue);

    // Display the updated contents of the queue
    display(myQueue);

    return 0;
}

// Function to add an element to the back of the queue
void enqueue(struct Queue* q, int value) {

    // Create a new node
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Initialize the new node
    newNode->value = value;
    newNode->next = NULL;

    // If the queue is empty, make the new node the front and rear
    if (!q->front &&!q->rear) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        // Otherwise, add the new node to the end of the queue
        q->rear->next = newNode;
        q->rear = newNode;
    }

    // Increment the size of the queue
    q->size++;
}

// Function to remove the first element from the front of the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Remove the front node and return its value
    int value = q->front->value;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    free(temp);

    // If the queue is now empty, make the rear node the front
    if (q->front == NULL) {
        q->front = q->rear = NULL;
    }
    else {
        q->rear = q->rear->next;
    }

    // Decrement the size of the queue
    q->size--;

    return value;
}

// Function to display the contents of the queue
void display(struct Queue* q) {
    struct QueueNode* temp = q->front;

    printf("Queue contents:\n");
    while (temp!= NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}