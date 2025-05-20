//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int execution_time;
  int completion_time;
  struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int executionTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_id = id;
  process->arrival_time = arrivalTime;
  process->execution_time = executionTime;
  process->completion_time = 0;
  process->next = NULL;
  return process;
}

void schedule(Process* processes) {
  // Round robin scheduling algorithm
  int current_time = 0;
  Process* current_process = processes;

  while (!processes->next || current_time < MAX_TIME) {
    // If the process has arrived and its execution time has started, complete it
    if (current_process->arrival_time <= current_time && current_process->execution_time > 0) {
      current_process->completion_time = current_time + 1;
      processes = processes->next;
      current_process = processes;
    } else {
      // Increment the current time
      current_time++;
    }
  }

  // Print the completion time for each process
  for (processes = processes; processes; processes = processes->next) {
    printf("Process ID: %d, Completion Time: %d\n", processes->process_id, processes->completion_time);
  }
}

int main() {
  // Create a list of processes
  Process* processes = createProcess(1, 0, 5);
  processes = createProcess(2, 2, 3);
  processes = createProcess(3, 4, 4);
  processes = createProcess(4, 6, 2);
  processes = createProcess(5, 8, 3);

  // Schedule the processes
  schedule(processes);

  return 0;
}