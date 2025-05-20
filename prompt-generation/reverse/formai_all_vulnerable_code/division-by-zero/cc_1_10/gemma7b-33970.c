//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main() {
  char buffer[BUFFER_SIZE];
  int i = 0, cpu_usage = 0, prev_cpu_usage = 0, total_time = 0, prev_time = 0;
  FILE *fp = NULL;

  // Open a file for logging
  fp = fopen("cpu_usage.log", "w");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Loop until the user decides to quit
  while (1) {
    // Get the current CPU usage
    cpu_usage = get_cpu_usage();

    // Calculate the time spent in the loop
    time_t current_time = time(NULL);
    total_time = current_time - prev_time;
    prev_time = current_time;

    // Calculate the CPU usage percentage
    int cpu_usage_percentage = (cpu_usage - prev_cpu_usage) * 100 / total_time;

    // Write the CPU usage to the file
    fprintf(fp, "Time: %d, CPU Usage: %.2f%%\n", total_time, cpu_usage_percentage);

    prev_cpu_usage = cpu_usage;

    // Sleep for a while
    sleep(1);
  }

  fclose(fp);
  return 0;
}

// Function to get the CPU usage in percentage
int get_cpu_usage() {
  FILE *fp = NULL;
  char buffer[BUFFER_SIZE];
  int lines = 0, total_user = 0, total_system = 0, total_idle = 0;

  fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the CPU usage statistics
  fgets(buffer, BUFFER_SIZE, fp);

  // Parse the statistics
  lines = atoi(buffer);
  total_user = atoi(buffer + 12);
  total_system = atoi(buffer + 16);
  total_idle = atoi(buffer + 20);

  // Calculate the CPU usage percentage
  int cpu_usage = (total_user + total_system) * 100 / lines;

  fclose(fp);
  return cpu_usage;
}