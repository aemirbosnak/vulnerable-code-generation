//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value;
  struct node *next;
} node;

typedef struct {
  node *head;
  node *tail;
} queue;

queue *create_queue() {
  queue *q = malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

void enqueue(queue *q, int value) {
  node *new_node = malloc(sizeof(node));
  new_node->value = value;
  new_node->next = NULL;
  if (q->tail) {
    q->tail->next = new_node;
  }
  q->tail = new_node;
  if (!q->head) {
    q->head = new_node;
  }
}

int dequeue(queue *q) {
  if (!q->head) {
    return -1;
  }
  int value = q->head->value;
  node *new_head = q->head->next;
  free(q->head);
  q->head = new_head;
  if (!q->head) {
    q->tail = NULL;
  }
  return value;
}

int main() {
  queue *q = create_queue();
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  printf("%d\n", dequeue(q));
  printf("%d\n", dequeue(q));
  printf("%d\n", dequeue(q));
  return 0;
}