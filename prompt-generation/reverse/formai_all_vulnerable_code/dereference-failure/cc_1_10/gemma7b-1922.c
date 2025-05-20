//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_PROC_NUM 10

typedef struct Process {
  int pid;
  char name[20];
  struct Process* next;
} Process;

Process* head = NULL;

void addProcess(char* name) {
  Process* newProcess = malloc(sizeof(Process));
  newProcess->pid = getpid();
  strcpy(newProcess->name, name);
  newProcess->next = NULL;

  if (head == NULL) {
    head = newProcess;
  } else {
    Process* lastProcess = head;
    while (lastProcess->next != NULL) {
      lastProcess = lastProcess->next;
    }
    lastProcess->next = newProcess;
  }
}

void viewProcesses() {
  Process* process = head;
  printf("Behold, the list of processes:\n");
  while (process) {
    printf("  Name: %s, PID: %d\n", process->name, process->pid);
    process = process->next;
  }
  printf("\n");
}

int main() {
  addProcess("The Brave Knight");
  addProcess("The Mighty Wizard");
  addProcess("The Fearless Archer");
  addProcess("The Loyal Dwarf");

  viewProcesses();

  wait(NULL);

  return 0;
}