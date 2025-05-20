//FormAI DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include <stdio.h> 
#include <stdlib.h> 

// Define the queue structure 
typedef struct { 
   int front, rear, size; 
   unsigned capacity; 
   int* array; 
} Queue; 

// Create a queue 
Queue* createQueue(unsigned capacity) 
{ 
    Queue* queue = (Queue*) malloc(sizeof(Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1;  
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 
  
// Check if queue is full 
int isFull(Queue* queue) 
{  return (queue->size == queue->capacity); } 
  
// Check if queue is empty 
int isEmpty(Queue* queue) 
{  return (queue->size == 0); } 
  
// Add an item to the queue 
void enqueue(Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1) % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
} 
  
// Remove an item from the queue 
int dequeue(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return -1; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Return the front item of the queue 
int front(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return -1; 
    return queue->array[queue->front]; 
} 
  
// Return the rear item of the queue 
int rear(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return -1; 
    return queue->array[queue->rear]; 
} 


// Main function
int main() 
{ 
    Queue* queue = createQueue(10); 
  
    enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 
  
    printf("%d dequeued from queue\n\n", dequeue(queue)); 
  
    printf("Front item is %d\n", front(queue)); 
    printf("Rear item is %d\n", rear(queue)); 
  
    return 0; 
}