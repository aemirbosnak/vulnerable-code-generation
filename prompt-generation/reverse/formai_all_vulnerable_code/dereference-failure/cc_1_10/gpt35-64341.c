//FormAI DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX_PID_LENGTH 6
#define MAX_NAME_LENGTH 255
#define MAX_STATUS_LENGTH 4096

void viewProcessInfo(char* pid) {
  char pidDir[MAX_NAME_LENGTH];
  char pidName[MAX_NAME_LENGTH];
  
  // Retrieve process name
  strcpy(pidDir, "/proc/");
  strcat(pidDir, pid);
  strcat(pidDir, "/comm");

  FILE* f = fopen(pidDir, "r");
  if (f == NULL)
    return;
  
  fgets(pidName, MAX_NAME_LENGTH, f);
  if (strlen(pidName) > 0 && pidName[strlen(pidName) - 1] == '\n')
    pidName[strlen(pidName) - 1] = '\0';
  fclose(f);

  // Retrieve process status
  char pidStatus[MAX_STATUS_LENGTH];
  strcpy(pidDir, "/proc/");
  strcat(pidDir, pid);
  strcat(pidDir, "/status");

  f = fopen(pidDir, "r");
  if (f == NULL)
    return;
  
  fread(pidStatus, MAX_STATUS_LENGTH, 1, f);
  fclose(f);

  // Print process info
  printf("Process: %s\n", pidName);
  printf("PID: %s\n", pid);
  printf("Status: %s\n", pidStatus);
  printf("--------------------------\n");
}

void viewProcesses() {
  DIR* procDir = opendir("/proc");
  if (procDir == NULL) {
    printf("Unable to read /proc directory.\n");
    return;
  }

  struct dirent* entry;
  while ((entry = readdir(procDir))) {
    // Check if entry is a directory and can be converted to int
    if (entry->d_type != DT_DIR || atoi(entry->d_name) == 0)
      continue;
  
    char pid[MAX_PID_LENGTH];
    strcpy(pid, entry->d_name);
    viewProcessInfo(pid);
  }

  closedir(procDir);
}

int main() {
  printf("Viewing system processes...\n");

  viewProcesses();

  printf("End of process list.\n");
  return 0;
}