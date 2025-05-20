//FormAI DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 //Maximum size of queue

//Implementation of queue using array
typedef struct Queue {
    int front, rear;
    int items[MAX_SIZE];
} Queue;

//Creates a new queue with empty front and rear
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

//Checks if the queue is full
int isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

//Checks if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

//Adds an item to the rear of the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("Added %d to the queue\n", item);
    }
}

//Removes an item from the front of the queue
int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("Removed %d from the queue\n", item);
    }
    return item;
}

int main() {
    Queue* queue = createQueue();

    //Adds items to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    enqueue(queue, 100);

    //Tries to add another item to the queue
    enqueue(queue, 110);

    //Removes items from the front of the queue
    int item1 = dequeue(queue);
    int item2 = dequeue(queue);
    int item3 = dequeue(queue);

    printf("Items dequeued: %d, %d, %d\n", item1, item2, item3);

    //Adds another item to the queue
    enqueue(queue, 110);

    //Removes the remaining items from the front of the queue
    while (!isEmpty(queue)) {
        int item = dequeue(queue);
    }

    //Tries to remove an item from the empty queue
    int item = dequeue(queue);

    return 0;
}