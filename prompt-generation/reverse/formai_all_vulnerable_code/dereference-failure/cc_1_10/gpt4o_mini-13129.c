//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define CPU_INFO_SIZE 1024

typedef struct CPUUsage {
    long user;
    long nice;
    long sys;
    long idle;
    long iowait;
    long irq;
    long softirq;
} CPUUsage;

// Function to parse CPU usage from /proc/stat
CPUUsage get_cpu_usage() {
    FILE *file = fopen("/proc/stat", "r");
    CPUUsage cpu_usage = {0};
    
    if (file) {
        char buffer[CPU_INFO_SIZE];
        fgets(buffer, sizeof(buffer), file); // Read the first line
        sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld",
               &cpu_usage.user, &cpu_usage.nice, &cpu_usage.sys, 
               &cpu_usage.idle, &cpu_usage.iowait, &cpu_usage.irq, 
               &cpu_usage.softirq);
        fclose(file);
    } else {
        fprintf(stderr, "Error: Could not open /proc/stat\n");
        exit(EXIT_FAILURE);
    }
    
    return cpu_usage;
}

// Function to calculate CPU usage percentage
double calculate_cpu_usage(CPUUsage *start, CPUUsage *end) {
    long total_start = start->user + start->nice + start->sys + start->idle + 
                       start->iowait + start->irq + start->softirq;
    long total_end = end->user + end->nice + end->sys + end->idle + 
                     end->iowait + end->irq + end->softirq;

    long busy_start = total_start - start->idle;
    long busy_end = total_end - end->idle;

    return 100.0 * (busy_end - busy_start) / (total_end - total_start);
}

// Function to display CPU usage
void display_cpu_usage(double usage) {
    printf("CPU Usage: %.2f%%\n", usage);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interval_in_seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int interval = atoi(argv[1]);
    
    if (interval == 0) {
        fprintf(stderr, "Error: Interval must be greater than 0\n");
        return EXIT_FAILURE;
    }
    
    while (1) {
        CPUUsage start = get_cpu_usage();
        sleep(interval);
        CPUUsage end = get_cpu_usage();
        
        double cpu_usage = calculate_cpu_usage(&start, &end);
        display_cpu_usage(cpu_usage);
    }

    return EXIT_SUCCESS;
}