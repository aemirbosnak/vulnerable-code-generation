//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void monitor_cpu_usage() {
    FILE *fp;
    char buffer[1024];
    size_t bytes_read;

    fp = fopen("/proc/stat", "r");

    if (fp == NULL) {
        fprintf(stderr, "Failed to open /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    // Read the cpu usage values
    bytes_read = fread(buffer, 1, sizeof(buffer), fp);

    if (bytes_read == 0 || bytes_read == sizeof(buffer)) {
        fprintf(stderr, "Failed to read /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0';
    fclose(fp);

    // Parse the cpu usage information
    char *cpu_line = strtok(buffer, "\n");
    cpu_line = strtok(NULL, "\n");

    long unsigned int user, nice, system, idle, iowait, irq, softirq;

    int num_tokens = sscanf(cpu_line, "%*s %lu %lu %lu %lu %lu %lu %lu",
                            &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    if (num_tokens != 7) {
        fprintf(stderr, "Failed to parse cpu usage information\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the total CPU time
    long unsigned int total_time = user + nice + system + idle + iowait + irq + softirq;

    // Calculate the idle CPU time
    long unsigned int idle_time = idle + iowait;

    // Calculate the CPU usage percentage
    double cpu_usage = (1.0 - ((double) idle_time) / total_time) * 100.0;

    printf("CPU usage: %0.2f%%\n", cpu_usage);

    // Wait for 1 second before checking again
    sleep(1);

    // Recursively call the function to monitor CPU usage
    monitor_cpu_usage();
}

int main() {
    monitor_cpu_usage();

    return 0;
}