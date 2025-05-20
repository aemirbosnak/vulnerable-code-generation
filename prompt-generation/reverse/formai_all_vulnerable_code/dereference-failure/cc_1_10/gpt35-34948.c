//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/* create a queue structure */
struct queue {
    int items[SIZE];
    int front;
    int rear;
};

/* function to create a queue */
struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

/* function to check if the queue is empty */
int isEmpty(struct queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

/* function to add an item to the queue */
void enqueue(struct queue* q, int value) {
    if (q->rear == SIZE - 1)
        printf("Queue is full!\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d successfully!\n", value);
    }
}

/* function to remove an item from the queue */
int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            printf("Resetting queue!\n");
            q->front = q->rear = -1;
        }
        return item;
    }
}

/* main function to test the queue */
int main() {
    struct queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    printf("Queue has: %d, %d, %d, %d\n", q->items[0], q->items[1], q->items[2], q->items[3]);
    dequeue(q);
    printf("Queue has: %d, %d, %d\n", q->items[0], q->items[1], q->items[2]);
    enqueue(q, 50);
    printf("Queue has: %d, %d, %d, %d\n", q->items[0], q->items[1], q->items[2], q->items[3]);
    dequeue(q);
    printf("Queue has: %d, %d, %d\n", q->items[0], q->items[1], q->items[2]);
    return 0;
}