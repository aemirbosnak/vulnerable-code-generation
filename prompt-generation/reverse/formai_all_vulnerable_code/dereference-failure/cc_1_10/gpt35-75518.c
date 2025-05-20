//FormAI DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct task {
  char *description;
  int priority;
} Task;

typedef struct node {
  Task *task;
  struct node *next;
} Node;

typedef struct priority_queue {
  Node *head;
} PriorityQueue;

PriorityQueue new_queue() {
  PriorityQueue pq;
  pq.head = NULL;
  return pq;
}

bool is_empty(PriorityQueue pq) {
  return pq.head == NULL;
}

void enqueue(PriorityQueue *pq, Task *task) {
  Node *new_node = malloc(sizeof(Node));
  new_node->task = task;
  new_node->next = NULL;

  if (is_empty(*pq)) {
    pq->head = new_node;
    return;
  }

  if (task->priority > pq->head->task->priority) {
    new_node->next = pq->head;
    pq->head = new_node;
    return;
  }

  Node *current = pq->head;
  while (current->next != NULL && task->priority <= current->next->task->priority) {
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
}

Task *dequeue(PriorityQueue *pq) {
  if (is_empty(*pq)) {
    printf("Queue is empty\n");
    return NULL;
  }

  Node *temp = pq->head;
  Task *task = temp->task;
  pq->head = pq->head->next;
  free(temp);
  return task;
}

int main() {
  PriorityQueue pq = new_queue();

  Task *task1 = malloc(sizeof(Task));
  task1->description = "Do laundry";
  task1->priority = 2;

  Task *task2 = malloc(sizeof(Task));
  task2->description = "Buy groceries";
  task2->priority = 1;

  Task *task3 = malloc(sizeof(Task));
  task3->description = "Study for exam";
  task3->priority = 3;

  Task *task4 = malloc(sizeof(Task));
  task4->description = "Take out trash";
  task4->priority = 2;

  enqueue(&pq, task1);
  enqueue(&pq, task2);
  enqueue(&pq, task3);
  enqueue(&pq, task4);

  printf("Tasks in order of priority:\n");
  while (!is_empty(pq)) {
    Task *task = dequeue(&pq);
    printf("- %s\n", task->description);
    free(task);
  }

  return 0;
}