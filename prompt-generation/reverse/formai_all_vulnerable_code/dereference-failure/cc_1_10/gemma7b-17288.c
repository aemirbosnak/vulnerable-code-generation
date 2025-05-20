//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int service_time;
  int completion_time;
  struct Process* next;
} Process;

Process* createProcess(int process_id, int arrival_time, int service_time) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_id = process_id;
  process->arrival_time = arrival_time;
  process->service_time = service_time;
  process->completion_time = 0;
  process->next = NULL;
  return process;
}

void schedule(Process* processes) {
  // Round Robin algorithm
  processes->next = processes;
  while (processes->next) {
    processes = processes->next;
    processes->completion_time = processes->arrival_time + processes->service_time;
  }
}

int main() {
  // Create a list of processes
  Process* processes = NULL;
  processes = createProcess(1, 0, 5);
  processes = createProcess(2, 2, 4);
  processes = createProcess(3, 4, 3);

  // Schedule the processes
  schedule(processes);

  // Print the completion times
  printf("Process ID\tCompletion Time\n");
  for (processes = processes; processes; processes = processes->next) {
    printf("%d\t\t%d\n", processes->process_id, processes->completion_time);
  }

  return 0;
}