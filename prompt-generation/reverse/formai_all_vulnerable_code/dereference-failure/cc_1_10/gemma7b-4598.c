//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
  int data;
  struct Node* next;
};

void insertAtTail(struct Node* head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void scheduler(struct Node* readyQueue) {
  if (readyQueue == NULL) {
    printf("Queue is empty\n");
    return;
  }

  struct Node* current = readyQueue;
  struct Node* next = NULL;

  // Round robin scheduling
  while (current) {
    next = current->next;
    printf("Process %d is running\n", current->data);

    // Simulate some CPU processing time
    sleep(1);

    // Move the current process to the end of the queue
    insertAtTail(readyQueue, current->data);

    // Free the current process from the queue
    free(current);

    current = next;
  }
}

int main() {
  struct Node* readyQueue = NULL;

  // Insert processes into the queue
  insertAtTail(readyQueue, 1);
  insertAtTail(readyQueue, 3);
  insertAtTail(readyQueue, 5);
  insertAtTail(readyQueue, 7);
  insertAtTail(readyQueue, 9);

  // Schedule the processes
  scheduler(readyQueue);

  return 0;
}