//FormAI DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

// function to check whether string is a number or not 
int isNumber(char* s) {
  for(int i = 0; i < strlen(s); i++) {
    if(!isdigit(s[i])) {
      return 0;
    }
  }
  return 1;
}

// function to print process info
void printProcInfo(char* pid) {
  char path[50];
  sprintf(path, "/proc/%s/status", pid);
  FILE* fp = fopen(path, "r");
  if(fp != NULL) {
    char line[256];
    while(fgets(line, sizeof(line), fp)) {
      if(strncmp(line, "Name:", 5) == 0) {
        printf("%s", line);
      }
      if(strncmp(line, "State:", 6) == 0) {
        printf("%s", line);
      }
      if(strncmp(line, "VmSize:", 7) == 0) {
        printf("%s", line);
      }
    }
    fclose(fp);
  }
}

// function to list all running processes
void listProcesses() {
  DIR* dp = opendir("/proc");
  struct dirent* entry;
  while((entry = readdir(dp))) {
    if(isNumber(entry->d_name)) {
      printProcInfo(entry->d_name);
    }
  }
  closedir(dp);
}

// main function
int main() {
  printf("=============== Retro Task Manager ===============\n");
  printf("PID\tNAME\t\t\tSTATUS\t\tVM SIZE\n");
  listProcesses();
  return 0;
}