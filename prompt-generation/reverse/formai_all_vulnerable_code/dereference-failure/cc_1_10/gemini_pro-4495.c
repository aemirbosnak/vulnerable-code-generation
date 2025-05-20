//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Queue node
struct QueueNode {
    int data;
    struct QueueNode *next;
};

// Queue
struct Queue {
    struct QueueNode *front, *rear;
    int size;
};

// Create a new queue
struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Check if queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == NULL);
}

// Enqueue an element
void enqueue(struct Queue *queue, int data) {
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// Dequeue an element
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    queue->size--;
    free(temp);
    return data;
}

// Get the front element
int front(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->front->data;
}

// Get the rear element
int rear(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->rear->data;
}

// Print the queue
void printQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    struct QueueNode *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Destroy the queue
void destroyQueue(struct Queue *queue) {
    struct QueueNode *temp;
    while (queue->front != NULL) {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

// Driver code
int main() {
    struct Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printQueue(queue);

    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));

    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));

    destroyQueue(queue);

    return 0;
}