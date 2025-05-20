//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct Queue {
    int front, rear;
    char* items[MAX_SIZE];
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Function to add an item to the queue
void enqueue(Queue* q, char* item) {
    if (isFull(q)) {
        printf("Queue Overflow! The queue is full, cannot enqueue '%s'.\n", item);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = strdup(item); // Duplicate the string
    printf("Enqueued: '%s' into the magical queue.\n", item);
}

// Function to remove an item from the queue
char* dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! The queue is empty, cannot dequeue.\n");
        return NULL;
    }
    char* item = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    printf("Dequeued: '%s' from the enchanted queue.\n", item);
    return item;
}

// Function to view the front item of the queue
char* peek(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    return q->items[q->front];
}

// Function to display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty, no magic to see here!\n");
        return;
    }
    printf("Magical Queue: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (q->items[i] != NULL) {
            printf("%s ", q->items[i]);
        }
    }
    printf("\n");
}

// Function to free the queue
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        char* item = dequeue(q);
        free(item); // Free the duplicated string
    }
    free(q);
}

int main() {
    Queue* magicalQueue = createQueue();
    
    enqueue(magicalQueue, "A spell of courage");
    enqueue(magicalQueue, "A charm of wisdom");
    enqueue(magicalQueue, "An incantation of joy");
    enqueue(magicalQueue, "A potion of strength");
    enqueue(magicalQueue, "A hex of adventure");
    // Attempt to add one more, to test overflowing
    enqueue(magicalQueue, "A curse of misfortune");

    display(magicalQueue);
    
    printf("Peeking the front: '%s'\n", peek(magicalQueue));

    char* item;
    
    item = dequeue(magicalQueue);
    free(item);
    display(magicalQueue);
    
    item = dequeue(magicalQueue);
    free(item);
    display(magicalQueue);
    
    item = dequeue(magicalQueue);
    free(item);
    display(magicalQueue);
    
    item = dequeue(magicalQueue);
    free(item);
    display(magicalQueue);
    
    item = dequeue(magicalQueue);
    free(item);
    display(magicalQueue);
    
    item = dequeue(magicalQueue); // Should show underflow message
    free(item);
    
    // Clean up the remaining dynamically allocated memory
    freeQueue(magicalQueue);
    
    return 0;
}