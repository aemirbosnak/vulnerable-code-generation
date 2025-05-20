//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NR_CPU 4
#define MAX_SCHEDULE_SIZE 20

typedef struct node {
  int cpu_num;
  struct node* next;
} node_t;

node_t* create_schedule(int size) {
  node_t* head = NULL;
  for (int i = 0; i < size; i++) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->cpu_num = -1;
    new_node->next = head;
    head = new_node;
  }
  return head;
}

void schedule_process(node_t* head, int process_id) {
  node_t* current = head;
  while (current) {
    if (current->cpu_num == -1) {
      current->cpu_num = process_id;
      break;
    }
    current = current->next;
  }
}

int main() {
  node_t* schedule = create_schedule(MAX_SCHEDULE_SIZE);
  for (int i = 0; i < NR_CPU; i++) {
    schedule_process(schedule, i);
  }

  for (int i = 0; i < MAX_SCHEDULE_SIZE; i++) {
    node_t* current = schedule;
    while (current) {
      if (current->cpu_num == i) {
        printf("Process ID: %d, CPU: %d\n", current->cpu_num, i);
      }
      current = current->next;
    }
  }

  return 0;
}