//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Queue Node
struct Node {
    int data;
    struct Node *next;
};

// Queue
struct Queue {
    struct Node *front;
    struct Node *rear;
    int size;
};

// Create a new queue
struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

// Add an element to the queue
void enqueue(struct Queue *queue, int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

// Remove an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->front->data;
    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    return data;
}

// Get the front element of the queue
int front(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

// Get the rear element of the queue
int rear(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->rear->data;
}

// Print the queue
void printQueue(struct Queue *queue) {
    struct Node *node = queue->front;
    printf("Queue: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    struct Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));
    return 0;
}