//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define CPU_USAGE_PRINT_INTERVAL 1  // Seconds between each CPU usage measurement
#define MAX_LINE_LENGTH 1024
#define MAX_CPUS 1024

int main(int argc, char *argv[]) {
    double prev_cpu_time[MAX_CPUS], curr_cpu_time[MAX_CPUS];
    double cpu_diff[MAX_CPUS];
    char line[MAX_LINE_LENGTH];

    FILE *proc_stat_file;

    int num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    int i, j;
    double total_usage;

    printf("Monitoring CPU usage (in percent)...\n");

    // Set initial values for previous CPU time
    for (i = 0; i < num_cpus; i++) {
        prev_cpu_time[i] = 0.0;
    }

    // Loop to periodically measure CPU usage
    while (1) {
        // Open the /proc/stat file that contains CPU time information
        proc_stat_file = fopen("/proc/stat", "r");
        if (!proc_stat_file) {
            fprintf(stderr, "Error opening /proc/stat: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // Read the line that contains total CPU time information
        fgets(line, MAX_LINE_LENGTH, proc_stat_file);

        // Close the /proc/stat file
        fclose(proc_stat_file);

        // Skip past the "cpu" string at the beginning of the line
        char *tok = strtok(line, " ");
        tok = strtok(NULL, " ");

        // Parse CPU time information for each CPU
        total_usage = 0.0;
        for (i = 0; i < num_cpus; i++) {
            tok = strtok(NULL, " ");
            curr_cpu_time[i] = atof(tok);
            cpu_diff[i] = curr_cpu_time[i] - prev_cpu_time[i];
            prev_cpu_time[i] = curr_cpu_time[i];
            total_usage += cpu_diff[i];
        }

        // Calculate and print CPU usage percentages
        for (i = 0; i < num_cpus; i++) {
            printf("CPU %d: %.1f%%\t", i, (100.0 * cpu_diff[i] / total_usage));
        }
        printf("\n");

        // Sleep for specified interval
        sleep(CPU_USAGE_PRINT_INTERVAL);
    }

    return 0;
}