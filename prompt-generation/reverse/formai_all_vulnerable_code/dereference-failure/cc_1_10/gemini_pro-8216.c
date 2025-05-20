//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define the neon void as a typedef
typedef struct neon_void {
  void *ptr;
  size_t size;
} neon_void;

// Define the neon queue as a typedef
typedef struct neon_queue {
  neon_void *front;
  neon_void *rear;
  size_t size;
} neon_queue;

// Create a neon queue
neon_queue *neon_queue_create() {
  neon_queue *queue = malloc(sizeof(neon_queue));
  if (queue == NULL) {
    return NULL;
  }
  queue->front = NULL;
  queue->rear = NULL;
  queue->size = 0;
  return queue;
}

// Destroy a neon queue
void neon_queue_destroy(neon_queue *queue) {
  if (queue == NULL) {
    return;
  }
  neon_void *current = queue->front;
  while (current != NULL) {
    neon_void *next = current->ptr;
    free(current);
    current = next;
  }
  free(queue);
}

// Enqueue an item into a neon queue
void neon_queue_enqueue(neon_queue *queue, void *item, size_t size) {
  if (queue == NULL) {
    return;
  }
  neon_void *new_item = malloc(sizeof(neon_void));
  if (new_item == NULL) {
    return;
  }
  new_item->ptr = item;
  new_item->size = size;
  if (queue->rear == NULL) {
    queue->front = new_item;
    queue->rear = new_item;
  } else {
    queue->rear->ptr = new_item;
    queue->rear = new_item;
  }
  queue->size++;
}

// Dequeue an item from a neon queue
void *neon_queue_dequeue(neon_queue *queue) {
  if (queue == NULL) {
    return NULL;
  }
  if (queue->front == NULL) {
    return NULL;
  }
  neon_void *item = queue->front;
  void *ptr = item->ptr;
  queue->front = item->ptr;
  if (queue->front == NULL) {
    queue->rear = NULL;
  }
  free(item);
  queue->size--;
  return ptr;
}

// Peek at the front item of a neon queue
void *neon_queue_peek(neon_queue *queue) {
  if (queue == NULL) {
    return NULL;
  }
  if (queue->front == NULL) {
    return NULL;
  }
  return queue->front->ptr;
}

// Get the size of a neon queue
size_t neon_queue_size(neon_queue *queue) {
  if (queue == NULL) {
    return 0;
  }
  return queue->size;
}

// Print the contents of a neon queue
void neon_queue_print(neon_queue *queue) {
  if (queue == NULL) {
    return;
  }
  neon_void *current = queue->front;
  while (current != NULL) {
    printf("%p ", current->ptr);
    current = current->ptr;
  }
  printf("\n");
}

// Test the neon queue
int main() {
  neon_queue *queue = neon_queue_create();
  if (queue == NULL) {
    return EXIT_FAILURE;
  }

  // Enqueue some items
  neon_queue_enqueue(queue, "Hello", sizeof("Hello"));
  neon_queue_enqueue(queue, "World", sizeof("World"));
  neon_queue_enqueue(queue, "!", sizeof("!"));

  // Print the contents of the queue
  neon_queue_print(queue);

  // Dequeue an item
  void *item = neon_queue_dequeue(queue);
  if (item != NULL) {
    printf("Dequeued: %s\n", (char *)item);
  }

  // Print the contents of the queue
  neon_queue_print(queue);

  // Destroy the queue
  neon_queue_destroy(queue);

  return EXIT_SUCCESS;
}