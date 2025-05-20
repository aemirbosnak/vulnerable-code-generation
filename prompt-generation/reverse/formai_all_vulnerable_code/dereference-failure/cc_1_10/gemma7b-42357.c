//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROC_NUM 100

typedef struct ProcInfo {
  char name[256];
  int pid;
  int status;
  struct ProcInfo* next;
} ProcInfo;

ProcInfo* proc_list = NULL;

void add_proc(char* name, int pid, int status) {
  ProcInfo* new_proc = malloc(sizeof(ProcInfo));
  strcpy(new_proc->name, name);
  new_proc->pid = pid;
  new_proc->status = status;
  new_proc->next = NULL;

  if (proc_list == NULL) {
    proc_list = new_proc;
  } else {
    proc_list->next = new_proc;
    proc_list = new_proc;
  }
}

void print_proc() {
  ProcInfo* current = proc_list;

  while (current) {
    printf("Name: %s, PID: %d, Status: %d\n", current->name, current->pid, current->status);
    current = current->next;
  }
}

int main() {
  add_proc("firefox", 1234, 0);
  add_proc("chrome", 5678, 1);
  add_proc("gnome-shell", 9841, 2);

  print_proc();

  return 0;
}