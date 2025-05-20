//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PROC_NAME_LENGTH 255

typedef struct process_info {
  char name[MAX_PROC_NAME_LENGTH];
  int pid;
  struct process_info* next;
} process_info;

process_info* get_process_info() {
  process_info* head = NULL;
  FILE* file = fopen("/proc/self/stat", "r");
  char proc_name[MAX_PROC_NAME_LENGTH];
  int pid = getpid();
  snprintf(proc_name, MAX_PROC_NAME_LENGTH, "/proc/%d/stat", pid);

  FILE* proc_file = fopen(proc_name, "r");
  char line[1024];
  char* ptr;
  while (fgets(line, 1024, proc_file) != NULL) {
    ptr = strchr(line, ' ') + 1;
    process_info* new_node = malloc(sizeof(process_info));
    snprintf(new_node->name, MAX_PROC_NAME_LENGTH, "%s", ptr);
    new_node->pid = pid;
    new_node->next = head;
    head = new_node;
  }

  fclose(proc_file);
  fclose(file);
  return head;
}

void print_process_info(process_info* head) {
  while (head) {
    printf("Name: %s, PID: %d\n", head->name, head->pid);
    head = head->next;
  }
}

int main() {
  process_info* processes = get_process_info();
  print_process_info(processes);
  return 0;
}