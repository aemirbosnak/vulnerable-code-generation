//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define quantum 4

struct Node {
  int process_id;
  struct Node* next;
  struct Node* prev;
  time_t arrival_time;
  time_t execution_time;
  time_t remaining_time;
  time_t completion_time;
  int priority;
};

void insert_at_tail(struct Node** head, int process_id, time_t arrival_time, time_t execution_time, int priority) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->process_id = process_id;
  newNode->arrival_time = arrival_time;
  newNode->execution_time = execution_time;
  newNode->remaining_time = execution_time;
  newNode->completion_time = 0;
  newNode->priority = priority;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->prev = newNode;
    (*head)->next = newNode;
    *head = newNode;
  }
}

void round_robin(struct Node** head) {
  struct Node* current = *head;
  while (current) {
    current->remaining_time--;
    if (current->remaining_time == 0) {
      current->completion_time = time(NULL);
      printf("Process %d completed at time %d\n", current->process_id, current->completion_time);
      free(current);
      *head = current->next;
    }
  }
}

int main() {
  struct Node* head = NULL;
  insert_at_tail(&head, 1, 0, 5, 3);
  insert_at_tail(&head, 2, 2, 4, 2);
  insert_at_tail(&head, 3, 4, 3, 1);

  round_robin(&head);

  return 0;
}