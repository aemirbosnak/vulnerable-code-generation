//FormAI DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct {
  int arr[MAX_QUEUE_SIZE];
  int front;
  int rear;
  int size;
} Queue;

Queue* create_queue() {
  Queue* q = (Queue*) malloc(sizeof(Queue));
  q -> front = q -> rear = -1;
  q -> size = 0;
  return q;
}

bool is_empty(Queue* q) {
  return (q -> front == -1);
}

bool is_full(Queue* q) {
  return (q -> rear + 1) % MAX_QUEUE_SIZE == q -> front;
}

int length(Queue* q) {
  int l = 0;
  if (q -> front <= q -> rear) {
    l = q -> rear - q -> front + 1;
  } else {
    l = MAX_QUEUE_SIZE - q -> front + q -> rear + 1;
  }
  return l;
}

void enqueue(Queue* q, int x) {
  if (is_full(q)) {
    printf("\nError: Overflow, Queue is full!\n");
    return;
  } else {
    if (is_empty(q)) {
      q -> front = q -> rear = 0;
    } else {
      q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
    }
    q -> arr[q -> rear] = x;
    q -> size++;
  }
}

int dequeue(Queue* q) {
  if (is_empty(q)) {
    printf("\nError: Underflow, Queue is empty!\n");
    return -1;
  } else {
    int x = q -> arr[q -> front];
    if (q -> front == q -> rear) {
      q -> front = q -> rear = -1;
    } else {
      q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;
    }
    q -> size--;
    return x;
  }
}

int front(Queue* q) {
  if (is_empty(q)) {
    printf("\nError: Underflow, Queue is empty!\n");
    return -1;
  } else {
    return q -> arr[q -> front];
  }
}

int rear(Queue* q) {
  if (is_empty(q)) {
    printf("\nError: Underflow, Queue is empty!\n");
    return -1;
  } else {
    return q -> arr[q -> rear];
  }
}

void display(Queue* q) {
  if (is_empty(q)) {
    printf("\nQueue is empty!\n");
    return;
  } else {
    printf("\nQueue contents: ");
    int i = q -> front;
    while (i != q -> rear) {
      printf("%d ", q -> arr[i]);
      i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d\n", q -> arr[q -> rear]);
  }
}

int main() {
  Queue* q = create_queue();
  
  printf("Is Queue empty? %s\n", is_empty(q) ? "true" : "false");
  
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);
  
  printf("Length of Queue: %d\n", length(q));
  display(q);
  
  printf("Front element of Queue: %d\n", front(q));
  printf("Rear element of Queue: %d\n", rear(q));
  
  dequeue(q);
  
  printf("Length of Queue: %d\n", length(q));
  display(q);
  
  printf("Front element of Queue: %d\n", front(q));
  printf("Rear element of Queue: %d\n", rear(q));
  
  enqueue(q, 6);
  enqueue(q, 7);
  enqueue(q, 8);
  
  printf("Length of Queue: %d\n", length(q));
  display(q);
  
  printf("Front element of Queue: %d\n", front(q));
  printf("Rear element of Queue: %d\n", rear(q));

  return 0;
}