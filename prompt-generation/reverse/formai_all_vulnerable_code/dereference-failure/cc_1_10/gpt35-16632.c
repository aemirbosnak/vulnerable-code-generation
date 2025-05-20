//FormAI DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the queue

typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* q, int val);
int dequeue(Queue* q);
void display(Queue* q);

int main() {
    Queue* q = createQueue(); // Create a queue

    // Enqueue some elements into the queue
    printf("Enqueueing 10 elements into the queue...\n");
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);

    // Display the elements in the queue
    printf("The elements in the queue are: ");
    display(q);
    printf("\n");

    // Dequeue some elements from the queue
    printf("Dequeuing 5 elements from the queue...\n");
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    // Display the elements in the queue after dequeueing
    printf("The elements in the queue are: ");
    display(q);
    printf("\n");

    return 0;
}

// Function to create a queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to enqueue an element into the queue
void enqueue(Queue* q, int val) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue overflow!\n");
        return;
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = val;
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    int item;
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue underflow!\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        return item;
    }
}

// Function to display the elements in the queue
void display(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
        return;
    } else {
        for (int i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
    }
}