//FormAI DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

struct Queue {
   int front;
   int rear;
   int *array;
   int capacity;
};

struct Queue* createQueue(int capacity) {
   struct Queue *Q = malloc(sizeof(struct Queue));
   if(!Q)
      return NULL;
   Q->capacity = capacity;
   Q->front = Q->rear = -1;
   Q->array = malloc(capacity * sizeof(int));
   if(!Q->array)
      return NULL;
   return Q;
}

int isFull(struct Queue *Q) {
   if(Q->rear == Q->capacity-1)
      return 1;
   return 0;
}

int isEmpty(struct Queue *Q) {
   if(Q->front == -1)
      return 1;
   return 0;
}

void enqueue(struct Queue *Q, int data) {
   if(isFull(Q))
      printf("Queue Overflow!\n");
   else {
      Q->rear++;
      Q->array[Q->rear] = data;
      if(Q->front == -1)
         Q->front = 0;
      printf("Enqueued: %d\n", data);
   }
}

int dequeue(struct Queue *Q) {
   int data = 0;
   if(isEmpty(Q)) {
      printf("Queue Underflow!\n");
      return 0;
   }
   else {
      data = Q->array[Q->front];
      if(Q->front == Q->rear)
         Q->front = Q->rear = -1;
      else
         Q->front++;
      printf("Dequeued: %d\n", data);
      return data;
   }
}

void display(struct Queue *Q) {
   if(isEmpty(Q)) {
      printf("Queue is Empty!\n");
      return;
   }
   else {
      int i;
      printf("Elements in the Queue are: \n");
      for(i=Q->front; i<=Q->rear; i++)
         printf("%d\n", Q->array[i]);
   }
}

int main() {
   struct Queue *Q = createQueue(5);
   
   enqueue(Q, 10);
   enqueue(Q, 20);
   enqueue(Q, 30);
   enqueue(Q, 40);
   enqueue(Q, 50);
   enqueue(Q, 60); //Overflow
   
   dequeue(Q);
   dequeue(Q);
   dequeue(Q);
   dequeue(Q);
   dequeue(Q);
   dequeue(Q); //Underflow
   
   display(Q);
   
   return 0;
}