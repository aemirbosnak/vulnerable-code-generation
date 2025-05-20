//FormAI DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue {
   int items[MAX_QUEUE_SIZE];
   int front;
   int rear;
} Queue;

/*
 * Function to create an empty queue
 */
Queue* createQueue() {
   Queue* queue = malloc(sizeof(Queue));
   queue->front = -1;
   queue->rear = -1;
   return queue;
}

/*
 * Function to check if the queue is empty
 */
int isEmpty(Queue* queue) {
   if (queue->rear == -1)
      return 1;
   else
      return 0;
}

/*
 * Function to check if the queue is full
 */
int isFull(Queue* queue) {
   if (queue->rear == MAX_QUEUE_SIZE - 1)
      return 1;
   else
      return 0;
}

/*
 * Function to add an element to the queue
 */
void enqueue(Queue* queue, int item) {
   if (isFull(queue)) {
      printf("Queue is full\n");
   } else {
      if (queue->front == -1)
         queue->front = 0;
      queue->rear++;
      queue->items[queue->rear] = item;
      printf("Enqueued %d\n", item);
   }
}

/*
 * Function to remove an element from the queue
 */
int dequeue(Queue* queue) {
   int item;
   if (isEmpty(queue)) {
      printf("Queue is empty\n");
      item = -1;
   } else {
      item = queue->items[queue->front];
      queue->front++;
      if (queue->front > queue->rear) {
         printf("Resetting queue\n");
         queue->front = queue->rear = -1;
      }
   }
   return item;
}

int main() {
   Queue* queue = createQueue();

   printf("Is the queue empty? %d\n", isEmpty(queue));

   enqueue(queue, 10);
   enqueue(queue, 20);
   enqueue(queue, 30);
   enqueue(queue, 40);
   enqueue(queue, 50);

   printf("Removing element from queue: %d\n", dequeue(queue));
   printf("Removing element from queue: %d\n", dequeue(queue));

   printf("Is the queue empty? %d\n", isEmpty(queue));

   enqueue(queue, 60);
   enqueue(queue, 70);

   printf("Removing element from queue: %d\n", dequeue(queue));
   printf("Removing element from queue: %d\n", dequeue(queue));
   printf("Removing element from queue: %d\n", dequeue(queue));
   printf("Removing element from queue: %d\n", dequeue(queue));
   printf("Removing element from queue: %d\n", dequeue(queue));

   printf("Is the queue empty? %d\n", isEmpty(queue));

   return 0;
}