//FormAI DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct{
  int front, rear;
  int data[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue(){
  Queue* q = (Queue*)malloc(sizeof(Queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

int isEmpty(Queue* q){
  if(q->front == -1 && q->rear == -1)
    return 1;
  return 0;
}

int isFull(Queue* q){
  if((q->rear+1) % MAX_QUEUE_SIZE == q->front)
    return 1;
  return 0;
}

void enqueue(Queue* q, int val){
  if(isFull(q)){
    printf("Queue is full!\n");
    return;
  }
  else if(isEmpty(q)){
    q->front = 0;
    q->rear = 0;
  }
  else{
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
  }
  q->data[q->rear] = val;
}

int dequeue(Queue* q){
  if(isEmpty(q)){
    printf("Queue is empty!\n");
    return -1;
  }
  else if(q->front == q->rear){
    int val = q->data[q->front];
    q->front = -1;
    q->rear = -1;
    return val;
  }
  else{
    int val = q->data[q->front];
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return val;
  }
}

void traverse(Queue* q){
  if(isEmpty(q)){
    printf("Queue is empty!\n");
    return;
  }
  int i = q->front;
  printf("Queue: ");
  while(i != q->rear){
    printf("%d ", q->data[i]);
    i = (i+1) % MAX_QUEUE_SIZE;
  }
  printf("%d\n", q->data[i]);
}

int main(){
  Queue* q = createQueue();

  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  enqueue(q, 50);
  traverse(q);

  dequeue(q);
  traverse(q);

  enqueue(q, 60);
  enqueue(q, 70);
  traverse(q);

  dequeue(q);
  dequeue(q);
  traverse(q);

  enqueue(q, 80);
  enqueue(q, 90);
  traverse(q);

  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);

  traverse(q);

  free(q);
  return 0;
}