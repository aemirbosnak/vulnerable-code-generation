//FormAI DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

// Queue Structure
struct Queue{
    int front, rear, size;
    unsigned int capacity;
    int *array;
};

// Create Queue
struct Queue* createQueue(unsigned int capacity){
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if Queue is Full
int isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}

// Check if Queue is Empty
int isEmpty(struct Queue* queue){
    return (queue->size == 0);
}

// Add Element to Queue
void enqueue(struct Queue* queue, int item){
    if (isFull(queue))
        return;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size += 1;
}

// Remove Element from Queue
int dequeue(struct Queue* queue){
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->size -= 1;
    return item;
}

// Print Queue Elements
void printQueue(struct Queue* queue){
    if (isEmpty(queue))
        printf("Queue is Empty\n");
    else{
        printf("Queue has Elements: ");
        int count = 0;
        for(int i = queue->front; count < queue->size; i = (i+1)%queue->capacity){
            printf("%d ", queue->array[i]);
            count++;
        }
        printf("\n");
    }
}

// Main Function
int main(){
    struct Queue* queue = createQueue(5);
    printf("Queue Initialized with Capacity 5...\n");

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    printf("\nElements Added to Queue...\n");

    printQueue(queue);
    printf("\n");

    int element = dequeue(queue);
    printf("Element Dequeued: %d\n", element);

    printQueue(queue);
    printf("\n");

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("Removing Elements from Queue...\n");

    printQueue(queue);
    printf("\n");

    enqueue(queue, 5);
    enqueue(queue, 6);
    printf("Adding Elements to Queue...\n");

    printQueue(queue);
    printf("\n");

    free(queue->array);
    free(queue);
    printf("Queue Memory Freed...\n");

    return 0;
}