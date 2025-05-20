//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>

// Define the maximum number of processes to display
#define MAX_PROCESSES 100

// Define the maximum length of a process name
#define MAX_PROCESS_NAME_LENGTH 256

// Define the maximum length of a command line
#define MAX_COMMAND_LINE_LENGTH 1024

// Define the maximum number of arguments in a command line
#define MAX_ARGS 32

// Define the maximum length of a directory path
#define MAX_DIRECTORY_PATH_LENGTH 1024

// Define the maximum length of a file path
#define MAX_FILE_PATH_LENGTH 1024

// Create a structure to store information about a process
typedef struct {
  pid_t pid;                // The process ID
  char name[MAX_PROCESS_NAME_LENGTH];  // The process name
  char command_line[MAX_COMMAND_LINE_LENGTH];  // The command line used to start the process
  int args_count;           // The number of arguments in the command line
  char *args[MAX_ARGS];     // The arguments in the command line
} process_info;

// Create a function to compare two processes by their PIDs
int compare_processes(const void *a, const void *b) {
  const process_info *process1 = (const process_info *)a;
  const process_info *process2 = (const process_info *)b;

  return process1->pid - process2->pid;
}

// Create a function to get the list of processes running on the system
int get_process_list(process_info **processes) {
  // Open the directory containing the process information
  DIR *proc_dir = opendir("/proc");
  if (proc_dir == NULL) {
    perror("opendir");
    return -1;
  }

  // Initialize the list of processes
  *processes = malloc(sizeof(process_info) * MAX_PROCESSES);
  if (*processes == NULL) {
    perror("malloc");
    closedir(proc_dir);
    return -1;
  }

  // Iterate over the files in the directory
  int num_processes = 0;
  struct dirent *entry;
  while ((entry = readdir(proc_dir)) != NULL) {
    // Check if the file is a directory
    if (entry->d_type != DT_DIR) {
      continue;
    }

    // Check if the file is a process directory
    int pid = atoi(entry->d_name);
    if (pid <= 0) {
      continue;
    }

    // Get the process information
    process_info *process = &(*processes)[num_processes];
    process->pid = pid;

    // Get the process name
    char proc_name_path[MAX_FILE_PATH_LENGTH];
    snprintf(proc_name_path, sizeof(proc_name_path), "/proc/%d/comm", pid);
    FILE *proc_name_file = fopen(proc_name_path, "r");
    if (proc_name_file == NULL) {
      perror("fopen");
      continue;
    }
    fgets(process->name, sizeof(process->name), proc_name_file);
    fclose(proc_name_file);

    // Get the command line
    char proc_cmdline_path[MAX_FILE_PATH_LENGTH];
    snprintf(proc_cmdline_path, sizeof(proc_cmdline_path), "/proc/%d/cmdline", pid);
    FILE *proc_cmdline_file = fopen(proc_cmdline_path, "r");
    if (proc_cmdline_file == NULL) {
      perror("fopen");
      continue;
    }
    fgets(process->command_line, sizeof(process->command_line), proc_cmdline_file);
    fclose(proc_cmdline_file);

    // Parse the command line
    char *token = strtok(process->command_line, " ");
    process->args_count = 0;
    while (token != NULL) {
      process->args[process->args_count++] = token;
      token = strtok(NULL, " ");
    }

    // Increment the number of processes
    num_processes++;
  }

  // Close the directory
  closedir(proc_dir);

  // Return the number of processes
  return num_processes;
}

// Create a function to print the list of processes
void print_process_list(process_info *processes, int num_processes) {
  // Sort the processes by their PIDs
  qsort(processes, num_processes, sizeof(process_info), compare_processes);

  // Print the header
  printf("%-5s %-256s %-1024s\n", "PID", "Name", "Command Line");

  // Iterate over the processes
  for (int i = 0; i < num_processes; i++) {
    // Print the process information
    printf("%-5d %-256s %-1024s\n", processes[i].pid, processes[i].name, processes[i].command_line);
  }
}

// Create a function to main
int main(void) {
  // Get the list of processes
  process_info *processes;
  int num_processes = get_process_list(&processes);
  if (num_processes == -1) {
    return EXIT_FAILURE;
  }

  // Print the list of processes
  print_process_list(processes, num_processes);

  // Free the list of processes
  free(processes);

  return EXIT_SUCCESS;
}