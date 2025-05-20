//FormAI DATASET v1.0 Category: Queue ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // Maximum size of the queue

struct Queue {
    int front;
    int rear;
    int size;
    int* arr;
};

/* Function to create a new queue */
struct Queue* create_queue() {

    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

    q->arr = (int*)malloc(MAX_QUEUE_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;

    return q;
}

/* Function to check if the queue is empty */
int is_empty(struct Queue* q) {
    return (q->size == 0);
}

/* Function to check if the queue is full */
int is_full(struct Queue* q) {
    return (q->size == MAX_QUEUE_SIZE);
}

/* Function to add an item to the queue */
void enqueue(struct Queue* q, int item) {

    if (is_full(q)) {
        printf("Queue Overflow\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->arr[q->rear] = item;
    q->size++;

    if (q->front == -1) {
        q->front = q->rear;
    }
}

/* Function to remove an item from the queue */
int dequeue(struct Queue* q) {

    if (is_empty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }

    int item = q->arr[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;

    return item;
}

/* Function to display the contents of the queue */
void display(struct Queue* q) {

    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements of the queue are : ");

    int i;
    for (i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_QUEUE_SIZE;
        printf("%d ", q->arr[index]);
    }

    printf("\n");
}

/* Main function to test the queue */
int main() {

    struct Queue* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    printf("Dequeued item : %d\n", dequeue(q));

    display(q);

    enqueue(q, 50);
    enqueue(q, 60);

    display(q);

    return 0;
}