//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// A queue node
struct QNode {
  int data;
  struct QNode *next;
};

// A queue
struct Queue {
  struct QNode *front, *rear;
};

// Create a new queue
struct Queue *createQueue() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  return q;
}

// Check if the queue is empty
int isEmpty(struct Queue *q) { return q->front == NULL; }

// Enqueue an item to the queue
void enQueue(struct Queue *q, int item) {
  struct QNode *newNode = (struct QNode *)malloc(sizeof(struct QNode));
  newNode->data = item;
  newNode->next = NULL;
  if (q->rear == NULL) {
    q->front = q->rear = newNode;
  } else {
    q->rear->next = newNode;
    q->rear = newNode;
  }
}

// Dequeue an item from the queue
int deQueue(struct Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  } else {
    struct QNode *temp = q->front;
    int item = temp->data;
    q->front = temp->next;
    if (q->front == NULL) {
      q->rear = NULL;
    }
    free(temp);
    return item;
  }
}

// Peek at the front of the queue
int peek(struct Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  } else {
    return q->front->data;
  }
}

// Print the queue
void printQueue(struct Queue *q) {
  struct QNode *temp = q->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Queue *q = createQueue();

  enQueue(q, 10);
  enQueue(q, 20);
  enQueue(q, 30);
  enQueue(q, 40);

  printQueue(q);

  printf("Dequeued item: %d\n", deQueue(q));
  printf("Dequeued item: %d\n", deQueue(q));

  printQueue(q);

  printf("Peeked item: %d\n", peek(q));

  return 0;
}