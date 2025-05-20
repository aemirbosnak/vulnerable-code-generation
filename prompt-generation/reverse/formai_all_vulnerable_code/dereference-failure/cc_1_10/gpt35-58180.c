//FormAI DATASET v1.0 Category: Queue ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct Queue {
   int front, rear, size;
   int capacity;
   int* array;
} Queue;

Queue* createQueue(int capacity) {
   Queue* queue = (Queue*) malloc(sizeof(Queue));
   queue->capacity = capacity;
   queue->front = queue->size = 0;
   queue->rear = -1;
   queue->array = (int*) malloc(queue->capacity * sizeof(int));

   return queue;
}

int isFull(Queue* queue) {
   return queue->size == queue->capacity;
}

int isEmpty(Queue* queue) {
   return queue->size == 0;
}

void enqueue(Queue* queue, int item) {
   if (isFull(queue)) {
      printf("Queue is full\n");
      return;
   }

   queue->rear = (queue->rear + 1) % queue->capacity;
   queue->array[queue->rear] = item;
   queue->size++;
   printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
   if (isEmpty(queue)) {
      printf("Queue is empty\n");
      return -1;
   }

   int item = queue->array[queue->front];
   queue->front = (queue->front + 1) % queue->capacity;
   queue->size--;
   return item;
}

int main() {
   Queue* queue = createQueue(MAX_QUEUE_SIZE);

   enqueue(queue, 10);
   enqueue(queue, 20);
   enqueue(queue, 30);
   enqueue(queue, 40);
   enqueue(queue, 50);

   printf("\nElements in queue: \n");
   while (!isEmpty(queue)) {
      printf("%d \n", dequeue(queue));
   }
   return 0;
}