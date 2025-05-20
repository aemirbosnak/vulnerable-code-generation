//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PROC_NUM 10

typedef struct process_info {
  char name[20];
  int pid;
  struct process_info* next;
} process_info;

process_info* head = NULL;

void add_process(char* name) {
  process_info* new_process = malloc(sizeof(process_info));
  strcpy(new_process->name, name);
  new_process->pid = getpid();
  new_process->next = NULL;

  if (head == NULL) {
    head = new_process;
  } else {
    head->next = new_process;
  }
}

void view_processes() {
  process_info* current = head;
  while (current) {
    printf("%s (PID: %d)\n", current->name, current->pid);
    current = current->next;
  }
}

int main() {
  add_process("Process 1");
  add_process("Process 2");
  add_process("Process 3");

  view_processes();

  system("ps -aux");

  wait(NULL);

  view_processes();

  return 0;
}