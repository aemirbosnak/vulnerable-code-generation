//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESS_NUMBER 5

typedef struct Process {
  int process_id;
  int arrival_time;
  int execution_time;
  struct Process* next;
} Process;

Process* create_process(int process_id, int arrival_time, int execution_time) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_id = process_id;
  process->arrival_time = arrival_time;
  process->execution_time = execution_time;
  process->next = NULL;
  return process;
}

void simulate_cpu(Process* processes) {
  int current_time = 0;
  while (!processes || processes->arrival_time <= current_time) {
    current_time++;
    if (processes) {
      printf("Process %d is running at time %d\n", processes->process_id, current_time);
      processes->execution_time--;
      if (processes->execution_time == 0) {
        processes = processes->next;
      }
    }
  }
}

int main() {
  Process* processes = NULL;

  // Create a few processes
  processes = create_process(1, 0, 5);
  processes = create_process(2, 2, 4);
  processes = create_process(3, 4, 3);
  processes = create_process(4, 6, 2);
  processes = create_process(5, 8, 1);

  // Simulate the CPU
  simulate_cpu(processes);

  return 0;
}