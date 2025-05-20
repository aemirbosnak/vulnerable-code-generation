//FormAI DATASET v1.0 Category: System process viewer ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define PROC_DIR "/proc"
#define MAX_PATH 1024
#define MAX_BUF 4096

bool is_number(const char* str) {
  while (*str) {
    if (!isdigit(*str)) {
      return false;
    }
    str++;
  }
  return true;
}

int main(int argc, char* argv[]) {
  DIR* dir_ptr;
  struct dirent* entry_ptr;
  char pid_dir[MAX_PATH];
  char buf[MAX_BUF];

  if ((dir_ptr = opendir(PROC_DIR)) == NULL) {
    fprintf(stderr, "Error opening proc directory\n");
    return -1;
  }

  printf("%5s %15s %10s %10s %s\n", "PID", "COMM", "STATE", "PPID", "CMDLINE");
  while ((entry_ptr = readdir(dir_ptr)) != NULL) {
    if (is_number(entry_ptr->d_name)) {
      sprintf(pid_dir, "%s/%s", PROC_DIR, entry_ptr->d_name);
      FILE* status_file = fopen(strcat(pid_dir, "/status"), "r");
      int pid, ppid;
      char comm[MAX_BUF], state[MAX_BUF];

      if (status_file != NULL) {
        while (fgets(buf, MAX_BUF, status_file)) {
          if (sscanf(buf, "Name:\t%s", comm) == 1) {
            continue;
          }
          else if (sscanf(buf, "State:\t%s", state) == 1) {
            continue;
          }
          else if (sscanf(buf, "Pid:\t%d", &pid) == 1) {
            continue;
          }
          else if (sscanf(buf, "PPid:\t%d", &ppid) == 1) {
            continue;
          }
        }
        fclose(status_file);
      }
      else {
        continue;
      }

      FILE* cmdline_file = fopen(strcat(entry_ptr->d_name, "/cmdline"), "r");
      char cmdline[MAX_BUF];

      if (cmdline_file != NULL) {
        fgets(cmdline, MAX_BUF, cmdline_file);
        fclose(cmdline_file);
      }
      else {
        cmdline[0] = '\0';
      }

      printf("%5d %15s %10s %10d %s\n", pid, comm, state, ppid, cmdline);
    }
  }

  closedir(dir_ptr);

  return 0;
}