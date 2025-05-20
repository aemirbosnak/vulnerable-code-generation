//FormAI DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void printProcessInfo(const char *pid) {
  char dirname[100], procfile[100], cmdline[100], state;
  int ppid;
  long int priority;
  FILE *fp;

  sprintf(dirname, "/proc/%s", pid);
  sprintf(procfile, "/proc/%s/stat", pid);

  fp = fopen(procfile, "r");

  fscanf(fp, "%s %*s %c", &cmdline, &state);

  if(state == 'T') {
    printf("%s: %s    State: Stopped", pid, cmdline);
  }
  else {
    fscanf(fp, " %*d %*d %d %*d %*d %*d %*lu %*lu %*lu %*lu %*lu %*lu %*ld %ld", &ppid, &priority);

    printf("%s: %s    PPID: %d    Priority: %ld", pid, cmdline, ppid, priority);
  }

  fclose(fp);
}

int main() {
  DIR *d;
  struct dirent *dir;
  char pid[10];

  d = opendir("/proc");

  if(d) {
    printf("PID   Program   PPID   Priority\n");

    while ((dir = readdir(d)) != NULL) {
      if (dir->d_type == DT_DIR) {
        strcpy(pid, dir->d_name);

        if(atoi(pid) != 0) {
          printProcessInfo(pid);
          printf("\n");
        }
      }
    }

    closedir(d);
  }
  
  return 0;
}