//FormAI DATASET v1.0 Category: System process viewer ; Style: high level of detail
// This is a C System Process Viewer Example Program

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Function to get the name of a process from its PID
char* get_process_name(int pid) {
  char* name = malloc(1024);
  sprintf(name, "/proc/%d/cmdline", pid);
  FILE* fp = fopen(name, "r");
  if(fp) {
    fgets(name, 1024, fp);
    fclose(fp);
    return name;
  }
  free(name);
  return NULL;
}

// Function to get the status of a process from its PID
char* get_process_status(int pid) {
  char* status = malloc(1024);
  sprintf(status, "/proc/%d/status", pid);
  FILE* fp = fopen(status, "r");
  if(fp) {
    fgets(status, 1024, fp);
    fclose(fp);
    return status;
  }
  free(status);
  return NULL;
}

// Main function
int main() {
  DIR* dirp;
  struct dirent* entry;
  dirp = opendir("/proc");
  printf("%-10s %-20s %-20s\n", "PID", "NAME", "STATUS");
  while((entry = readdir(dirp)) != NULL) {
    if(entry->d_type == DT_DIR) {
      int pid = atoi(entry->d_name);
      if(pid > 0) {
        char* name = get_process_name(pid);
        char* status = get_process_status(pid);
        if(name && status) {
          printf("%-10d %-20s %-20s\n", pid, name, status);
        }
        free(name);
        free(status);
      }
    }
  }
  closedir(dirp);
  return 0;
}