//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main(void) {
  char cmd[MAX_LINE];
  char buffer[MAX_LINE];
  char *cmd_result;
  int cpu_usage;

  while (1) {
    // Execute command to get CPU usage
    sprintf(cmd, "cat /proc/stat | grep '^cpu '");
    FILE* fp = popen(cmd, "r");
    if (fp == NULL) {
      fprintf(stderr, "Error executing command\n");
      exit(EXIT_FAILURE);
    }

    // Parse the CPU usage from the command output
    if (fgets(buffer, MAX_LINE, fp) != NULL) {
      char *tok = strtok(buffer, " ");
      int values[7];
      for (int i = 0; i < 7; i++) {
        tok = strtok(NULL, " ");
        values[i] = atoi(tok);
      }
      // Calculate the CPU usage percentage
      int total_time = 0;
      for (int i = 0; i < 7; i++) {
        total_time += values[i];
      }
      int idle_time = values[3];
      cpu_usage = 100 - (idle_time * 100 / total_time);
    }

    // Close the command's output file
    pclose(fp);

    // Print the CPU usage percentage
    printf("Current CPU usage: %d%%\n", cpu_usage);

    // Wait for 1 second before checking again
    sleep(1);
  }

  return 0;
}