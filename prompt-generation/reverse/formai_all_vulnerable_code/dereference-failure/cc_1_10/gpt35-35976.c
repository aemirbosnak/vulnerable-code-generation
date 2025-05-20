//FormAI DATASET v1.0 Category: Queue ; Style: funny
#include <stdio.h>
#include <stdlib.h>

/* Queue data type in C */
typedef struct Queue {
    int front, rear;
    unsigned capacity;
    int *array;
} Queue;

/* Create queue */
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    printf("Creating queue of capacity %d...\n", capacity);
    return queue;
}

/* Check if queue is full */
int isFull(Queue* queue) {
    return queue->rear == queue->capacity-1;
}

/* Check if queue is empty */
int isEmpty(Queue* queue) {
    return queue->rear == -1 || queue->front > queue->rear;
}

/* Add item to queue */
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Sorry, queue is full! No more items can be added.\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
    printf("Enqueuing %d...\n", item);
}

/* Remove item from queue */
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Sorry, queue is empty! No more items can be dequeued.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    printf("Dequeuing %d...\n", item);
    return item;
}

/* Print all items in queue */
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Sorry, queue is empty! Nothing to print.\n");
        return;
    }
    printf("Printing all items in queue:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

/* Main function */
int main() {
    printf("Starting C Queue example program...\n");
    Queue* queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);    
    free(queue);
    printf("Exiting C Queue example program...\n");
    return 0;
}