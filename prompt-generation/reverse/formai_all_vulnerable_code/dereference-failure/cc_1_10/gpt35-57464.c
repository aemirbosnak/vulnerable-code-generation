//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // maximum size of the queue

/* defining the structure of the queue */
typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

/* function to check if the queue is full */
int isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

/* function to check if the queue is empty */
int isEmpty(Queue* queue) {
    return queue->rear == -1;
}

/* function to add an item to the queue */
void enQueue(Queue* queue, int item) {
    /* check if the queue is full and raise an error */
    if (isFull(queue)) {
        printf("\nQueue is full!\n");
        return;
    }

    /* if the queue is empty, set the front to 0 */
    if (isEmpty(queue)) {
        queue->front = 0;
    }

    /* add the item to the queue and increment the rear */
    queue->rear++;
    queue->items[queue->rear] = item;
    printf("\nInserted Item: %d\n", item);
}

/* function to remove an item from the queue */
int deQueue(Queue* queue) {
    /* check if the queue is empty and raise an error */
    if (isEmpty(queue)) {
        printf("\nQueue is empty!\n");
        return -1;
    }

    /* retrieve the item from the front of the queue and increment the front */
    int item = queue->items[queue->front];
    queue->front++;

    /* if the queue has become empty, reset the front and rear */
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    printf("\nRemoved Item: %d\n", item);
    return item;
}

/* function to display the contents of the queue */
void displayQueue(Queue* queue) {
    /* check if the queue is empty and raise an error */
    if (isEmpty(queue)) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\nQueue contents: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

/* main function to run the program */
int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue)); // allocate memory for the queue

    queue->front = -1;
    queue->rear = -1;

    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);
    enQueue(queue, 40);

    displayQueue(queue);

    deQueue(queue);
    deQueue(queue);

    displayQueue(queue);

    enQueue(queue, 50);

    displayQueue(queue);

    return 0;
}