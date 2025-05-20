//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 256

typedef struct {
    unsigned long user, nice, system, idle, iowait, irq, softirq, steal, total;
} CPUStats;

void read_cpu_stats(CPUStats *cpu_stats) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, file);
    fclose(file);

    sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
           &cpu_stats->user,
           &cpu_stats->nice,
           &cpu_stats->system,
           &cpu_stats->idle,
           &cpu_stats->iowait,
           &cpu_stats->irq,
           &cpu_stats->softirq,
           &cpu_stats->steal);
    
    cpu_stats->total = cpu_stats->user + cpu_stats->nice + cpu_stats->system +
                       cpu_stats->idle + cpu_stats->iowait + cpu_stats->irq +
                       cpu_stats->softirq + cpu_stats->steal;
}

double calculate_cpu_usage(CPUStats *old_stats, CPUStats *new_stats) {
    unsigned long total_diff = new_stats->total - old_stats->total;
    unsigned long idle_diff = new_stats->idle - old_stats->idle;

    return total_diff == 0 ? 0.0 : (1.0 - (double)idle_diff / (double)total_diff) * 100.0;
}

void monitor_cpu_usage(int interval, int duration) {
    CPUStats old_stats, new_stats;

    read_cpu_stats(&old_stats);
    sleep(interval);

    for (int i = 0; i < duration / interval; i++) {
        read_cpu_stats(&new_stats);
        double usage = calculate_cpu_usage(&old_stats, &new_stats);
        
        printf("CPU Usage: %.2f%%\n", usage);
        
        old_stats = new_stats;
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <interval in seconds> <duration in seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int interval = atoi(argv[1]);
    int duration = atoi(argv[2]);

    if (interval <= 0 || duration <= 0) {
        fprintf(stderr, "Both interval and duration must be positive integers.\n");
        return EXIT_FAILURE;
    }

    printf("Monitoring CPU usage every %d second(s) for %d second(s)...\n", interval, duration);
    monitor_cpu_usage(interval, duration);

    return EXIT_SUCCESS;
}