//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: curious
#include <stdio.h>
#include <sys/sysinfo.h>
#include <stdlib.h>

#define PROC_NAME_LEN 256

typedef struct process_info {
  char name[PROC_NAME_LEN];
  int pid;
  long mem_usage;
  long cpu_usage;
  struct process_info* next;
} process_info;

process_info* create_process_info(char* name, int pid, long mem_usage, long cpu_usage) {
  process_info* new_info = malloc(sizeof(process_info));
  strcpy(new_info->name, name);
  new_info->pid = pid;
  new_info->mem_usage = mem_usage;
  new_info->cpu_usage = cpu_usage;
  new_info->next = NULL;
  return new_info;
}

void print_process_info(process_info* head) {
  process_info* current = head;
  while (current) {
    printf("Process name: %s\n", current->name);
    printf("Process ID: %d\n", current->pid);
    printf("Memory usage: %.2lf MB\n", (double)current->mem_usage / 1048576);
    printf("CPU usage: %.2lf%%\n", (double)current->cpu_usage);
    printf("\n");
    current = current->next;
  }
}

int main() {
  process_info* head = NULL;
  system("ps -eo pid,command,rss,cpu");

  FILE* file = fopen("/proc/stat", "r");
  char line[256];
  while (fgets(line, 256, file) != NULL) {
    char* pid_str = strchr(line, " ");
    int pid = atoi(pid_str);

    char* name = strchr(line, " ") + 1;
    name = strchr(name, " ") ? strchr(name, " ") : name;

    long mem_usage = atoi(strchr(line, " ") + 1);
    long cpu_usage = atoi(strchr(line, "%") - 1);

    process_info* new_info = create_process_info(name, pid, mem_usage, cpu_usage);
    if (head == NULL) {
      head = new_info;
    } else {
      new_info->next = head;
      head = new_info;
    }
  }

  fclose(file);

  print_process_info(head);

  return 0;
}