//FormAI DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int rear, front;
    int items[MAX_SIZE];
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full or not
int isFull(Queue* q) {
    if (q->rear == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is empty or not
int isEmpty(Queue* q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add an item to the queue
void enqueue(Queue* q, int element) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = element;
        printf("Inserted element %d\n", element);
    }
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    int element;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        element = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        printf("Deleted element %d\n", element);
        return element;
    }
}

// Function to display the elements of the queue
void display(Queue* q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are:\n");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    display(q);

    dequeue(q);
    dequeue(q);

    display(q);

    enqueue(q, 5);
    enqueue(q, 6);

    display(q);

    return 0;
}