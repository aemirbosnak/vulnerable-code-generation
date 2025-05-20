//FormAI DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

// Function to check whether a given string represents a number
int is_number(char* str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] < '0' || str[i] > '9') {
      return 0;
    }
  }
  return 1;
}

// Function to get the process information
void get_process_info(char* pid) {
  char proc_path[100];
  sprintf(proc_path, "/proc/%s/stat", pid);

  FILE* proc_file = fopen(proc_path, "r");
  if (proc_file) {
    char line[1024];
    fgets(line, sizeof(line), proc_file);
    fclose(proc_file);

    // Parsing the information from the stat file
    char* token = strtok(line, " ");
    int count = 0;
    while (token != NULL) {
      count++;
      if (count == 2) {
        printf("%6s", token); // PID
      } else if (count == 3) {
        printf("%6s", token); // Parent PID
      } else if (count == 4) {
        printf("%6s", token); // Process group ID
      } else if (count == 14) {
        printf("%6s", token); // User time
      } else if (count == 15) {
        printf("%6s", token); // System time
      } else if (count == 23) {
        printf("%s", token); // Command name
        break;
      }
      token = strtok(NULL, " ");
    }
  } else {
    printf("Error: Cannot read process information\n");
  }
}

int main() {
  // Iterate through the /proc directory to get the list of process IDs
  DIR* proc_dir = opendir("/proc");
  struct dirent* entry;
  while ((entry = readdir(proc_dir)) != NULL) {
    if (is_number(entry->d_name)) {
      get_process_info(entry->d_name);
      printf("\n");
    }
  }
  closedir(proc_dir);
  return 0;
}