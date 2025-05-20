//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 256
#define MAX_CPU 64

const char *PROC_STAT_FILE = "/proc/stat";

int main(int argc, char *argv[]) {
  int interval = 1;  // Default interval (in seconds)
  if (argc > 1) {
    interval = atoi(argv[1]);
  }

  unsigned long long prev_idle[MAX_CPU];
  unsigned long long prev_total[MAX_CPU];

  // Read initial CPU usage
  FILE *stat_file = fopen(PROC_STAT_FILE, "r");
  if (! stat_file) {
    printf("Unable to open %s\n", PROC_STAT_FILE);
    return 1;
  }

  char buf[BUF_SIZE];
  fgets(buf, BUF_SIZE, stat_file);  // Total CPU utilization (discard)
  for (int i = 0; i < MAX_CPU; i++) {
    // Read utilization for each CPU core
    fgets(buf, BUF_SIZE, stat_file);
    char *fields = strtok(buf, " ");  // Skip cpuX label
    prev_idle[i] = atoll(strtok(NULL, " "));
    prev_idle[i] += atoll(strtok(NULL, " "));
    prev_total[i] = prev_idle[i] + atoll(strtok(NULL, " "));
    for (int j = 3; j < 10; j++) {
      prev_total[i] += atoll(strtok(NULL, " "));
    }
  }

  fclose(stat_file);

  for (;;) {
    // Wait for next interval
    sleep(interval);

    stat_file = fopen(PROC_STAT_FILE, "r");
    if (! stat_file) {
      printf("Unable to open %s\n", PROC_STAT_FILE);
      return 1;
    }

    fgets(buf, BUF_SIZE, stat_file);  // Total CPU utilization (discard)

    printf("%-5s %-15s %12s %7s\n", "Time", "CPU", "Usage", "Idle");
    for (int i = 0; i < MAX_CPU; i++) {
      // Read utilization for each CPU core
      fgets(buf, BUF_SIZE, stat_file);

      char cpu_label[5];
      sprintf(cpu_label, "cpu%d", i);
      if (strncmp(buf, cpu_label, strlen(cpu_label)) != 0) {
        printf("Unable to parse %s\n", PROC_STAT_FILE);
        return 1;
      }

      unsigned long long idle = atoll(strtok(buf, " "));
      idle += atoll(strtok(NULL, " "));
      unsigned long long total = idle + atoll(strtok(NULL, " "));
      for (int j = 3; j < 10; j++) {
        total += atoll(strtok(NULL, " "));
      }

      // Calculate CPU usage since last interval
      unsigned long long idle_diff = idle - prev_idle[i];
      unsigned long long total_diff = total - prev_total[i];
      double usage = (double) (total_diff - idle_diff) / total_diff * 100;
      printf("%-5d %-15s %12.2f %7.2f\n", interval, cpu_label, usage, (double) idle_diff / total_diff * 100);

      prev_idle[i] = idle;
      prev_total[i] = total;
    }

    fclose(stat_file);
  }

  return 0;
}