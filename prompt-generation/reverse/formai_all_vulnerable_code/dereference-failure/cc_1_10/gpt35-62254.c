//FormAI DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// define the maximum size of the queue
#define MAX_SIZE 100

// define the queue data structure
struct Queue {
    int front, rear;
    int items[MAX_SIZE];
};

// function to create a new queue and initialize it
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// function to check if queue is full
int isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// function to check if queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// function to add new item to queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("Added %d to queue.\n", item);
    }
}

// function to remove item from queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("Removed %d from queue.\n", item);
        return item;
    }
}

// function to print all items in queue
void display(struct Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Items in queue are:\n");
        for (i=queue->front; i<=queue->rear; i++) {
            printf("%d\n", queue->items[i]);
        }
    }
}

// main function to test the queue implementation
int main() {
    struct Queue* queue = createQueue();
    
    // add some items to queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    
    // display items in queue
    display(queue);
    
    // remove some items from queue
    dequeue(queue);
    dequeue(queue);
    
    // display items in queue again
    display(queue);
    
    // add more items to queue
    enqueue(queue, 60);
    enqueue(queue, 70);
    
    // display items in queue again
    display(queue);
    
    return 0;
}