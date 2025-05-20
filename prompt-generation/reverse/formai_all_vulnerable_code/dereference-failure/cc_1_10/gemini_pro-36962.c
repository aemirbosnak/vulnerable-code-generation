//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef struct queue {
  node_t *head;
  node_t *tail;
  int size;
} queue_t;

queue_t *create_queue() {
  queue_t *queue = malloc(sizeof(queue_t));
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  return queue;
}

void enqueue(queue_t *queue, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;

  if (queue->size == 0) {
    queue->head = new_node;
    queue->tail = new_node;
  } else {
    queue->tail->next = new_node;
    queue->tail = new_node;
  }

  queue->size++;
}

int dequeue(queue_t *queue) {
  if (queue->size == 0) {
    return -1;
  }

  node_t *temp = queue->head;
  int data = temp->data;

  queue->head = queue->head->next;
  if (queue->head == NULL) {
    queue->tail = NULL;
  }

  free(temp);
  queue->size--;

  return data;
}

int main() {
  queue_t *queue = create_queue();

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  while (queue->size > 0) {
    printf("%d ", dequeue(queue));
  }

  printf("\n");

  return 0;
}