//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
  int process_id;
  int arrival_time;
  int service_time;
  int completion_time;
  struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int serviceTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_id = id;
  process->arrival_time = arrivalTime;
  process->service_time = serviceTime;
  process->completion_time = 0;
  process->next = NULL;
  return process;
}

void simulate(Process* processes) {
  int quantum = 0;
  time_t start_time = time(NULL);

  while (!processes->next) {
    for (processes = processes; processes; processes = processes->next) {
      if (processes->arrival_time == quantum) {
        processes->completion_time = start_time + processes->service_time;
        printf("Process %d completed at time %d\n", processes->process_id, processes->completion_time);
      }
    }

    quantum++;
  }
}

int main() {
  Process* processes = NULL;
  processes = createProcess(1, 0, 5);
  processes = createProcess(2, 2, 3);
  processes = createProcess(3, 4, 2);
  processes = createProcess(4, 6, 4);
  processes = createProcess(5, 8, 3);

  simulate(processes);

  return 0;
}