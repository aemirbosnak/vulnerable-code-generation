//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

// Wait for a second
#define WAIT 1000000

int main() {
  // Declare variables
  struct timeval start, end;
  double elapsed_time;
  FILE *fp;
  char line[1024];
  char *token;
  int previous_idle, previous_total, idle, total, utilization;

  // Open the file
  fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  // Get the initial values
  fgets(line, sizeof(line), fp);
  token = strtok(line, " ");
  token = strtok(NULL, " ");
  previous_idle = atoi(token);
  token = strtok(NULL, " ");
  previous_total = atoi(token);

  // Wait for a second
  usleep(WAIT);

  // Get the final values
  rewind(fp);
  fgets(line, sizeof(line), fp);
  token = strtok(line, " ");
  token = strtok(NULL, " ");
  idle = atoi(token);
  token = strtok(NULL, " ");
  total = atoi(token);

  // Calculate the CPU utilization
  elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
  utilization = 100 * (1 - (idle - previous_idle) / (total - previous_total));

  // Print the results
  printf("CPU utilization: %d%%\n", utilization);

  // Close the file
  fclose(fp);

  return 0;
}