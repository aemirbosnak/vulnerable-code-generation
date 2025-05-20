//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h> 
#include <stdlib.h> 

struct Queue { 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 

struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1; 
    queue->array = (int*)malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 

int isFull(struct Queue* queue) 
{ 
    return (queue->size == queue->capacity); 
} 

int isEmpty(struct Queue* queue) 
{ 
    return (queue->size == 0); 
} 

void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1) % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    printf("%d enqueued to queue\n", item); 
} 

int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return -1; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 

int main() 
{ 
    struct Queue* queue = createQueue(5); 
    enqueue(queue, 1); 
    enqueue(queue, 2); 
    enqueue(queue, 3); 
    printf("%d dequeued from queue\n", dequeue(queue)); 
    printf("Front item is %d\n", queue->array[queue->front]); 
    printf("Rear item is %d\n", queue->array[queue->rear]); 
    return 0; 
}