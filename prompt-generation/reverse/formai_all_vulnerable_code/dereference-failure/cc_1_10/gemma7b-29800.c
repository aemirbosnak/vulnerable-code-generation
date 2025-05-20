//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>

#define MAX_PROC_NUM 1024

typedef struct ProcessInfo {
  char name[256];
  char user[256];
  char state[16];
  int pid;
  struct ProcessInfo *next;
} ProcessInfo;

ProcessInfo *getProcessList() {
  ProcessInfo *head = NULL;
  char cmd[256];
  FILE *fp;
  char line[256];
  char *user, *state, *name, *pid;

  fp = popen("ps aux", "r");

  if (fp) {
    while (fgets(line, 256, fp) != NULL) {
      user = strchr(line, 'u');
      state = strchr(line, 'S');
      name = strchr(line, 'a');
      pid = strchr(line, 'pid');

      if (user && state && name && pid) {
        ProcessInfo *newProc = malloc(sizeof(ProcessInfo));
        strcpy(newProc->name, name);
        strcpy(newProc->user, user);
        strcpy(newProc->state, state);
        newProc->pid = atoi(pid);
        newProc->next = head;
        head = newProc;
      }
    }
  }

  return head;
}

int main() {
  ProcessInfo *processList = getProcessList();

  if (processList) {
    printf("Process List:\n");
    for (ProcessInfo *curr = processList; curr; curr = curr->next) {
      printf("  - Process Name: %s\n", curr->name);
      printf("    - User: %s\n", curr->user);
      printf("    - State: %s\n", curr->state);
      printf("    - PID: %d\n", curr->pid);
      printf("\n");
    }
  } else {
    printf("No processes found.\n");
  }

  return 0;
}