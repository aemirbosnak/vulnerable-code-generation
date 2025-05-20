//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS_NUM 5
#define MAX_INSTRUCTIONS 10

typedef struct Process {
  int process_num;
  int instructions;
  int waiting_time;
  int execution_time;
  struct Process* next;
} Process;

Process* createProcess(int process_num, int instructions) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_num = process_num;
  process->instructions = instructions;
  process->waiting_time = 0;
  process->execution_time = 0;
  process->next = NULL;
  return process;
}

void simulate(Process* process) {
  process->waiting_time++;
  printf("Process %d waiting for execution...\n", process->process_num);
  sleep(process->instructions);
  process->execution_time++;
  printf("Process %d completed execution.\n", process->process_num);
}

int main() {
  Process* head = NULL;
  for (int i = 0; i < MAX_PROCESS_NUM; i++) {
    Process* process = createProcess(i + 1, MAX_INSTRUCTIONS);
    process->waiting_time = i;
    if (head == NULL) {
      head = process;
    } else {
      process->next = head;
      head = process;
    }
  }

  time_t start_time = time(NULL);
  while (head) {
    simulate(head);
    head = head->next;
  }

  time_t end_time = time(NULL);
  printf("Total time taken: %ld seconds\n", end_time - start_time);

  return 0;
}