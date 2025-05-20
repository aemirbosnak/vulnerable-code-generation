//FormAI DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10 // Maximum size of the queue

struct Queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
};

typedef struct Queue queue;

// Function to create an empty queue
queue* create_queue() {
    queue* q = (queue*) malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int is_full(queue* q) {
    if (q->front == 0 && q->rear == QUEUE_SIZE - 1) {
        return 1;
    }
    if (q->front == q->rear + 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int is_empty(queue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an item to the queue
void enqueue(queue* q, int item) {
    if (is_full(q)) {
        printf("Queue overflow!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % QUEUE_SIZE;
        q->items[q->rear] = item;
        printf("Enqueued %d.\n", item);
    }
}

// Function to remove an item from the queue
int dequeue(queue* q) {
    int item;
    if (is_empty(q)) {
        printf("Queue underflow!\n");
        return -1;
    } else {
        item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % QUEUE_SIZE;
        }
        printf("Dequeued %d.\n", item);
        return item;
    }
}

// Sample main function to demonstrate how the queue works
int main() {
    queue* q = create_queue();
    
    dequeue(q);
    enqueue(q, 1);
    dequeue(q);
    
    for (int i = 1; i <= 11; i++) {
        enqueue(q, i);
    }
    
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 11);
    enqueue(q, 12);
    
    while (!is_empty(q)) {
        dequeue(q);
    }
    dequeue(q);
    
    free(q);
    return 0;
}