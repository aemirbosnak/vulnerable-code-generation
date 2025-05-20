//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: automated
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Get the CPU usage in percentage
int get_cpu_usage() {
    FILE *fp;
    char line[1024];
    int user, nice, system, idle, iowait, irq, softirq;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        return -1;
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            sscanf(line, "cpu %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);
            break;
        }
    }
    fclose(fp);

    // Calculate the CPU usage in percentage
    int total = user + nice + system + idle + iowait + irq + softirq;
    int idle_time = idle + iowait;
    int busy_time = total - idle_time;
    int cpu_usage = (busy_time * 100) / total;

    return cpu_usage;
}

// Print the CPU usage in percentage
void print_cpu_usage() {
    int cpu_usage = get_cpu_usage();
    if (cpu_usage == -1) {
        printf("Error getting CPU usage\n");
        return;
    }
    printf("CPU usage: %d%%\n", cpu_usage);
}

// Main function
int main() {
    // Get the CPU usage every second
    while (1) {
        print_cpu_usage();
        sleep(1);
    }

    return 0;
}