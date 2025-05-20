//FormAI DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// define queue struct
typedef struct Queue {
    int arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// function to create queue
Queue* create_queue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// function to check if queue is full
int is_full(Queue* queue) {
    return (queue->size >= MAX_QUEUE_SIZE);
}

// function to check if queue is empty
int is_empty(Queue* queue) {
    return (queue->size == 0);
}

// function to add an item to the queue
void enqueue(Queue* queue, int data) {
    if(!is_full(queue)) {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        queue->arr[queue->rear] = data;
        queue->size++;
    } else {
        printf("Queue is full!\n");
    }
}

// function to remove an item from the queue
int dequeue(Queue* queue) {
    if(!is_empty(queue)) {
        int data = queue->arr[queue->front];
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        queue->size--;
        return data;
    } else {
        printf("Queue is empty!\n");
        return -1;
    }
}

// function to display the elements in the queue
void display(Queue* queue) {
    if(!is_empty(queue)) {
        printf("Queue: ");
        int i;
        for(i = 0; i < queue->size; i++) {
            printf("%d ", queue->arr[(queue->front + i) % MAX_QUEUE_SIZE]);
        }
        printf("\n");
    } else {
        printf("Queue is empty!\n");
    }
}

// main function
int main() {
    Queue* queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    display(queue); // Output: Queue: 1 2 3 4
    dequeue(queue);
    dequeue(queue);
    display(queue); // Output: Queue: 3 4
    enqueue(queue, 5);
    enqueue(queue, 6);
    display(queue); // Output: Queue: 3 4 5 6
    return 0;
}