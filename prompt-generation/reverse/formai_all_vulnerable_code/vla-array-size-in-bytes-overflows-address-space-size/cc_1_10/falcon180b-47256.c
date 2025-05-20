//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_CPU_USAGE 100
#define SLEEP_TIME 1

int main() {
    int i, j;
    int cpus = sysconf(_SC_NPROCESSORS_ONLN);
    struct rusage usage;
    double cpu_usage[cpus];
    int cpu_count = 0;
    char buffer[50];

    // Initialize CPU usage to zero
    for (i = 0; i < cpus; i++) {
        cpu_usage[i] = 0.0;
    }

    // Get CPU usage every second
    while (1) {
        getrusage(RUSAGE_SELF, &usage);

        // Calculate CPU usage for each CPU
        for (i = 0; i < cpus; i++) {
            cpu_usage[i] = ((double) usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec / 1000000.0) / ((double) SLEEP_TIME);
            if (cpu_usage[i] > MAX_CPU_USAGE) {
                cpu_usage[i] = MAX_CPU_USAGE;
            }
        }

        // Print CPU usage
        printf("\r");
        for (i = 0; i < cpus; i++) {
            if (cpu_usage[i] > 0) {
                sprintf(buffer, "CPU%d: %.2f%% ", i + 1, cpu_usage[i] * 100.0);
                printf("%s", buffer);
                cpu_count++;
            }
        }
        printf("\n");

        // Sleep for one second
        sleep(SLEEP_TIME);
    }

    return 0;
}