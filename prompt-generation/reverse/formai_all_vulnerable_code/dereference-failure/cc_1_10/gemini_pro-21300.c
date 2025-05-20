//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macros for queue operations
#define ENQUEUE(queue, element) (queue->rear = (queue->rear + 1) % queue->size, queue->array[queue->rear] = element)
#define DEQUEUE(queue) (queue->front = (queue->front + 1) % queue->size, queue->array[queue->front])
#define IS_EMPTY(queue) (queue->front == queue->rear)
#define IS_FULL(queue) ((queue->rear + 1) % queue->size == queue->front)

// Create a new queue
typedef struct Queue {
    int *array;
    int front;
    int rear;
    int size;
} Queue;

Queue *create_queue(int size) {
    Queue *queue = malloc(sizeof(Queue));
    queue->array = malloc(sizeof(int) * size);
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}

// Function to check if the queue is happy
int is_happy(Queue *queue) {
    int sum = 0;
    for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->size) {
        sum += queue->array[i];
    }
    return sum >= 0;
}

// Function to make the queue happy
void make_happy(Queue *queue) {
    while (!is_happy(queue)) {
        int element = DEQUEUE(queue);
        element = abs(element);
        ENQUEUE(queue, element);
    }
}

// Function to print the queue
void print_queue(Queue *queue) {
    for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->size) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    // Create a queue of size 5
    Queue *queue = create_queue(5);

    // Enqueue some elements into the queue
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int element = rand() % 10;
        ENQUEUE(queue, element);
    }

    // Check if the queue is happy
    if (is_happy(queue)) {
        printf("The queue is happy!\n");
    } else {
        printf("The queue is not happy.\n");
        make_happy(queue);
        printf("The queue is now happy!\n");
    }

    // Print the queue
    print_queue(queue);

    return 0;
}