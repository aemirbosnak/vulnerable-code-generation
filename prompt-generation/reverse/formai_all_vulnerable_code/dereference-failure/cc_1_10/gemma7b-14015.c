//Gemma-7B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct Process {
  char name[20];
  int pid;
  struct Process *next;
} Process;

Process *head = NULL;

void addProcess(char *name) {
  Process *newProcess = malloc(sizeof(Process));
  strcpy(newProcess->name, name);
  newProcess->pid = getpid();
  newProcess->next = head;
  head = newProcess;
}

void killProcess(char *name) {
  Process *prev = NULL;
  Process *curr = head;

  while (curr) {
    if (strcmp(curr->name, name) == 0) {
      if (prev) {
        prev->next = curr->next;
      } else {
        head = curr->next;
      }
      free(curr);
      return;
    }
    prev = curr;
    curr = curr->next;
  }

  printf("Process not found: %s\n", name);
}

int main() {
  addProcess("foo");
  addProcess("bar");
  addProcess("baz");

  killProcess("bar");

  Process *curr = head;
  while (curr) {
    printf("%s (%d)\n", curr->name, curr->pid);
    curr = curr->next;
  }

  return 0;
}