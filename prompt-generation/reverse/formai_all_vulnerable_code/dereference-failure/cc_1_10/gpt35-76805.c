//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PID_LEN 50
#define MAX_NAME_LEN 200

// Function to check if a given string is an integer
int is_integer(const char* str) {
  int len = strlen(str);

  for (int i = 0; i < len; i++) {
    if (!isdigit(str[i])) {
      return 0;
    }
  }

  return 1;
}

// Function to get the name of a process associated with a given PID
char* get_process_name(const char* pid_str) {
  static char name[MAX_NAME_LEN];
  char path[MAX_PID_LEN + 12];
  int fd, n;

  snprintf(path, sizeof(path), "/proc/%s/comm", pid_str);

  fd = open(path, O_RDONLY);

  if (fd == -1) {
    return pid_str;
  }

  n = read(fd, name, sizeof(name) - 1);

  if (n == -1) {
    close(fd);
    return pid_str;
  }

  if (name[n - 1] == '\n') {
    name[n - 1] = '\0';
  } else {
    name[n] = '\0';
  }

  close(fd);
  return name;
}

// Function to format and display the information about a process
void display_process_info(const char* pid_str) {
  char process_name[MAX_NAME_LEN];

  strcpy(process_name, get_process_name(pid_str));

  printf("%-9s %s\n", pid_str, process_name);
}

// Function to read the list of running processes and display their information
void display_processes() {
  DIR* proc_dir;
  struct dirent* ent;
  char pid_str[MAX_PID_LEN];

  printf("PID       Process Name\n");

  proc_dir = opendir("/proc");

  if (proc_dir == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }

  while ((ent = readdir(proc_dir))) {
    if (is_integer(ent->d_name)) {
      strcpy(pid_str, ent->d_name);
      display_process_info(pid_str);
    }
  }

  closedir(proc_dir);
}

int main() {
  display_processes();
  
  return 0;
}