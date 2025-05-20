//FormAI DATASET v1.0 Category: Queue ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
// MAX_SIZE is the size of our queue

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};
//We have a queue structure that stores the front, rear and items of the queue.

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
// We have a function that creates the queue by allocating space for it using malloc. The front and rear values are initialized to -1.

int isFull(struct Queue* queue) {
    if(queue->rear == MAX_SIZE - 1) return 1;
    else return 0;
}
// We also check if the Queue is full or not. It returns 1 if it is full, otherwise 0.

int isEmpty(struct Queue* queue) {
    if(queue->front == -1) return 1;
    else return 0;
}
// Similarly, we check if the Queue is empty. It returns 1 if it is empty, otherwise 0.

void enqueue(struct Queue* queue, int value) {
    if(isFull(queue)) printf("Queue is full\n");
    else {
        if(queue->front == -1) queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Inserted %d into queue\n", value);
    }
}
// When we want to insert a value in the queue, we first check if the queue is full or not. If it is not full, we increment the rear and insert the value at that index.

int dequeue(struct Queue* queue) {
    int item;
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    else {
        item = queue->items[queue->front];
        queue->front++;
        if(queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("Removed %d from queue\n", item);
        return item;
    }
}
// If we want to remove an item from the queue, we first check if the queue is empty or not. If it is empty, we display a message and return -1. Otherwise, we remove the item from the front of the queue and increment the front. If the front is greater than the rear then we set the front and rear to -1.

void display(struct Queue* queue) {
    int i;
    if(isEmpty(queue)) printf("Queue is empty\n");
    else {
        printf("Queue contains: ");
        for(i=queue->front; i<=queue->rear; i++) printf("%d ", queue->items[i]);
        printf("\n");
    }
}
// To display the content of the queue, we traverse all the elements of the queue starting from the front up to the rear.

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 20);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    return 0;
}
// In the main function, we create a new queue, and enqueue some values into it. We then display the contents of the queue. Finally, we dequeue two items from the queue and display the contents again.