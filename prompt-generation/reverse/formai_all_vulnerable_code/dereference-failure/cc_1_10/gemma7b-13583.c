//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PROCESSES 10
#define PROCESS_TIME 5

struct process {
  int id;
  int burst_time;
  struct process* next;
};

void schedule_process(struct process* head) {
  struct process* current_process = head;
  struct process* next_process = NULL;

  while (current_process) {
    if (next_process) {
      next_process = current_process->next;
    } else {
      next_process = head;
    }

    printf("Process %d is running...\n", current_process->id);
    sleep(PROCESS_TIME);

    current_process->burst_time--;
    if (current_process->burst_time == 0) {
      printf("Process %d is finished.\n", current_process->id);
      if (next_process) {
        current_process = next_process;
      } else {
        current_process = head;
      }
    } else {
      current_process = current_process->next;
    }
  }
}

int main() {
  struct process* head = NULL;
  for (int i = 0; i < MAX_PROCESSES; i++) {
    struct process* new_process = malloc(sizeof(struct process));
    new_process->id = i + 1;
    new_process->burst_time = rand() % PROCESS_TIME + 1;
    new_process->next = head;
    head = new_process;
  }

  schedule_process(head);

  return 0;
}