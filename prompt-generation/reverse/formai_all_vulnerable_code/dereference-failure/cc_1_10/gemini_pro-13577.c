//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the Romeo and Juliet types
typedef struct {
  int value;
  struct Romeo *next;
} Romeo;

typedef struct {
  int value;
  struct Juliet *next;
} Juliet;

// Define the Queue type
typedef struct {
  Romeo *head;
  Juliet *tail;
} Queue;

// Create a new Romeo
Romeo* newRomeo(int value) {
  Romeo *romeo = malloc(sizeof(Romeo));
  romeo->value = value;
  romeo->next = NULL;
  return romeo;
}

// Create a new Juliet
Juliet* newJuliet(int value) {
  Juliet *juliet = malloc(sizeof(Juliet));
  juliet->value = value;
  juliet->next = NULL;
  return juliet;
}

// Create a new Queue
Queue* newQueue() {
  Queue *queue = malloc(sizeof(Queue));
  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

// Enqueue a Romeo
void enqueueRomeo(Queue *queue, Romeo *romeo) {
  if (queue->head == NULL) {
    queue->head = romeo;
    queue->tail = romeo;
  } else {
    queue->tail->next = romeo;
    queue->tail = romeo;
  }
}

// Enqueue a Juliet
void enqueueJuliet(Queue *queue, Juliet *juliet) {
  if (queue->head == NULL) {
    queue->head = juliet;
    queue->tail = juliet;
  } else {
    queue->tail->next = juliet;
    queue->tail = juliet;
  }
}

// Dequeue a Romeo
Romeo* dequeueRomeo(Queue *queue) {
  if (queue->head == NULL) {
    return NULL;
  }
  Romeo *romeo = queue->head;
  queue->head = queue->head->next;
  if (queue->head == NULL) {
    queue->tail = NULL;
  }
  return romeo;
}

// Dequeue a Juliet
Juliet* dequeueJuliet(Queue *queue) {
  if (queue->head == NULL) {
    return NULL;
  }
  Juliet *juliet = queue->head;
  queue->head = queue->head->next;
  if (queue->head == NULL) {
    queue->tail = NULL;
  }
  return juliet;
}

// Print the Queue
void printQueue(Queue *queue) {
  Romeo *romeo = queue->head;
  while (romeo != NULL) {
    printf("%d ", romeo->value);
    romeo = romeo->next;
  }
  printf("\n");
}

// Main function
int main() {
  // Create a new Queue
  Queue *queue = newQueue();

  // Enqueue some Romeos and Juliets
  enqueueRomeo(queue, newRomeo(1));
  enqueueJuliet(queue, newJuliet(2));
  enqueueRomeo(queue, newRomeo(3));
  enqueueJuliet(queue, newJuliet(4));

  // Print the Queue
  printf("Queue: ");
  printQueue(queue);

  // Dequeue some Romeos and Juliets
  dequeueRomeo(queue);
  dequeueJuliet(queue);

  // Print the Queue
  printf("Queue: ");
  printQueue(queue);

  return 0;
}