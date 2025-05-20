//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_FREQUENCY 100 // Hz
#define MIN_FREQUENCY 1 // Hz
#define DEFAULT_FREQUENCY 10 // Hz

// Get the current CPU usage.
int get_cpu_usage() {
    FILE *fp;
    int cpu_usage;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        return -1;
    }

    fscanf(fp, "cpu %d %d %d %d %d %d %d %d", &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage);
    fclose(fp);

    return cpu_usage;
}

// Main function.
int main(int argc, char *argv[]) {
    int frequency = DEFAULT_FREQUENCY;
    int cpu_usage;

    // Parse command line arguments.
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            frequency = atoi(argv[++i]);
            if (frequency < MIN_FREQUENCY || frequency > MAX_FREQUENCY) {
                fprintf(stderr, "Frequency must be between %d and %d Hz.\n", MIN_FREQUENCY, MAX_FREQUENCY);
                return 1;
            }
        }
    }

    // Main loop.
    while (1) {
        // Get the current CPU usage.
        cpu_usage = get_cpu_usage();
        if (cpu_usage == -1) {
            fprintf(stderr, "Error getting CPU usage.\n");
            return 1;
        }

        // Print the CPU usage.
        printf("CPU usage: %d%%\n", cpu_usage);

        // Sleep for the specified interval.
        usleep(1000000 / frequency);
    }

    return 0;
}