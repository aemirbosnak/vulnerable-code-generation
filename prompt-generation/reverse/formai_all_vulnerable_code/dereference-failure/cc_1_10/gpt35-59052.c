//FormAI DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int *arr; // The array for storage
    int front; // The index of front element
    int rear; // The index of rear element
    int size; // The size of the queue
} queue;

// Initialize an empty queue
queue *init_queue() {
    queue *q = (queue*) malloc(sizeof(queue));
    q->arr = (int*) malloc(sizeof(int) * MAX_QUEUE_SIZE);
    q->front = q->rear = -1;
    q->size = 0;
    return q;
}

// Check if queue is empty
int is_empty(queue *q) {
    return q->size == 0;
}

// Check if queue is full
int is_full(queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

// Add an element to the queue
void enqueue(queue *q, int val) {
    if (is_full(q)) {
        printf("Queue is full, cannot add element.\n");
        return;
    }
    
    if (q->rear == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
    
    q->arr[q->rear] = val;
    q->size++;
}

// Remove an element from the queue
int dequeue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot remove element.\n");
        return -1;
    }
    
    int val = q->arr[q->front];
    
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    
    q->size--;
    return val;
}

// Print the contents of the queue
void print_queue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("[ ");
    
    int curr = q->front;
    for (int i = 0; i < q->size; ++i) {
        printf("%d ", q->arr[curr]);
        curr = (curr + 1) % MAX_QUEUE_SIZE;
    }
    
    printf("]\n");
}

int main() {
    queue *q = init_queue();
    
    /* adds elements to the queue */
    printf("Adding elements to queue...\n");
    for (int i = 1; i <= 5; ++i) {
        enqueue(q, i);
    }
    
    /* prints the contents of the queue */
    printf("Queue contents after adding elements: ");
    print_queue(q);
    
    /* removes an element from the queue */
    printf("Removing one element from queue...\n");
    dequeue(q);
    
    /* prints the contents of the queue */
    printf("Queue contents after removing element: ");
    print_queue(q);
    
    /* adds elements to the queue */
    printf("Adding more elements to queue...\n");
    for (int i = 6; i <= 10; ++i) {
        enqueue(q, i);
    }
    
    /* prints the contents of the queue */
    printf("Queue contents after adding more elements: ");
    print_queue(q);
    
    /* tries to add more elements (queue is full) */
    printf("Trying to add more elements to queue...\n");
    for (int i = 11; i <= 15; ++i) {
        enqueue(q, i);
    }
    
    /* removes elements from the queue */
    printf("Removing elements from queue...\n");
    while (!is_empty(q)) {
        printf("%d ", dequeue(q));
    }
    
    /* prints the contents of the queue */
    printf("\nQueue contents after removing all elements: ");
    print_queue(q);
    
    free(q->arr);
    free(q);
    
    return 0;
}