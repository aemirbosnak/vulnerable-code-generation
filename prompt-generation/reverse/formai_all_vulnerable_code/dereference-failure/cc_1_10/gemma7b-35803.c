//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PROCESSES 10

typedef struct Process {
  int process_id;
  char name[20];
  int cpu_burst;
  struct Process *next;
} Process;

Process *head = NULL;

void schedule_process() {
  Process *current_process = head;
  while (current_process) {
    printf("Process ID: %d, Name: %s, CPU Burst: %d\n", current_process->process_id, current_process->name, current_process->cpu_burst);
    sleep(current_process->cpu_burst);
    current_process = current_process->next;
  }
}

void add_process(int process_id, char *name, int cpu_burst) {
  Process *new_process = (Process *)malloc(sizeof(Process));
  new_process->process_id = process_id;
  strcpy(new_process->name, name);
  new_process->cpu_burst = cpu_burst;
  new_process->next = NULL;

  if (head == NULL) {
    head = new_process;
  } else {
    Process *last_process = head;
    while (last_process->next) {
      last_process = last_process->next;
    }
    last_process->next = new_process;
  }
}

int main() {
  add_process(1, "Process A", 5);
  add_process(2, "Process B", 3);
  add_process(3, "Process C", 2);

  schedule_process();

  return 0;
}