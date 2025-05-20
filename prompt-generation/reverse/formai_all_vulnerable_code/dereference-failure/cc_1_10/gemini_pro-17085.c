//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

typedef struct {
  pid_t pid;
  char name[32];
  long rss, vms;
} Process;

int compare(const void *a, const void *b) {
  Process *p1 = (Process *)a;
  Process *p2 = (Process *)b;
  return p2->rss - p1->rss;
}

int main() {
  // Get process information
  DIR *dir = opendir("/proc");
  if (dir == NULL) {
    perror("Error opening /proc");
    return 1;
  }

  // Initialize memory
  struct dirent *entry;
  Process **processes = malloc(sizeof(Process *) * 1024);
  int count = 0;

  // Iterate over processes
  while ((entry = readdir(dir)) != NULL) {
    if (atoi(entry->d_name) > 0) {
      Process *process = malloc(sizeof(Process));
      process->pid = atoi(entry->d_name);

      // Read process name
      char path[64];
      snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);
      FILE *file = fopen(path, "r");
      if (file == NULL) {
        perror("Error opening comm file");
        return 1;
      }
      fscanf(file, "%s", process->name);
      fclose(file);

      // Read process memory usage
      snprintf(path, sizeof(path), "/proc/%s/statm", entry->d_name);
      file = fopen(path, "r");
      if (file == NULL) {
        perror("Error opening statm file");
        return 1;
      }
      fscanf(file, "%ld %ld", &process->rss, &process->vms);
      fclose(file);

      // Add process to list
      processes[count++] = process;
    }
  }
  closedir(dir);

  // Sort processes by memory usage
  qsort(processes, count, sizeof(Process *), compare);

  // Print process information
  printf("%-5s %-32s %-7s %-7s\n", "PID", "Name", "RSS", "VMS");
  for (int i = 0; i < count; i++) {
    Process *process = processes[i];
    printf("%-5d %-32s %-7ld %-7ld\n", process->pid, process->name, process->rss, process->vms);
  }

  // Free memory
  for (int i = 0; i < count; i++) {
    free(processes[i]);
  }
  free(processes);

  return 0;
}