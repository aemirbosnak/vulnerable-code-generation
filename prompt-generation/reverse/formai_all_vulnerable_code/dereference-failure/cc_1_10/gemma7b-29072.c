//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_PROC_NUMBER 1024

typedef struct Process {
  char name[256];
  int cpu_usage;
  struct Process* next;
} Process;

Process* head = NULL;

void addToProcessList(char* name, int cpu_usage) {
  Process* newProcess = malloc(sizeof(Process));
  strcpy(newProcess->name, name);
  newProcess->cpu_usage = cpu_usage;
  newProcess->next = NULL;

  if (head == NULL) {
    head = newProcess;
  } else {
    Process* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newProcess;
  }
}

int main() {
  int i = 0;
  int cpu_usage = 0;
  FILE* file = fopen("/proc/stat", "r");
  char line[256];

  // Calculate CPU usage for each process
  while (fgets(line, 256, file) != NULL) {
    char* processName = strchr(line, " ");
    processName++;
    cpu_usage = atoi(strchr(processName, "%"));

    addToProcessList(processName, cpu_usage);
  }

  fclose(file);

  // Print process CPU usage
  Process* temp = head;
  while (temp) {
    printf("%s: %.2f%%\n", temp->name, (float)temp->cpu_usage);
  }

  return 0;
}