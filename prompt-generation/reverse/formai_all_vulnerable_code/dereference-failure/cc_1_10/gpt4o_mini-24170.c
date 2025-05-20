//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Queue structure definition
typedef struct Queue {
    int *items;
    int front;
    int rear;
    int max_size;
} Queue;

// Function to create a new queue
Queue* createQueue(int size) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->max_size = size;
    q->front = -1;
    q->rear = -1;
    q->items = (int*)malloc(size * sizeof(int));
    return q;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear + 1) % q->max_size == q->front;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to add an item to the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full, brave soul! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->max_size;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an item from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, valiant knight. Cannot dequeue.\n");
        return -1; // Indicating an empty queue
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1; // Queue has become empty
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->max_size;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

// Function to display the queue contents
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, nothing to display.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = 0; i < q->max_size; i++) {
        int index = (q->front + i) % q->max_size;
        if (i <= (q->rear - q->front + q->max_size) % q->max_size) {
            printf("%d ", q->items[index]);
        }
    }
    printf("\n");
}

// Main function to demonstrate the queue
int main() {
    int size = 5;
    Queue *q = createQueue(size);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60); // This should trigger a full message

    displayQueue(q);

    dequeue(q);
    dequeue(q);
    
    displayQueue(q);
    
    enqueue(q, 60);
    enqueue(q, 70);

    displayQueue(q);

    // Clean up
    free(q->items);
    free(q);
    
    return 0;
}