//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

struct queue {
  struct node *head;
  struct node *tail;
};

void enqueue(struct queue *queue, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  if (queue->head == NULL) {
    queue->head = new_node;
    queue->tail = new_node;
  } else {
    queue->tail->next = new_node;
    queue->tail = new_node;
  }
}

int dequeue(struct queue *queue) {
  if (queue->head == NULL) {
    printf("Error: Queue is empty\n");
    return -1;
  }

  struct node *temp = queue->head;
  int data = temp->data;

  queue->head = temp->next;
  if (queue->head == NULL) {
    queue->tail = NULL;
  }

  free(temp);
  return data;
}

int main() {
  struct queue queue;
  queue.head = NULL;
  queue.tail = NULL;

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);

  printf("%d\n", dequeue(&queue));
  printf("%d\n", dequeue(&queue));
  printf("%d\n", dequeue(&queue));

  return 0;
}