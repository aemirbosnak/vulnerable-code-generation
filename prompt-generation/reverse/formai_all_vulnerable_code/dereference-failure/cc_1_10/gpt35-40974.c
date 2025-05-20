//FormAI DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_DIRECTORY "/proc"
#define MAX_PID_LENGTH 6
#define MAX_COMMAND_LENGTH 256
#define MAX_STAT_LENGTH 1000
#define MAX_STATUS_LENGTH 6000

// Function to check if a string represents a number
int is_number(char* str) {
  for (int i = 0; i < strlen(str); i++) {
    if (!isdigit(str[i])) {
      return 0;
    }
  }
  return 1;
}

// Function to read the process command from /proc/pid/cmdline
void read_process_command(char* pid, char* command) {
  // Create the filepath
  char filepath[MAX_COMMAND_LENGTH];
  sprintf(filepath, "%s/%s/cmdline", PROC_DIRECTORY, pid);

  // Open the file for reading
  FILE* file = fopen(filepath, "r");

  // Read the command from the file
  if (file) {
    fgets(command, MAX_COMMAND_LENGTH, file);
    fclose(file);
  }
}

// Function to read the process status from /proc/pid/status
void read_process_status(char* pid, char* status) {
  // Create the filepath
  char filepath[MAX_COMMAND_LENGTH];
  sprintf(filepath, "%s/%s/status", PROC_DIRECTORY, pid);

  // Open the file for reading
  FILE* file = fopen(filepath, "r");

  // Read the status from the file
  if (file) {
    fseek(file, 0, SEEK_SET);
    fgets(status, MAX_STATUS_LENGTH, file);
    fclose(file);
  }
}

// Function to parse the process status and extract required information
void parse_process_status(char* pid, char* status) {
  // Define variables
  char* line;
  char state;
  int ppid = -1;
  long int rss = -1;
  
  // Parse the status file line by line
  line = strtok(status, "\n");
  while (line != NULL) {
    // Check if the line represents the process state
    if (strncmp(line, "State:", 6) == 0) {
      state = line[7];
    }
    // Check if the line represents the parent process id
    else if (strncmp(line, "PPid:", 5) == 0) {
      ppid = atoi(line + 6);
    }
    // Check if the line represents the resident set size
    else if (strncmp(line, "VmRSS:", 6) == 0) {
      rss = atol(line + 7);
    }
    // Move to the next line
    line = strtok(NULL, "\n");
  }

  // Print the extracted information
  printf("%-6s%-20s%-10c%-10d%ld KB\n", pid, "process name", state, ppid, rss);
}

int main() {
  // Define variables
  DIR* dir;
  struct dirent* dir_entry;
  char pid[MAX_PID_LENGTH];
  char command[MAX_COMMAND_LENGTH];
  char status[MAX_STATUS_LENGTH];

  // Print the table header
  printf("%-6s%-20s%-10s%-10s%s\n", "PID", "COMMAND", "STATE", "PPID", "RSS");

  // Open the /proc directory
  dir = opendir(PROC_DIRECTORY);
  if (dir) {
    // Loop through all directory entries
    while ((dir_entry = readdir(dir)) != NULL) {
      // Check if the entry represents a process directory (a directory with only digits in its name)
      if (is_number(dir_entry->d_name)) {
        strcpy(pid, dir_entry->d_name);
        read_process_command(pid, command);
        read_process_status(pid, status);
        parse_process_status(pid, status);
      }
    }
    closedir(dir);
  }

  // Exit the program
  return 0;
}