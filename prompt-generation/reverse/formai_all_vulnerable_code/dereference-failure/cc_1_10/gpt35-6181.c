//FormAI DATASET v1.0 Category: System process viewer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

// function to check if a given string is a number
int isNumber(char *str) {
  int i = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i]))
      return 0;
  }
  return 1;
}

// function to check if a given PID is a valid number
int isValidPID(char *pid) {
  if (isNumber(pid)) {
    char procPath[100] = "/proc/";
    strcat(procPath, pid);
    DIR *dir = opendir(procPath);
    if (dir) {
      closedir(dir);
      return 1;
    }
  }
  return 0;
}

// function to get process name from the given PID
char *getProcName(char *pid) {
  char procPath[100] = "/proc/";
  strcat(procPath, pid);
  strcat(procPath, "/comm");
  char buffer[100];
  FILE *f = fopen(procPath, "r");
  fgets(buffer, 100, f);
  fclose(f);
  return buffer;
}

// function to get process status from the given PID
char *getProcStatus(char *pid) {
  char procPath[100] = "/proc/";
  strcat(procPath, pid);
  strcat(procPath, "/status");
  char buffer[100], *status;
  FILE *f = fopen(procPath, "r");
  while (fgets(buffer, 100, f)) {
    if (strstr(buffer, "State:")) {
      status = strtok(buffer, " \t\n");
      status = strtok(NULL, " \t\n");
      break;
    }
  }
  fclose(f);
  return status;
}

// function to get process memory usage from the given PID
unsigned long int getProcMem(char *pid) {
  char procPath[100] = "/proc/";
  strcat(procPath, pid);
  strcat(procPath, "/statm");
  char buffer[100], *token;
  long int mem;
  FILE *f = fopen(procPath, "r");
  fgets(buffer, 100, f);
  token = strtok(buffer, " \t\n");
  mem = atol(token);
  fclose(f);
  return mem * getpagesize() / 1024;
}

// function to print the process table header
void printHeader() {
    printf("%-10s %-25s %-15s %-15s\n", "PID", "PROCESS NAME", "STATUS", "MEMORY USAGE (KB)");
    printf("---------------------------------------------------------\n");
}

int main() {
  DIR *dir;
  struct dirent *ent;
  char *pid, *procName, *procStatus;
  int processCount = 0;
  unsigned long int procMemUsage = 0, totalMemUsage = 0;

  // open the /proc directory
  if ((dir = opendir("/proc/")) != NULL) {
    // print the table header
    printHeader();
    // read all the entries in the /proc directory
    while ((ent = readdir(dir)) != NULL) {
      // check if the entry is a directory and a valid PID
      pid = ent->d_name;
      if (isNumber(pid) && isValidPID(pid)) {
        // get process details
        procName = getProcName(pid);
        procStatus = getProcStatus(pid);
        procMemUsage = getProcMem(pid);
        // print the process details
        printf("%-10s %-25s %-15s %-15ld\n", pid, procName, procStatus, procMemUsage);
        // update total memory usage
        totalMemUsage += procMemUsage;
        processCount++;
      }
    }
    // close the /proc directory
    closedir(dir);
  } else {
    // could not open the /proc directory
    perror("Could not open /proc directory");
    return EXIT_FAILURE;
  }
  printf("---------------------------------------------------------\n");
  printf("Total number of processes: %d\n", processCount);
  printf("Total memory usage (KB): %ld\n", totalMemUsage);
  return EXIT_SUCCESS;
}