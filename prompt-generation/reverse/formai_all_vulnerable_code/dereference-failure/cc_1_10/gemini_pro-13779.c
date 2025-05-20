//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
/*
 * A C Queue Implementation in the Style of Alan Turing
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * The Queue Structure
 */
typedef struct Queue {
  int *array;
  int head;
  int tail;
  int size;
} Queue;

/*
 * Create a new Queue
 */
Queue *createQueue(int size) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->array = (int *)malloc(size * sizeof(int));
  queue->head = 0;
  queue->tail = 0;
  queue->size = size;
  return queue;
}

/*
 * Destroy a Queue
 */
void destroyQueue(Queue *queue) {
  free(queue->array);
  free(queue);
}

/*
 * Enqueue an item into the Queue
 */
void enqueue(Queue *queue, int item) {
  if ((queue->tail + 1) % queue->size == queue->head) {
    printf("Queue is full\n");
    return;
  }

  queue->array[queue->tail] = item;
  queue->tail = (queue->tail + 1) % queue->size;
}

/*
 * Dequeue an item from the Queue
 */
int dequeue(Queue *queue) {
  if (queue->head == queue->tail) {
    printf("Queue is empty\n");
    return -1;
  }

  int item = queue->array[queue->head];
  queue->head = (queue->head + 1) % queue->size;
  return item;
}

/*
 * Print the Queue
 */
void printQueue(Queue *queue) {
  printf("Queue: ");
  for (int i = queue->head; i != queue->tail; i = (i + 1) % queue->size) {
    printf("%d ", queue->array[i]);
  }
  printf("\n");
}

/*
 * Main Function
 */
int main() {
  Queue *queue = createQueue(5);

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  printQueue(queue);

  int item = dequeue(queue);
  printf("Dequeued item: %d\n", item);

  printQueue(queue);

  destroyQueue(queue);

  return 0;
}