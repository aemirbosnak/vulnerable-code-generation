//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROCESSES 10

typedef struct process_info {
  char name[20];
  int pid;
  struct process_info *next;
} process_info;

process_info *head = NULL;

void display_processes() {
  process_info *curr = head;
  while (curr) {
    printf("%s (PID: %d)\n", curr->name, curr->pid);
    curr = curr->next;
  }
}

void handle_process(int sig) {
  process_info *curr = head;
  while (curr) {
    if (curr->pid == sig) {
      printf("%s exited with status %d\n", curr->name, WEXITSTATUS(sig));
      free(curr);
      curr = head;
    }
    curr = curr->next;
  }
}

int main() {
  signal(SIGCHLD, handle_process);

  for (int i = 0; i < MAX_PROCESSES; i++) {
    process_info *new_process = malloc(sizeof(process_info));
    strcpy(new_process->name, "process_" + i);
    new_process->pid = fork();
    if (new_process->pid == 0) {
      printf("Hello, world from process %d\n", getpid());
      exit(i);
    } else {
      head = new_process;
    }
  }

  display_processes();

  pause();

  return 0;
}