//FormAI DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH 1024 // maximum path

// struct to store basic process info
struct ProcessInfo {
  char pid[32];
  char command[MAX_PATH];
  char state[32];
  char memory[32];
};

// function to parse the status file and get process info
void read_stat_file(char *pid, struct ProcessInfo *proc) {
  char filename[MAX_PATH];
  snprintf(filename, MAX_PATH, "/proc/%s/status", pid);

  FILE *fp = fopen(filename, "r");

  if (!fp) {
    printf("Error: unable to open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  char line[MAX_PATH];
  char *token;
  while (fgets(line, MAX_PATH, fp) != NULL) {
    if (strstr(line, "Name:") != NULL) {
      token = strtok(line, " ");
      token = strtok(NULL, " ");
      strcpy(proc->command, token);
      strtok(NULL, "\n");
    } else if (strstr(line, "State:") != NULL) {
      token = strtok(line, "\t");
      token = strtok(NULL, " ");
      strcpy(proc->state, token);
    } else if (strstr(line, "VmRSS:") != NULL) {
      token = strtok(line, "\t");
      token = strtok(NULL, " ");
      token = strtok(NULL, " ");
      strcpy(proc->memory, token);
    }
  }

  fclose(fp);
}

int main(void) {
  DIR *dir;
  struct dirent *ent;

  dir = opendir("/proc/");
  if (dir == NULL) {
    perror("Error: could not open /proc directory");
    exit(EXIT_FAILURE);
  }

  printf("%-10s %-20s %-10s %-10s\n", "PID", "COMMAND", "STATE", "MEMORY");

  while ((ent = readdir(dir)) != NULL) {
    if (!isdigit(ent->d_name[0])) {
      continue;
    }

    struct ProcessInfo proc;
    strcpy(proc.pid, ent->d_name);

    read_stat_file(proc.pid, &proc);

    printf("%-10s %-20s %-10s %-10s\n", proc.pid, proc.command, proc.state, proc.memory);
  }

  closedir(dir);

  return 0;
}