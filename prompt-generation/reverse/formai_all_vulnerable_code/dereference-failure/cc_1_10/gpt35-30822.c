//FormAI DATASET v1.0 Category: System process viewer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define PROC_DIRECTORY "/proc/"
#define MAX_PROC_ID 65535
#define MAX_PROC_PATH_SIZE 512
#define MAX_PROC_NAME_SIZE 128

typedef struct {
  int pid;
  char name[MAX_PROC_NAME_SIZE];
} Process;

int isNumeric(char* str) {
  int i = 0;
  while(str[i]) {
    if (!isdigit(str[i++]))
      return 0;
  }
  return 1;
}

Process* getProcesses(size_t* size) {
  DIR* procDir;
  struct dirent* ent;
  Process* processes = (Process*)malloc(sizeof(Process) * MAX_PROC_ID);
  int count = 0;

  if ((procDir = opendir(PROC_DIRECTORY)) != NULL) {
    while ((ent = readdir(procDir)) != NULL) {
      if (isNumeric(ent->d_name)) {
        char path[MAX_PROC_PATH_SIZE];
        snprintf(path, sizeof(path), "%s/%s/cmdline", PROC_DIRECTORY, ent->d_name);
        FILE* file = fopen(path, "r");
        if (file) {
          fgets(processes[count].name, MAX_PROC_NAME_SIZE, file);
          fclose(file);
          processes[count].pid = atoi(ent->d_name);
          count++;
        }
      }
    }
    closedir(procDir);
  }
  *size = count;
  return processes;
}

void showProcesses(Process* processes, size_t size) {
  system("clear");
  printf("PID\tNAME\n");
  for (int i = 0; i < size; i++) {
    printf("%d\t%s", processes[i].pid, processes[i].name);
  }
}

int main(int argc, char* argv[]) {
  while (1) {
    size_t size;
    Process* processes = getProcesses(&size);
    showProcesses(processes, size);
    free(processes);
    sleep(1);
  }
  return 0;
}