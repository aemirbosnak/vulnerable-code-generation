//FormAI DATASET v1.0 Category: Queue Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>

/* Queue Structure Definition */
struct queue {
    int front, rear;
    unsigned capacity;
    int* array;
};

/* Function to create a queue of specified capacity */
struct queue* createQueue(unsigned capacity) {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->array = (int*) malloc(q->capacity * sizeof(int));
    return q;
}

/* Function to check if the queue is full */
int isFull(struct queue* q) {
    return (q->rear == q->capacity - 1 && q->front == 0) || (q->rear + 1 == q->front);
}

/* Function to check if the queue is empty */
int isEmpty(struct queue* q) {
    return q->front == -1;
}

/* Function to enqueue an element into the queue */
void enqueue(struct queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    printf("%d enqueued to the queue\n", item);
}

/* Function to dequeue an element from the queue */
int dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    int item = q->array[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % q->capacity;
    printf("%d dequeued from the queue\n", item);
    return item;
}

/* Function to display elements of the queue */
void display(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the queue are: ");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % q->capacity)
        printf("%d ", q->array[i]);
    printf("%d", q->array[q->rear]);
}

/* Main function */
int main() {
    struct queue* q = createQueue(5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6); // This will fail as the queue is full
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q); // This will fail as the queue is empty
    display(q);
    return 0;
}