//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of CPUs to monitor
#define MAX_CPUS 16
// File lengths for reading values from /proc
#define MAX_READ_LEN 64
// Refresh rate in seconds
#define REFRESH_RATE 1

void print_header(int num_cpus) {
  printf("-----------------------------\n");
  printf("   CPU  |  Usage (Percentage)\n");
  printf("-----------------------------\n");
  for(int i = 0; i < num_cpus; i++) {
    printf("    %d   |\n", i);
  }
  printf("-----------------------------\n");
}

int main(int argc, char **argv) {
  // Initialize variables
  int num_cpus = 0;
  double cpu_usage[MAX_CPUS];
  FILE *file;
  char buffer[MAX_READ_LEN];

  // Read available CPUs from /proc/stat
  file = fopen("/proc/stat", "r");
  while(fgets(buffer, MAX_READ_LEN, file) != NULL) {
    if(strncmp(buffer, "cpu", 3) == 0) {
      num_cpus++;
    }
  }
  fclose(file);
  if(num_cpus > MAX_CPUS) {
    fprintf(stderr, "Error: Too many CPUs to monitor\n");
    return 1;
  }

  // Print header
  print_header(num_cpus);

  // Monitor CPU usage
  while(1) {
    // Read CPU usage from /proc/stat
    file = fopen("/proc/stat", "r");
    for(int i = 0; i < num_cpus; i++) {
      fgets(buffer, MAX_READ_LEN, file);
      sscanf(buffer, "cpu%d %*u %*u %*u %*u %*u %*u %*u %*u %*u %lf", &i, &cpu_usage[i]);
    }
    fclose(file);

    // Calculate total CPU usage
    double total_usage = 0;
    for(int i = 0; i < num_cpus; i++) {
      total_usage += cpu_usage[i];
    }

    // Print CPU usage percentages
    printf("\033[13A"); // Move cursor up
    for(int i = 0; i < num_cpus; i++) {
      printf("\033[2K"); // Clear line
      printf("\r    %d   | %6.2f%%", i, cpu_usage[i] / total_usage * 100);
      fflush(stdout);
    }

    // Wait for refresh
    sleep(REFRESH_RATE);
  }

  return 0;
}