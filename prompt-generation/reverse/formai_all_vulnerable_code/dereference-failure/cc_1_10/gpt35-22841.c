//FormAI DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

// Define the structure of the queue
struct Queue{
    int front, rear;
    int capacity, size;
    int *array;
};

// Create a queue using the given capacity
struct Queue* createQueue(int cap){
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = cap;
    queue->front = queue->size = 0;
    queue->rear = cap - 1;
    queue->array = (int*)malloc(queue->capacity*sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(struct Queue *queue){
    return (queue->size == queue->capacity);
}

// Check if the queue is empty
int isEmpty(struct Queue *queue){
    return (queue->size == 0);
}

// Add an element to the queue
void enqueue(struct Queue *queue, int item){
    if(isFull(queue)){
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to the queue\n", item);
}

// Remove an element from the queue
int dequeue(struct Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    printf("%d dequeued from the queue\n", item);
    return item;
}

// Get the front element of the queue
int front(struct Queue *queue){
    if(isEmpty(queue)){
        return -1;
    }
    return queue->array[queue->front];
}

// Get the rear element of the queue
int rear(struct Queue *queue){
    if(isEmpty(queue)){
        return -1;
    }
    return queue->array[queue->rear];
}

// Testing the queue implementation
int main(){
    // Create a queue of capacity 5
    struct Queue *queue = createQueue(5);

    // Add elements to the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Attempt to add element to the full queue
    enqueue(queue, 6);

    // Get the front and rear elements of the queue
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    // Remove elements from the queue
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Add more elements to the queue
    enqueue(queue, 6);
    enqueue(queue, 7);

    // Get the front element of the queue
    printf("Front element: %d\n", front(queue));

    return 0;
}