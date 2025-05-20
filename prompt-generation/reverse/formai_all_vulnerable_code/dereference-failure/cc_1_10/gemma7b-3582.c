//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  char name[20];
  int priority;
  struct node* next;
} node;

typedef struct {
  node* head;
  node* tail;
} queue;

void insert(queue* q, node* n) {
  if (q->head == NULL) {
    q->head = n;
    q->tail = n;
  } else {
    q->tail->next = n;
    q->tail = n;
  }
}

void schedule(queue* q) {
  node* current = q->head;
  while (current) {
    // Calculate the quantum of the current node
    int quantum = current->priority;
    // Spin for the quantum
    int i = 0;
    for (; i < quantum; i++) {
      printf("%s is running...\n", current->name);
    }
    // Move to the next node
    current = current->next;
  }
}

int main() {
  // Create a queue
  queue* q = malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;

  // Insert some nodes into the queue
  node* n1 = malloc(sizeof(node));
  strcpy(n1->name, "Node 1");
  n1->priority = 5;
  insert(q, n1);

  node* n2 = malloc(sizeof(node));
  strcpy(n2->name, "Node 2");
  n2->priority = 3;
  insert(q, n2);

  node* n3 = malloc(sizeof(node));
  strcpy(n3->name, "Node 3");
  n3->priority = 2;
  insert(q, n3);

  // Schedule the nodes
  schedule(q);

  return 0;
}