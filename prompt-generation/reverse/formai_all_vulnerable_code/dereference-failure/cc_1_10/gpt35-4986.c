//FormAI DATASET v1.0 Category: System process viewer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define SHOW_CMD_LINE_ARGS 0
#define SHOW_NON_STOPPED_PROCESSES 1
#define SHOW_ALL_PROCESSES 2

/* Function to get process status from /proc/PID/status file */
char* get_process_status(char* pid) {
  FILE *file;
  char filename[30], status[300];
  sprintf(filename, "/proc/%s/status", pid);
  file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }
  while (fgets(status, 300, file)) {
    char* token;
    if (strstr(status, "State")) {
      token = strtok(status, ":\t"); // delimiter can either be tab or colon followed by space
      token = strtok(NULL, ":\t");
      char* state = malloc(sizeof(char) * (strlen(token) + 1));
      strncpy(state, token, strlen(token) + 1);
      fclose(file);
      return state;
    }
  }
  fclose(file);
  return NULL;
}

/* Function to get process name from /proc/PID/comm file */
char* get_process_name(char* pid) {
  FILE *file;
  char filename[30], pname[100];
  sprintf(filename, "/proc/%s/comm", pid);
  file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }
  fgets(pname, 100, file);
  char* name = malloc(sizeof(char) * (strlen(pname) + 1));
  strncpy(name, pname, strlen(pname) + 1);
  fclose(file);
  return name;
}

/* Function to check if a string is a number */
int is_number(char *s) {
  int len = strlen(s);
  for(int i = 0; i < len; i++) {
    if (!isdigit(*(s+i))) {
      return 0;
    }
  }
  return 1;
}

/* Function to display process details */
void display_processes(int show_mode) {
  DIR *dir;
  struct dirent *entry;
  dir = opendir("/proc");
  if (dir == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }
  printf("%-10s %-20s %-10s %-20s %-10s %s\n", "PID", "Process Name", "State", "User", "Threads", "Command Line");
  while ((entry = readdir(dir)) != NULL) {
    if (is_number(entry->d_name)) {
      char* pid = entry->d_name;
      switch (show_mode) {
        case SHOW_CMD_LINE_ARGS:
          // Display only processes that have command line arguments
          {
            char filename[50];
            sprintf(filename, "/proc/%s/cmdline", pid);
            FILE* file = fopen(filename, "r");
            if (file == NULL) {
              printf("Error opening file for process %s\n", pid);
              break;
            }
            int c, c_count = 0;
            while((c=getc(file)) != EOF) {
              c_count++;
              if (c == '\0') {
                break;
              }
            }
            fclose(file);
            if (c_count > 1) { // cmdline file contains at least one argument
              char* pname = get_process_name(pid);
              char* state = get_process_status(pid);
              char details[300];
              sprintf(details, "cat /proc/%s/cmdline", pid);
              FILE *cmd_line_args_pipe = popen(details, "r");
              if (cmd_line_args_pipe == NULL) {
                printf("Error opening pipe for process %s\n", pid);
                break;
              }
              char cmd_line_args[300];
              fgets(cmd_line_args, 300, cmd_line_args_pipe);
              pclose(cmd_line_args_pipe);
              printf("%-10s %-20s %-10s %-20s %-10s %s\n", pid, pname, state, "root", "", cmd_line_args);
              free(pname);
              free(state);
            }
            break;
          }
        case SHOW_NON_STOPPED_PROCESSES:
          // Display only non-stopped processes
          {
            char* state = get_process_status(pid);
            if (state != NULL && strcmp(state, "R (running)") == 0) {
              char* pname = get_process_name(pid);
              char details[300];
              sprintf(details, "ps -p %s --no-headers --format=nlwp", pid);
              FILE *threads_pipe = popen(details, "r");
              if (threads_pipe == NULL) {
                printf("Error opening pipe for process %s\n", pid);
                break;
              }
              char threads[10];
              fgets(threads, 10, threads_pipe);
              pclose(threads_pipe);
              printf("%-10s %-20s %-10s %-20s %-10s %s\n", pid, pname, state, "root", threads, "");
              free(pname);
              free(state);
            }
            break;
          }
        case SHOW_ALL_PROCESSES:
          // Display all processes
          {
            char* pname = get_process_name(pid);
            char* state = get_process_status(pid);
            char cmd_line_args[300];
            sprintf(cmd_line_args, "ps -o command= -p %s", pid);
            FILE *cmd_line_args_pipe = popen(cmd_line_args, "r");
            if (cmd_line_args_pipe == NULL) {
              printf("Error opening pipe for process %s\n", pid);
              break;
            }
            fgets(cmd_line_args, 300, cmd_line_args_pipe);
            pclose(cmd_line_args_pipe);
            char details[300];
            sprintf(details, "ps -p %s --no-headers --format=nlwp", pid);
            FILE *threads_pipe = popen(details, "r");
            if (threads_pipe == NULL) {
              printf("Error opening pipe for process %s\n", pid);
              break;
            }
            char threads[10];
            fgets(threads, 10, threads_pipe);
            pclose(threads_pipe);
            if (pname != NULL && state != NULL) {
              printf("%-10s %-20s %-10s %-20s %-10s %s\n", pid, pname, state, "root", threads, cmd_line_args);
              free(pname);
              free(state);
            }
            break;
          }
        default:
          printf("Invalid show mode specified\n");
          exit(EXIT_FAILURE);
      }
    }
  }
  closedir(dir);
}

int main(int argc,char** argv) {
  int show_mode = SHOW_ALL_PROCESSES;
  if (argc > 1) {
    if (strcmp(argv[1], "-c") == 0) {
      show_mode = SHOW_CMD_LINE_ARGS;
    }
    else if (strcmp(argv[1], "-n") == 0) {
      show_mode = SHOW_NON_STOPPED_PROCESSES;
    }
    else {
      printf("Invalid arguments specified\n");
      exit(EXIT_FAILURE);
    }
  }
  display_processes(show_mode);
  return 0;
}