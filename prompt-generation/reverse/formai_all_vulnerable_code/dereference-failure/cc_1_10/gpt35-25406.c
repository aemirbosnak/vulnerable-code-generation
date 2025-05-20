//FormAI DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Unique structure for queue implementation
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// Function to create a queue of given capacity
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    
    // Allocate queue data and set initial values
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // Rear points to last element in queue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
 
    return queue;
}
 
// Check if queue is full
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
 
// Check if queue is empty
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
 
// Add an element to the queue
void enqueue(struct Queue* queue, int item)
{
    // Check if queue is full
    if (isFull(queue))
        return;
    
    // Increment rear pointer and add item
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d added to queue.\n", item);
}
 
// Remove an element from the queue
int dequeue(struct Queue* queue)
{
    // Check if queue is empty
    if (isEmpty(queue))
        return -1;
 
    // Get the first item and increment front pointer
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    printf("%d removed from queue.\n", item);
    return item;
}
 
// Get queue front element (peek)
int front(struct Queue* queue)
{
    // Check if queue is empty
    if (isEmpty(queue))
        return -1;
 
    return queue->array[queue->front];
}
 
// Get queue rear element
int rear(struct Queue* queue)
{
    // Check if queue is empty
    if (isEmpty(queue))
        return -1;
 
    return queue->array[queue->rear];
}

int main()
{
    // Create a queue of capacity 5
    struct Queue* queue = createQueue(5);
 
    // Add elements to queue (1-5)
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    
    // Attempt to add another element to full queue, should fail
    enqueue(queue, 6);
    
    // Remove elements from queue (1-5)
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    
    // Attempt to remove another element from empty queue, should fail
    dequeue(queue);
 
    return 0;
}