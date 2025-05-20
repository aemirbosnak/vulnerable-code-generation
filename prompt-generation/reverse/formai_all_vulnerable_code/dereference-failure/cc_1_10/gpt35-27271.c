//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>

#define CPU_USAGE_REFRESH_TIME 1 // in seconds

int main() {
  // get number of CPUs available
  int num_cpus = get_nprocs();

  // allocate memory for array of previous CPU totals
  unsigned long long *prev_cpu_totals = malloc(sizeof(unsigned long long) * num_cpus);
  memset(prev_cpu_totals, 0, sizeof(unsigned long long) * num_cpus);

  while (1) {
    // sleep for specified refresh time
    sleep(CPU_USAGE_REFRESH_TIME);

    // open /proc/stat file for reading
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        fprintf(stderr, "Error opening /proc/stat file\n");
        exit(1);
    }

    // read first line of file containing overall CPU stats
    char line[256];
    fgets(line, sizeof(line), fp);

    // close file now that we have what we need
    fclose(fp);

    // calculate CPU usage percentages
    char cpu_label[32];
    unsigned long long values[10]; // max possible values in /proc/stat
    sscanf(line, "%s %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
        cpu_label,
        &values[0], &values[1], &values[2], &values[3], &values[4],
        &values[5], &values[6], &values[7], &values[8], &values[9]);

    unsigned long long total_time = 0;
    for (int i = 0; i < 10; i++) {
        total_time += values[i];
    }

    for (int i = 0; i < num_cpus; i++) {
        unsigned long long cpu_time = values[i+1]; // skip first "cpu" label
        unsigned long long prev_cpu_time = prev_cpu_totals[i];
        double cpu_percentage = ((double) (cpu_time - prev_cpu_time) / (double) (total_time - prev_cpu_time)) * 100.0;

        printf("CPU %d usage: %.2f%%\n", i, cpu_percentage);

        // update previous CPU total for this CPU
        prev_cpu_totals[i] = cpu_time;
    }
  }

  free(prev_cpu_totals);
  
  return 0;
}