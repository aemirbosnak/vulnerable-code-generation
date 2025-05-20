//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  int cpu_prev_total = 0;
  int cpu_prev_idle = 0;

  while (1) {
    // Open the proc/stat file
    FILE* stat_file = fopen("/proc/stat", "r");

    // Read the first line of the file, which contains CPU usage stats
    char cpu_line[256];
    fgets(cpu_line, 256, stat_file);

    // Close the file
    fclose(stat_file);

    // Split the first line into individual fields
    char* cpu_fields[10];
    int cpu_total = 0;
    int cpu_idle = 0;
    char* tok = strtok(cpu_line, " ");
    int i = 0;
    while (tok != NULL) {
      cpu_fields[i] = tok;
      i++;

      if (i == 1) continue; // skip the first field, which is "cpu"

      // Calculate total CPU time
      cpu_total += atoi(tok);

      if (i == 5) { // idle time is the 5th field
        cpu_idle = atoi(tok);
        break;
      }

      tok = strtok(NULL, " ");
    }

    // Calculate CPU usage percentage since last measurement
    int cpu_diff_total = cpu_total - cpu_prev_total;
    int cpu_diff_idle = cpu_idle - cpu_prev_idle;
    double cpu_usage = ((double) cpu_diff_total - (double) cpu_diff_idle) / (double) cpu_diff_total * 100.0;

    // Print CPU usage to the console
    printf("CPU usage: %.2f%%\n", cpu_usage);

    // Save current CPU stats for the next measurement
    cpu_prev_total = cpu_total;
    cpu_prev_idle = cpu_idle;

    // Wait 1 second before next measurement
    sleep(1);
  }

  return 0;
}