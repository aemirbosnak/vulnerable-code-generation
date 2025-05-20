//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROC_NUM 1024

struct Process {
  char name[256];
  int pid;
  int status;
  struct Process* next;
};

void print_processes(struct Process* head) {
  struct Process* current = head;
  while (current) {
    printf("%s (PID: %d) - State: %s\n", current->name, current->pid,
        (current->status) ? "Running" : "Idle");
    current = current->next;
  }
}

int main() {
  struct Process* processes = NULL;
  struct Process* new_process = NULL;

  // Get a list of processes
  FILE* proc_file = fopen("/proc/processes", "r");
  if (proc_file) {
    char line[256];
    while (fgets(line, 256, proc_file) != NULL) {
      char* pid_str = strchr(line, " ");
      int pid = atoi(pid_str);
      char* name = strchr(line, "(") + 1;
      name = strchr(name, ")") - name;

      new_process = malloc(sizeof(struct Process));
      new_process->pid = pid;
      strncpy(new_process->name, name, 256);
      new_process->status = 1;
      new_process->next = processes;
      processes = new_process;
    }
    fclose(proc_file);
  }

  // Print the processes
  print_processes(processes);

  return 0;
}