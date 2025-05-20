//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main() {
  DIR *procfs;
  struct dirent *dp;
  struct stat s;
  int pid;
  char path[256];
  char name[256];
  char state;
  int ppid;
  int utime;
  int stime;

  procfs = opendir("/proc");
  if (procfs == NULL) {
    perror("opendir");
    exit(1);
  }

  while ((dp = readdir(procfs)) != NULL) {
    if (dp->d_name[0] < '0' || dp->d_name[0] > '9')
      continue;

    pid = atoi(dp->d_name);

    sprintf(path, "/proc/%d", pid);
    if (stat(path, &s) == -1)
      continue;

    sprintf(path, "/proc/%d/stat", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
      continue;

    fscanf(fp, "%d %s %c %d %d %d %d %d", &pid, name, &state, &ppid, &utime, &stime);
    fclose(fp);

    printf("PID: %d, Name: %s, State: %c, PPID: %d, UTime: %d, STime: %d\n", pid, name, state, ppid, utime, stime);
  }

  closedir(procfs);

  return 0;
}