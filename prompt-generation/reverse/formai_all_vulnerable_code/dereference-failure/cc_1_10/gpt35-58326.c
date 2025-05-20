//FormAI DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct queue {
    int *items;  // pointer to an array of integers to store queue elements
    int front, rear;  // front and rear represent index positions of frontmost 
                      // and rearmost element of queue respectively
} queue;

// function to create a queue of given size, dynamically allocates memory
queue* createQueue() {
    queue *q = malloc(sizeof(queue));
    q->items = malloc(MAX_QUEUE_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    return q;
}

// function to destroy the queue, frees the dynamically allocated memory
void destroyQueue(queue *q) {
    free(q->items);
    free(q);
}

// function to check if the queue is empty
int isEmpty(queue *q) {
    return q->front == -1;
}

// function to check if the queue is full
int isFull(queue *q) {
    return q->rear == MAX_QUEUE_SIZE-1;
}

// function to add an element to the rear end of the queue
void enqueue(queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full, cannot insert element.\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("%d has been enqueued to the queue\n", value);
    }
}

// function to remove and return the frontmost element of queue
int dequeue(queue *q) {
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue.\n");
        value = -1;
    } else {
        value = q->items[q->front];
        if (q->front >= q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        printf("%d dequeued from the queue\n", value);
    }
    return value;
}

// function to print the contents of the queue
void display(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Contents of the queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    queue *q = createQueue();

    // adding elements to queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // attempt to add more elements to already full queue
    enqueue(q, 60);

    // printing queue contents
    display(q);

    // removing elements from queue
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    // attempting to remove elements from empty queue
    dequeue(q);

    destroyQueue(q);
    return 0;
}