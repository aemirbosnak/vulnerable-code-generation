//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_QUEUE_SIZE 5

typedef struct process_node {
  int process_id;
  int cpu_burst_time;
  int waiting_time;
  struct process_node* next;
} process_node;

process_node* create_process_node(int process_id, int cpu_burst_time) {
  process_node* new_node = (process_node*)malloc(sizeof(process_node));
  new_node->process_id = process_id;
  new_node->cpu_burst_time = cpu_burst_time;
  new_node->waiting_time = 0;
  new_node->next = NULL;

  return new_node;
}

void add_process_to_queue(process_node* new_node, process_node** head) {
  if (*head == NULL) {
    *head = new_node;
  } else {
    (*head)->next = new_node;
    *head = new_node;
  }
}

void round_robin_scheduling(process_node** head) {
  time_t current_time = time(NULL);
  process_node* current_process = *head;
  int time_quantum = 5;

  while (current_process) {
    // Calculate the remaining time for the process
    int remaining_time = current_process->cpu_burst_time - current_process->waiting_time;

    // If the remaining time is less than the time quantum, execute the process
    if (remaining_time < time_quantum) {
      current_process->waiting_time += remaining_time;
      current_process = current_process->next;
    } else {
      current_process->waiting_time += time_quantum;
      current_process = current_process->next;
    }

    // Update the current time
    current_time = time(NULL);
  }
}

int main() {
  process_node** ready_queue = (process_node**)malloc(MAX_QUEUE_SIZE * sizeof(process_node*));
  for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
    ready_queue[i] = NULL;
  }

  process_node* process_list = create_process_node(1, 10);
  add_process_to_queue(process_list, &ready_queue);

  process_list = create_process_node(2, 8);
  add_process_to_queue(process_list, &ready_queue);

  process_list = create_process_node(3, 6);
  add_process_to_queue(process_list, &ready_queue);

  round_robin_scheduling(&ready_queue);

  for (process_node* process = ready_queue[0]; process; process = process->next) {
    printf("Process ID: %d, Waiting Time: %d\n", process->process_id, process->waiting_time);
  }

  return 0;
}