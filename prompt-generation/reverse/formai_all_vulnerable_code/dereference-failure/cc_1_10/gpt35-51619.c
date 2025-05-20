//FormAI DATASET v1.0 Category: Queue ; Style: active
#include<stdio.h>
#include<stdlib.h>

// The structure of a Queue
struct Queue {
    int *arr; // Array to store elements
    int front; // Index of front element
    int rear; // Index of rear element
    int size; // Current size of queue
    int capacity; // Maximum capacity of queue
};

// Function to create and initialize a queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->arr = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to check if queue is empty
int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// Function to check if queue is full
int isFull(struct Queue* queue) {
    return queue->size == queue->capacity;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int element) {
    if(isFull(queue)) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }
    queue->rear = (queue->rear+1) % queue->capacity;
    queue->arr[queue->rear] = element;
    queue->size++;
    printf("%d inserted to queue\n", element);
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty. Cannot remove element.\n");
        return -1;
    }
    int element = queue->arr[queue->front];
    queue->front = (queue->front+1) % queue->capacity;
    queue->size--;
    printf("%d removed from queue\n", element);
    return element;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    printf("Elements in queue: ");
    int i;
    for(i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i % queue->capacity]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(5);

    // Add elements to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60); // Should display "Queue is full. Cannot insert element."

    // Display elements in the queue
    display(queue);

    // Remove elements from the queue
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue); // Should display "Queue is empty. Cannot remove element."

    return 0;
}