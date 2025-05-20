//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Our enchanted queue, a charming array of values
int *queue;
int front = 0, rear = -1, size = 0;

// Enchanting the queue with a new value
void enqueue(int value) {
  if (size == rear + 1) {
    printf("\nOops! Our queue is full. Time to expand!\n");
    int *newQueue = (int *)malloc(sizeof(int) * (size + 10));
    for (int i = 0; i < size; i++) {
      newQueue[i] = queue[(front + i) % size];
    }
    free(queue);
    queue = newQueue;
    rear = size - 1;
    front = 0;
    size += 10;
  }
  rear = (rear + 1) % size;
  queue[rear] = value;
  printf("\n%d gracefully steps into the queue.\n", value);
}

// Unenchanting the queue, releasing a value to the wild
int dequeue() {
  if (size == 0) {
    printf("\nAlas! The queue is empty. Nothing to release.\n");
    return -1;
  }
  int value = queue[front];
  front = (front + 1) % size;
  printf("\n%d bids farewell to the queue.\n", value);
  return value;
}

// Peeking into the queue's wonders
int peek() {
  if (size == 0) {
    printf("\nThe queue is shy. It hides its secrets.\n");
    return -1;
  }
  return queue[front];
}

// Unveiling the size of our queue's enchantment
int queueSize() {
  return size;
}

// Main function, where the enchantment unfolds
int main() {
  printf("\nWelcome to the Enchanted Queue!\n");

  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);

  printf("\nPeek into the queue's enchantment: %d\n", peek());

  dequeue();
  dequeue();

  enqueue(60);
  enqueue(70);

  printf("\nCurrent size of the queue: %d\n", queueSize());

  while (size > 0) {
    printf("\nUnveiling the next enchantment: %d\n", dequeue());
  }

  return 0;
}