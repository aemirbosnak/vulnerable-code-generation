//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Node {
  int process_id;
  struct Node* next;
} Node;

void insert_node(Node** head, int process_id) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->process_id = process_id;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    (*head)->next = new_node;
  }
}

void schedule(Node** head) {
  time_t start_time = time(NULL);
  int quantum = 0;
  while (*head) {
    int process_id = (*head)->process_id;
    printf("Process ID: %d, Quantum: %d\n", process_id, quantum);
    sleep(1);
    quantum++;
    (*head) = (*head)->next;
  }

  time_t end_time = time(NULL);
  printf("Total time: %ld seconds\n", end_time - start_time);
}

int main() {
  Node* head = NULL;
  insert_node(&head, 1);
  insert_node(&head, 2);
  insert_node(&head, 3);
  insert_node(&head, 4);
  insert_node(&head, 5);

  schedule(&head);

  return 0;
}