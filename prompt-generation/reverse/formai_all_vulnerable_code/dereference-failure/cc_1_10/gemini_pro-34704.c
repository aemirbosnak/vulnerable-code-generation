//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *data;
  struct node *next;
} node;

typedef struct queue {
  node *front;
  node *rear;
} queue;

void enqueue(queue *q, char *data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = strdup(data);
  new_node->next = NULL;
  if (q->rear == NULL) {
    q->front = new_node;
    q->rear = new_node;
  } else {
    q->rear->next = new_node;
    q->rear = new_node;
  }
}

char *dequeue(queue *q) {
  if (q->front == NULL) {
    return NULL;
  }
  node *temp = q->front;
  char *data = temp->data;
  q->front = q->front->next;
  if (q->front == NULL) {
    q->rear = NULL;
  }
  free(temp);
  return data;
}

int main() {
  queue q;
  q.front = NULL;
  q.rear = NULL;

  enqueue(&q, "Hello");
  enqueue(&q, "World");
  enqueue(&q, "!");

  while (q.front != NULL) {
    char *data = dequeue(&q);
    printf("%s", data);
    free(data);
  }

  printf("\n");

  return 0;
}