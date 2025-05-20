//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

// Define the maximum length of a process name
#define MAX_PROC_NAME_LENGTH 256

// Define the structure of a process
typedef struct {
  pid_t pid;               // Process ID
  char name[MAX_PROC_NAME_LENGTH];  // Process name
  int state;                // Process state
  int ppid;                // Parent process ID
} process_t;

// Compare two processes by their PIDs
int compare_processes(const void *a, const void *b) {
  const process_t *proc1 = (const process_t *)a;
  const process_t *proc2 = (const process_t *)b;

  return proc1->pid - proc2->pid;
}

// Get the list of processes
int get_processes(process_t **processes) {
  // Open the directory containing the process information
  DIR *dir = opendir("/proc");
  if (dir == NULL) {
    perror("opendir");
    return -1;
  }

  // Allocate memory for the array of processes
  *processes = malloc(sizeof(process_t) * 1024);
  if (*processes == NULL) {
    perror("malloc");
    closedir(dir);
    return -1;
  }

  // Read the directory and get the information for each process
  int num_processes = 0;
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Check if the entry is a directory
    if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
      continue;
    }

    // Check if the entry is a numeric directory
    int pid = atoi(entry->d_name);
    if (pid == 0) {
      continue;
    }

    // Get the process information
    process_t *proc = &(*processes)[num_processes];
    proc->pid = pid;
    snprintf(proc->name, sizeof(proc->name), "/proc/%d/comm", pid);
    FILE *fp = fopen(proc->name, "r");
    if (fp == NULL) {
      perror("fopen");
      continue;
    }
    fgets(proc->name, sizeof(proc->name), fp);
    fclose(fp);
    proc->name[strlen(proc->name) - 1] = '\0';  // Remove the newline character
    proc->state = -1;
    proc->ppid = -1;

    // Get the process state
    snprintf(proc->name, sizeof(proc->name), "/proc/%d/stat", pid);
    fp = fopen(proc->name, "r");
    if (fp == NULL) {
      perror("fopen");
      continue;
    }
    char buf[1024];
    fgets(buf, sizeof(buf), fp);
    fclose(fp);

    // Parse the process state from the stat file
    char *state_str = strtok(buf, " ");
    if (state_str != NULL) {
      proc->state = state_str[0] - '0';
    }

    // Get the parent process ID
    char *ppid_str = strtok(NULL, " ");
    if (ppid_str != NULL) {
      proc->ppid = atoi(ppid_str);
    }

    // Increment the number of processes
    num_processes++;
  }

  // Close the directory
  closedir(dir);

  // Sort the processes by their PIDs
  qsort(*processes, num_processes, sizeof(process_t), compare_processes);

  // Return the number of processes
  return num_processes;
}

// Print the information for each process
void print_processes(process_t *processes, int num_processes) {
  printf("%-6s %-16s %-2s %-6s\n", "PID", "NAME", "STATE", "PPID");
  for (int i = 0; i < num_processes; i++) {
    process_t *proc = &processes[i];
    printf("%-6d %-16s %-2d %-6d\n", proc->pid, proc->name, proc->state, proc->ppid);
  }
}

// Main function
int main() {
  // Get the list of processes
  process_t *processes;
  int num_processes = get_processes(&processes);
  if (num_processes == -1) {
    return EXIT_FAILURE;
  }

  // Print the information for each process
  print_processes(processes, num_processes);

  // Free the memory allocated for the array of processes
  free(processes);

  return EXIT_SUCCESS;
}