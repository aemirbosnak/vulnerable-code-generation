//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
    unsigned long steal;
    unsigned long total;
} CPUInfo;

void read_cpu_info(CPUInfo* cpu_info) {
    FILE* file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), file) == NULL) {
        perror("Failed to read from /proc/stat");
        fclose(file);
        exit(1);
    }
    fclose(file);

    sscanf(line, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
           &cpu_info->user,
           &cpu_info->nice,
           &cpu_info->system,
           &cpu_info->idle,
           &cpu_info->iowait,
           &cpu_info->irq,
           &cpu_info->softirq,
           &cpu_info->steal);
    
    cpu_info->total = cpu_info->user + cpu_info->nice + cpu_info->system +
                      cpu_info->idle + cpu_info->iowait + cpu_info->irq +
                      cpu_info->softirq + cpu_info->steal;
}

double calculate_cpu_usage(CPUInfo* prev, CPUInfo* curr) {
    unsigned long prev_total = prev->total;
    unsigned long curr_total = curr->total;

    unsigned long total_diff = curr_total - prev_total;
    unsigned long idle_diff = curr->idle - prev->idle;

    if (total_diff == 0) return 0.0; // Avoid division by zero

    return (1.0 - (double)idle_diff / total_diff) * 100.0;
}

void monitor_cpu_usage(int interval) {
    CPUInfo prev_cpu_info, curr_cpu_info;

    read_cpu_info(&prev_cpu_info);
    sleep(interval);

    while (1) {
        read_cpu_info(&curr_cpu_info);
        double usage = calculate_cpu_usage(&prev_cpu_info, &curr_cpu_info);
        printf("CPU Usage: %.2f%%\n", usage);

        prev_cpu_info = curr_cpu_info;
        sleep(interval);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interval_in_seconds>\n", argv[0]);
        return 1;
    }

    int interval = atoi(argv[1]);
    if (interval <= 0) {
        fprintf(stderr, "Interval must be a positive integer.\n");
        return 1;
    }

    printf("Starting CPU usage monitor... (every %d second(s))\n", interval);
    monitor_cpu_usage(interval);

    return 0;
}