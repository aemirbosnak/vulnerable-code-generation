//FormAI DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

// Function to check if a string is numeric
int isNumeric(char* str) {
  for (int i = 0; i < strlen(str); i++) {
    if (!isdigit(str[i])) {
      return 0;
    }
  }
  return 1;
}

// Function to extract the process ID from the process name
int getPID(char* name) {
  DIR* dir;
  struct dirent* ent;
  char* endptr;
  char buf[512];

  if (!(dir = opendir("/proc"))) {
    perror("Cannot open /proc directory");
    exit(EXIT_FAILURE);
  }

  int found = 0;
  while ((ent = readdir(dir)) != NULL) {
    if (isNumeric(ent->d_name)) {
      strcpy(buf, "/proc/");
      strcat(buf, ent->d_name);
      strcat(buf, "/comm");

      FILE* fp = fopen(buf, "r");
      if (fp) {
        fgets(buf, sizeof(buf), fp);
        buf[strlen(buf)-1] = '\0';

        if (strcmp(name, buf) == 0) {
          found = 1;
          break;
        }
        fclose(fp);
      }
    }
  }

  if (found) {
    return strtol(ent->d_name, &endptr, 10);
  }
  return -1;
}

// Function to display process information
void displayProcessInfo(int pid) {
  char file[100];
  sprintf(file, "/proc/%d/stat", pid);

  FILE* fp = fopen(file, "r");
  if (fp) {
    char buf[512];
    fgets(buf, sizeof(buf), fp);
    fclose(fp);

    char* token;
    int count = 0;

    token = strtok(buf, " ");
    while (token != NULL) {
      count++;
      if (count == 3) {
        printf("Process ID: %d\n", pid);
        printf("Name: %s\n", token);
      }
      if (count == 14) {
        printf("CPU Time: %ld\n", strtol(token, NULL, 10));
      }
      if (count == 23) {
        printf("RSS: %ld\n", strtol(token, NULL, 10));
      }
      token = strtok(NULL, " ");
    }
  }
}

int main(int argc, char** argv) {

  if (argc != 2) {
    printf("Usage: %s <process name>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int pid = getPID(argv[1]);

  if (pid == -1) {
    printf("Process not found.\n");
    exit(EXIT_FAILURE);
  }

  displayProcessInfo(pid);

  return 0;
}