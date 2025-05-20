//FormAI DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} Node;

typedef struct queue {
  Node* front;
  Node* rear;
} Queue;

void initializeQueue(Queue* queue) {
  queue->front = NULL;
  queue->rear = NULL;
}

int isEmpty(Queue* queue) {
  return queue->front == NULL;
}

void enqueue(Queue* queue, int value) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = value;
  newNode->next = NULL;
  
  if (queue->rear == NULL) {
    queue->front = queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

int dequeue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return -1;
  }

  int data = queue->front->data;
  Node* temp = queue->front;
  
  if (queue->front == queue->rear) {
    queue->front = queue->rear = NULL;
  } else {
    queue->front = queue->front->next;
  }

  free(temp);
  return data;
}

void display(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
  } else {
    Node* temp = queue->front;
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  Queue queue;
  initializeQueue(&queue);

  printf("Enqueueing 1, 2, 3, and 4.\n");
  enqueue(&queue, 1);
  enqueue(&queue, 2);
  enqueue(&queue, 3);
  enqueue(&queue, 4);
  display(&queue);

  printf("Dequeueing first element.\n");
  dequeue(&queue);
  display(&queue);

  printf("Enqueueing 5 and 6.\n");
  enqueue(&queue, 5);
  enqueue(&queue, 6);
  display(&queue);

  printf("Dequeueing all elements.\n");
  while (!isEmpty(&queue)) {
    printf("%d ", dequeue(&queue));
  }
  return 0;
}