//FormAI DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue structure
struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Function to create a queue
struct Queue* createQueue()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if queue is empty
int isEmpty(struct Queue* queue)
{
    return queue->front == -1 && queue->rear == -1;
}

// Function to check if queue is full
int isFull(struct Queue* queue)
{
    return queue->rear == MAX_SIZE - 1;
}

// Function to add element to queue
void enqueue(struct Queue* queue, int x)
{
    if (isFull(queue)) {
        printf("\nSorry, Queue is full and we can't add more elements");
        return;
    }
    else if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    }
    else {
        queue->rear++;
    }
    queue->arr[queue->rear] = x;
    printf("\nElement %d has been successfully added to the queue", x);
}

// Function to remove element from queue
void dequeue(struct Queue* queue)
{
    if (isEmpty(queue)) {
        printf("\nSorry, Queue is empty and we can't remove any elements");
        return;
    }
    else if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    }
    else {
        queue->front++;
    }
    printf("\nElement %d has been successfully removed from the queue", queue->arr[queue->front]);
}

// Function to display queue elements
void display(struct Queue* queue)
{
    if (isEmpty(queue)) {
        printf("\nSorry, Queue is empty and there are no elements to display");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
}

// Main function
int main()
{
    struct Queue* queue = createQueue();

    printf("Welcome to our Queue! Let's add some elements...\n");

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    enqueue(queue, 20);
    display(queue);

    printf("\n\nNow let's remove an element from the queue...\n");

    dequeue(queue);
    display(queue);

    printf("\n\nThanks for using our Queue! Happy programming :)");

    return 0;
}