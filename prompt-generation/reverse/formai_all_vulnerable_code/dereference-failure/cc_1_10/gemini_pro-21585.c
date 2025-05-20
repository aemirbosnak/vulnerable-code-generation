//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int front, rear, size;
    int *array;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == queue->size - 1);
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->array[queue->rear] = item;
        printf("%d inserted\n", item);
    }
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return (-1);
    }
    else {
        item = queue->array[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
            queue->front = queue->rear = -1;
        printf("%d deleted\n", item);
        return (item);
    }
}

// Print the queue
void printQueue(Queue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->array[i]);
        printf("\n");
    }
}

// Free the queue
void freeQueue(Queue *queue) {
    if (queue) {
        if (queue->array)
            free(queue->array);
        free(queue);
    }
}

// Driver program to test the queue
int main() {
    int choice, item;
    Queue *queue;

    // Create a queue of size 5
    queue = createQueue(5);

    // Perform queue operations
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            enqueue(queue, item);
            break;
        case 2:
            item = dequeue(queue);
            break;
        case 3:
            printQueue(queue);
            break;
        case 4:
            freeQueue(queue);
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}