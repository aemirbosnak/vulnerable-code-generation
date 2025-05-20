//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFSIZE 1024

void print_proc_info(char *name, int pid, int ppid, int cpu, int mem, int state) {
  printf("Name: %s\n", name);
  printf("PID: %d\n", pid);
  printf("PPID: %d\n", ppid);
  printf("CPU: %d%%\n", cpu);
  printf("Memory: %d MB\n", mem);
  printf("State: %s\n", state);
  printf("------------------------------------\n");
}

int main() {
  DIR *dir;
  struct dirent *entry;
  char path[BUFFSIZE];
  FILE *file;
  char line[BUFFSIZE];
  int pid, ppid, cpu, mem, state;
  char name[BUFFSIZE];

  // Open the /proc directory
  dir = opendir("/proc");
  if (dir == NULL) {
    perror("Error opening /proc directory");
    return EXIT_FAILURE;
  }

  // Iterate over the entries in the /proc directory
  while ((entry = readdir(dir)) != NULL) {
    // Skip entries that are not directories
    if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..") || !entry->d_type == DT_DIR) {
      continue;
    }

    // Get the process ID from the entry name
    pid = atoi(entry->d_name);
    if (pid <= 0) {
      continue;
    }

    // Construct the path to the stat file
    snprintf(path, BUFFSIZE, "/proc/%d/stat", pid);

    // Open the stat file
    file = fopen(path, "r");
    if (file == NULL) {
      perror("Error opening stat file");
      continue;
    }

    // Read the first line of the stat file
    if (fgets(line, BUFFSIZE, file) == NULL) {
      perror("Error reading stat file");
      fclose(file);
      continue;
    }

    // Parse the stat file
    sscanf(line, "%d %s %c %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %llu", &pid, name, &state, &ppid, &cpu, &mem, &state, &state, &state, &state, &state, &state, &state, &state, &state, &state, &state, &state, &state, &state, &state, &state, &state, &state, &state);

    // Close the stat file
    fclose(file);

    // Print the process information
    print_proc_info(name, pid, ppid, cpu, mem, state);
  }

  // Close the /proc directory
  closedir(dir);

  return EXIT_SUCCESS;
}