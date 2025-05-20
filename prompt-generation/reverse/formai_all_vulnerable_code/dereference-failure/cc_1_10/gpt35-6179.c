//FormAI DATASET v1.0 Category: System process viewer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LINE_LEN 1024
#define MAX_PID_LEN 6
#define SLEEP_TIME 1

char* get_process_cmd_line(pid_t pid) {
  char* cmd_line_path = calloc(MAX_LINE_LEN, sizeof(char));
  sprintf(cmd_line_path, "/proc/%d/cmdline", pid);
  FILE* fp = fopen(cmd_line_path, "r");
  if (fp == NULL) {
    printf("Unable to open `%s`\n", cmd_line_path);
    free(cmd_line_path);
    return NULL;
  }
  char* cmd_line = calloc(MAX_LINE_LEN, sizeof(char));
  fgets(cmd_line, MAX_LINE_LEN, fp);
  fclose(fp);
  free(cmd_line_path);
  return cmd_line;
}

bool is_numeric(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

void print_processes() {
  DIR* proc_dir = opendir("/proc");
  if (proc_dir == NULL) {
    printf("Unable to open `/proc`\n");
    return;
  }
  printf("%-6s %-20s %s\n", "PID", "CMD", "STATE");
  struct dirent* ent;
  while ((ent = readdir(proc_dir))) {
    char* name = ent->d_name;
    if (is_numeric(name)) {
      pid_t pid = atoi(name);
      char* cmd_line = get_process_cmd_line(pid);
      if (cmd_line != NULL) {
        char* state_path = calloc(MAX_LINE_LEN, sizeof(char));
        sprintf(state_path, "/proc/%d/stat", pid);
        FILE* fp = fopen(state_path, "r");
        char* state_str = calloc(MAX_LINE_LEN, sizeof(char));
        fgets(state_str, MAX_LINE_LEN, fp);
        fclose(fp);
        char* state = calloc(MAX_LINE_LEN, sizeof(char));
        sscanf(state_str, "%*d %*s %s", state);
        printf("%-6d %-20s %s\n", pid, cmd_line, state);
        free(cmd_line);
        free(state_path);
        free(state_str);
        free(state);
      }
    }
  }
  closedir(proc_dir);
}

int main() {
  printf("Welcome to the curious process viewer!\n");
  while (true) {
    printf("Printing current processes...\n");
    print_processes();
    printf("Sleeping for %d second(s)\n", SLEEP_TIME);
    sleep(SLEEP_TIME);
  }
  return 0;
}