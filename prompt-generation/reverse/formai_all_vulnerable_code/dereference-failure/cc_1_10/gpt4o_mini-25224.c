//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5  // Define the maximum size of the queue

typedef struct {
    int id;
    char name[30];
} Data;  // Custom data structure - can be modified as needed

typedef struct {
    Data *items;
    int front;
    int rear;
    int max_size;
    int current_size;
} Queue;

// Function to create a new Queue
Queue* create_queue(int size) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->max_size = size;
    q->front = -1;
    q->rear = -1;
    q->current_size = 0;
    q->items = (Data *) malloc(size * sizeof(Data));
    
    if (!q->items) {
        fprintf(stderr, "Memory allocation failed for queue items.\n");
        exit(EXIT_FAILURE);
    }
    
    return q;
}

// Function to check if the queue is empty
int is_empty(Queue *q) {
    return q->current_size == 0;
}

// Function to check if the queue is full
int is_full(Queue *q) {
    return q->current_size == q->max_size;
}

// Enqueue function to add an item to the queue
void enqueue(Queue *q, Data item) {
    if (is_full(q)) {
        fprintf(stderr, "Queue overflow - Cannot enqueue %d, %s\n", item.id, item.name);
        return;
    }
    
    q->rear = (q->rear + 1) % q->max_size;  // Circular increment
    q->items[q->rear] = item;
    
    if (q->front == -1) {
        q->front = 0;  // First element
    }
    
    q->current_size++;
    printf("Enqueued: %d, %s\n", item.id, item.name);
}

// Dequeue function to remove an item from the queue
Data dequeue(Queue *q) {
    Data item;
    
    if (is_empty(q)) {
        fprintf(stderr, "Queue underflow - Cannot dequeue\n");
        exit(EXIT_FAILURE);  // Exit if trying to dequeue from an empty queue
    }
    
    item = q->items[q->front];
    q->front = (q->front + 1) % q->max_size;  // Circular increment
    q->current_size--;
    
    if (is_empty(q)) {
        q->front = -1;
        q->rear = -1;  // Reset queue when empty
    }
    
    printf("Dequeued: %d, %s\n", item.id, item.name);
    return item;
}

// Function to display the queue
void display_queue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents:\n");
    for (int i = 0; i < q->current_size; i++) {
        int index = (q->front + i) % q->max_size;
        printf("ID: %d, Name: %s\n", q->items[index].id, q->items[index].name);
    }
}

// Function to free the queue
void free_queue(Queue *q) {
    free(q->items);
    free(q);
}

int main() {
    Queue *queue = create_queue(MAX_SIZE);
    
    Data data1 = {1, "John"};
    Data data2 = {2, "Doe"};
    Data data3 = {3, "Alice"};
    Data data4 = {4, "Bob"};
    Data data5 = {5, "Charlie"};
    Data data6 = {6, "David"}; // This will cause overflow

    enqueue(queue, data1);
    enqueue(queue, data2);
    enqueue(queue, data3);
    enqueue(queue, data4);
    enqueue(queue, data5);
    
    display_queue(queue);

    dequeue(queue);
    dequeue(queue);
    
    display_queue(queue);
    
    enqueue(queue, data6);  // Test the overflow condition

    while (!is_empty(queue)) {
        dequeue(queue);
    }

    display_queue(queue);
    
    free_queue(queue);
    return 0;
}