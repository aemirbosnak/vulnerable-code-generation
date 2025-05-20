//FormAI DATASET v1.0 Category: Queue ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

// Creating a struct for our Queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a new Queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->capacity = capacity;
    Q->front = Q->size = 0;
    Q->rear = capacity - 1;
    Q->array = (int*)malloc(Q->capacity * sizeof(int));
    return Q;
}

// Function to check if Queue is full
int isFull(struct Queue* Q) {
    return (Q->size == Q->capacity);
}

// Function to check if Queue is empty
int isEmpty(struct Queue* Q) {
    return (Q->size == 0);
}

// Function to add element to Queue
void enqueue(struct Queue* Q, int item) {
    if (isFull(Q)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = item;
    Q->size++;
    printf("%d enqueued to Queue\n", item);
}

// Function to remove element from Queue
int dequeue(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = Q->array[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    Q->size--;
    return item;
}

// Function to get front element of Queue
int front(struct Queue* Q) {
    if (isEmpty(Q))
        return -1;
    return Q->array[Q->front];
}

// Function to get rear element of Queue
int rear(struct Queue* Q) {
    if (isEmpty(Q))
        return -1;
    return Q->array[Q->rear];
}

int main() {
    struct Queue* Q = createQueue(5); // Creating a queue with capacity of 5

    enqueue(Q, 10); // Enqueueing elements
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    enqueue(Q, 50);

    enqueue(Q, 100); // Trying to enqueue when Queue is full

    printf("Front element of Queue is %d\n", front(Q)); // Printing front and rear elements
    printf("Rear element of Queue is %d\n", rear(Q));

    printf("%d dequeued from the Queue\n", dequeue(Q)); // Dequeuing elements
    printf("%d dequeued from the Queue\n", dequeue(Q));

    printf("Front element of Queue is %d\n", front(Q)); // Printing front and rear elements
    printf("Rear element of Queue is %d\n", rear(Q));

    enqueue(Q, 60); // Enqueueing elements
    enqueue(Q, 70);

    printf("Front element of Queue is %d\n", front(Q)); // Printing front and rear elements
    printf("Rear element of Queue is %d\n", rear(Q));

    return 0;
}