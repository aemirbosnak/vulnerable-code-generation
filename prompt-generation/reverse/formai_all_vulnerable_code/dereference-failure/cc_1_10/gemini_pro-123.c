//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: innovative
// Queue Implementation with Linked List
#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node *next;
};

// Queue Structure
struct Queue {
    struct Node *front;
    struct Node *rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

// Function to enqueue (insert at the end of queue)
void enqueue(struct Queue *queue, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue (remove from the front of queue)
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int data = queue->front->data;
    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

// Function to print the queue
void printQueue(struct Queue *queue) {
    struct Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Queue *queue = createQueue();

    // Enqueue some elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printQueue(queue);

    // Dequeue some elements
    dequeue(queue);
    dequeue(queue);

    // Print the queue again
    printQueue(queue);

    return 0;
}