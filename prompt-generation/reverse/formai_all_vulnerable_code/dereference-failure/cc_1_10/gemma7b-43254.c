//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define PROC_NAME_LEN 255
#define PROC_STAT_LEN 255

typedef struct Process
{
  char name[PROC_NAME_LEN];
  char state[PROC_STAT_LEN];
  int pid;
  struct Process* next;
} Process;

Process* process_list = NULL;

void add_process(char* name, char* state, int pid)
{
  Process* new_process = malloc(sizeof(Process));

  strcpy(new_process->name, name);
  strcpy(new_process->state, state);
  new_process->pid = pid;
  new_process->next = process_list;
  process_list = new_process;
}

void display_processes()
{
  Process* current_process = process_list;

  printf("Processes:\n");

  while (current_process)
  {
    printf("  - Name: %s\n", current_process->name);
    printf("    State: %s\n", current_process->state);
    printf("    PID: %d\n", current_process->pid);
    printf("\n");
    current_process = current_process->next;
  }
}

int main()
{
  add_process("firefox", "running", 1234);
  add_process("chrome", "suspended", 5678);
  add_process("gnome-shell", "idle", 9213);

  display_processes();

  return 0;
}