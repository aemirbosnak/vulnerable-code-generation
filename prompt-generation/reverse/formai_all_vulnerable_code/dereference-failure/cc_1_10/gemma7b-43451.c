//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PROCESSES 10

typedef struct Process {
  char name[256];
  int cpu_usage;
  int memory_usage;
  struct Process* next;
} Process;

Process* head = NULL;

void update_process_usage(char* name, int cpu_usage, int memory_usage) {
  Process* new_process = malloc(sizeof(Process));
  strcpy(new_process->name, name);
  new_process->cpu_usage = cpu_usage;
  new_process->memory_usage = memory_usage;
  new_process->next = head;
  head = new_process;
}

int main() {
  char process_name[256];
  int cpu_usage, memory_usage;

  for (int i = 0; i < MAX_PROCESSES; i++) {
    printf("Enter the name of process %d: ", i + 1);
    scanf("%s", process_name);

    printf("Enter the CPU usage of process %d: ", i + 1);
    scanf("%d", &cpu_usage);

    printf("Enter the memory usage of process %d: ", i + 1);
    scanf("%d", &memory_usage);

    update_process_usage(process_name, cpu_usage, memory_usage);
  }

  printf("List of processes:\n");
  Process* current_process = head;
  while (current_process) {
    printf("%s has a CPU usage of %d%% and a memory usage of %dKB\n", current_process->name, current_process->cpu_usage, current_process->memory_usage);
    current_process = current_process->next;
  }

  return 0;
}