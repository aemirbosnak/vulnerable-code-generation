//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct queue {
    int *data;
    int front;
    int rear;
};

// Function to enqueue elements in the queue
void enqueue(struct queue *q, int item) {
    // Allocate memory for the new node
    int *new_node = (int *)malloc(sizeof(int));
    *new_node = item;
    
    // If the queue is empty, set the front and rear pointers to the new node
    if (q->rear == -1) {
        q->front = q->rear = 0;
    }
    // Otherwise, move the rear pointer to the new node
    else {
        q->rear++;
    }
    
    // Add the new node to the end of the queue
    q->data[q->rear] = new_node;
}

// Function to dequeue elements from the queue
int dequeue(struct queue *q) {
    // Check if the queue is empty
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    // Move the front pointer to the next node
    int *item = q->data[q->front];
    q->front++;
    
    // If the queue is not empty, decrement the rear pointer
    if (q->rear!= -1) {
        q->rear--;
    }
    
    // Free the memory occupied by the dequeued node
    free(item);
    
    // Return the dequeued item
    return *item;
}

// Function to check if the queue is empty
int is_empty(struct queue *q) {
    // Check if the front pointer is -1
    return (q->front == -1);
}

// Main function
int main() {
    struct queue my_queue;
    
    // Create a new queue
    my_queue.data = NULL;
    my_queue.front = -1;
    my_queue.rear = -1;
    
    // Enqueue some elements
    enqueue(&my_queue, 1);
    enqueue(&my_queue, 2);
    enqueue(&my_queue, 3);
    
    // Print the elements in the queue
    int item;
    while (!is_empty(&my_queue)) {
        item = dequeue(&my_queue);
        printf("%d ", item);
    }
    printf("\n");
    
    // Dequeue the last element
    item = dequeue(&my_queue);
    printf("Dequeued item: %d\n", item);
    
    // Print the elements in the queue after dequeuing
    while (!is_empty(&my_queue)) {
        item = dequeue(&my_queue);
        printf("%d ", item);
    }
    printf("\n");
    
    // Free the memory occupied by the queue
    free(my_queue.data);
    
    return 0;
}