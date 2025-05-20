//FormAI DATASET v1.0 Category: Queue Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// The structure for the queue
struct queue{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create the queue
struct queue* createQueue(unsigned capacity){
    struct queue* q = (struct queue*) malloc(sizeof(struct queue)); // Allocate memory for the queue

    // Initialize the queue
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->array = (int*) malloc(q->capacity * sizeof(int));  // Allocate memory for the queue elements

    return q;
}

// Function to check if the queue is full
int isFull(struct queue* q){
    return (q->size == q->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct queue* q){
    return (q->size == 0);
}

// Function to insert an element into the queue
void enqueue(struct queue* q, int item){
    if (isFull(q)){  // Check if the queue is full
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;  // Update the rear index
    q->array[q->rear] = item;  // Insert the element
    q->size++;  // Increase the size of the queue
    printf("%d enqueued to the queue.\n", item);
}

// Function to remove an element from the queue
int dequeue(struct queue* q){
    int item;
    if (isEmpty(q)){  // Check if the queue is empty
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    item = q->array[q->front];  // Get the front element
    q->front = (q->front + 1) % q->capacity;  // Update the front index
    q->size--;  // Decrease the size of the queue
    return item;  // Return the dequeued element
}

// Function to get the front element of the queue
int front(struct queue* q){
    if (isEmpty(q)){  // Check if the queue is empty
        printf("Queue is empty! Cannot get front element.\n");
        return -1;
    }
    return q->array[q->front];  // Return the front element
}

// Function to get the rear element of the queue
int rear(struct queue* q){
    if (isEmpty(q)){  // Check if the queue is empty
        printf("Queue is empty! Cannot get rear element.\n");
        return -1;
    }
    return q->array[q->rear];  // Return the rear element
}

// Main Function
int main(){
    struct queue* q = createQueue(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);

    printf("%d dequeued from the queue\n", dequeue(q));
    printf("Front item is %d\n", front(q));
    printf("Rear item is %d\n", rear(q));

    return 0;
}