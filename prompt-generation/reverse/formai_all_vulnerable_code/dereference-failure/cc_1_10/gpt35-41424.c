//FormAI DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct Queue {
   int data[MAX_QUEUE_SIZE];
   int rear;
   int front;
} Queue;

Queue *createQueue();
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int getQueueSize(Queue *q);

int main() {
   Queue *q = createQueue();
   
   printf("Enqueuing 5 elements into the queue...\n");
   enqueue(q, 10);
   enqueue(q, 20);
   enqueue(q, 30);
   enqueue(q, 40);
   enqueue(q, 50);

   printf("Dequeueing 3 elements from the queue...\n");
   printf("%d ", dequeue(q));
   printf("%d ", dequeue(q));
   printf("%d ", dequeue(q));

   printf("\nQueue size: %d\n", getQueueSize(q));

   printf("Enqueuing 2 more elements into the queue...\n");
   enqueue(q, 60);
   enqueue(q, 70);

   printf("Dequeueing all elements from the queue...\n");
   while (!isQueueEmpty(q)) {
      printf("%d ", dequeue(q));
   }

   printf("\nQueue size: %d\n", getQueueSize(q));

   return 0;
}

Queue *createQueue() {
   Queue *q = (Queue *) malloc(sizeof(Queue));
   q->front = q->rear = -1;
   return q;
}

int isQueueEmpty(Queue *q) {
   return (q->front == -1 && q->rear == -1);
}

int isQueueFull(Queue *q) {
   return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue *q, int data) {
   if (isQueueFull(q)) {
      printf("Queue is full.\n");
      return;
   } else if (isQueueEmpty(q)) {
      q->front = q->rear = 0;
   } else {
      q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
   }
   q->data[q->rear] = data;
}

int dequeue(Queue *q) {
   int data = -1;
   if (isQueueEmpty(q)) {
      printf("Queue is empty.\n");
      return data;
   } else if (q->front == q->rear) {
      data = q->data[q->front];
      q->front = q->rear = -1;
   } else {
      data = q->data[q->front];
      q->front = (q->front + 1) % MAX_QUEUE_SIZE;
   }
   return data;  
}

int getQueueSize(Queue *q) {
   if (isQueueEmpty(q)) {
      return 0;
   } else {
      return ((MAX_QUEUE_SIZE - q->front + q->rear) % MAX_QUEUE_SIZE + 1);
   }
}