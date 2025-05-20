//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Queue {
  int arr[MAX_SIZE];
  int front, rear;
  int count;
} Queue;

Queue* createQueue() {
  Queue* q = (Queue*)malloc(sizeof(Queue));
  q->front = -1;
  q->rear = -1;
  q->count = 0;
  return q;
}

void enqueue(Queue* q, int value) {
  if (q->count == MAX_SIZE) {
    printf("Queue is full, cannot insert.\n");
    return;
  }

  if (q->front == -1) {
    q->front = q->rear = 0;
  } else {
    q->rear = (q->rear + 1) % MAX_SIZE;
  }
  q->arr[q->rear] = value;
  q->count++;
}

int dequeue(Queue* q) {
  if (q->count == 0) {
    printf("Queue is empty, cannot delete.\n");
    return -1;
  }

  int value = q->arr[q->front];
  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front = (q->front + 1) % MAX_SIZE;
  }
  q->count--;
  return value;
}

void printQueue(Queue* q) {
  if (q->count == 0) {
    printf("Queue is empty.\n");
    return;
  }

  int i = q->front;
  while (i != q->rear) {
    printf("%d  ", q->arr[i]);
    i = (i + 1) % MAX_SIZE;
  }
  printf("%d\n", q->arr[q->rear]);
}

int main() {
  // Romeo and Juliet style
  printf("Romeo: My love, Juliet, I have come to see thee.\n");
  printf("Juliet: Romeo, my dearest, thou art most welcome here.\n");
  printf("Romeo: I have brought thee a gift, a token of my love.\n");
  printf("Juliet: A gift? What is it, my love?\n");
  printf("Romeo: It is a queue, my dear. A place where we can store our secrets.\n");
  printf("Juliet: A queue? How does it work?\n");
  printf("Romeo: It is simple, my love. One end is for adding secrets, and the other end is for removing them.\n");
  printf("Juliet: I understand. And what secrets shall we store in our queue?\n");
  printf("Romeo: We shall store our love letters, our whispers, and our deepest desires.\n");
  printf("Juliet: Oh, Romeo, that is a wonderful idea!\n");

  // Create a queue
  Queue* q = createQueue();

  // Enqueue some secrets
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);

  // Print the queue
  printf("Our queue of secrets:\n");
  printQueue(q);

  // Dequeue some secrets
  int secret1 = dequeue(q);
  int secret2 = dequeue(q);
  int secret3 = dequeue(q);

  // Print the remaining queue
  printf("Our remaining queue of secrets:\n");
  printQueue(q);

  // Romeo and Juliet say goodbye
  printf("Romeo: My love, it is time for me to go.\n");
  printf("Juliet: Oh, Romeo, I shall miss thee so!\n");
  printf("Romeo: Fear not, my love. I shall return soon, and we shall fill our queue with even more secrets.\n");
  printf("Juliet: Farewell, my love. Until then, I shall cherish our queue.\n");

  return 0;
}