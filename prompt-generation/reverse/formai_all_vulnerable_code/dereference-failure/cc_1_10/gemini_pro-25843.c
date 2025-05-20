//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Queue {
  struct Node *front;
  struct Node *rear;
};

struct Queue *create_queue() {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

void enqueue(struct Queue *queue, int data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  if (queue->front == NULL) {
    queue->front = new_node;
    queue->rear = new_node;
  } else {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }
}

int dequeue(struct Queue *queue) {
  if (queue->front == NULL) {
    printf("Queue is empty. Cannot dequeue.\n");
    return -1;
  } else {
    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
  }
}

int is_empty(struct Queue *queue) {
  return queue->front == NULL;
}

void print_queue(struct Queue *queue) {
  if (queue->front == NULL) {
    printf("Queue is empty. Nothing to print.\n");
  } else {
    struct Node *temp = queue->front;
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  struct Queue *queue = create_queue();

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);

  print_queue(queue);

  printf("Dequeued: %d\n", dequeue(queue));
  printf("Dequeued: %d\n", dequeue(queue));

  enqueue(queue, 50);
  enqueue(queue, 60);

  print_queue(queue);

  printf("Dequeued: %d\n", dequeue(queue));
  printf("Dequeued: %d\n", dequeue(queue));
  printf("Dequeued: %d\n", dequeue(queue));
  printf("Dequeued: %d\n", dequeue(queue));

  if (is_empty(queue)) {
    printf("Queue is empty.\n");
  } else {
    printf("Queue is not empty.\n");
  }

  return 0;
}