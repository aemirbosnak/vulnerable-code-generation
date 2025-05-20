//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 256
#define INTERVAL 2 // Time interval for CPU usage measurement in seconds

/**
 * This function returns the current CPU usage in percentage
 */
float get_cpu_usage() {
    FILE* fp;
    char buffer[BUFFER_SIZE];
    char* token;
    int active_cpus, idle_time;
    long int user_time, nice_time, system_time, idle_process_time, iowait_time, irq_time, sirq_time;

    // Open file to read CPU usage
    fp = fopen("/proc/stat", "r");
    if(fp == NULL) {
        perror("Error opening file /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line of the file which contains the overall CPU usage
    if(fgets(buffer, BUFFER_SIZE, fp) == NULL) {
        perror("Error reading file /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Close the file now that we have the data we need
    fclose(fp);

    // Parse the line to extract CPU usage data
    token = strtok(buffer, " ");
    token = strtok(NULL, " "); // Skip 'cpu' label
    user_time = strtol(token, NULL, 10);
    token = strtok(NULL, " ");
    nice_time = strtol(token, NULL, 10);
    token = strtok(NULL, " ");
    system_time = strtol(token, NULL, 10);
    token = strtok(NULL, " ");
    idle_process_time = strtol(token, NULL, 10);
    token = strtok(NULL, " ");
    iowait_time = strtol(token, NULL, 10);
    token = strtok(NULL, " ");
    irq_time = strtol(token, NULL, 10);
    token = strtok(NULL, " ");
    sirq_time = strtol(token, NULL, 10);

    // Calculate total CPU time
    long int total_time = user_time + nice_time + system_time + idle_process_time + iowait_time + irq_time + sirq_time;
    // Calculate CPU idle time
    idle_time = idle_process_time + iowait_time;
    // Get number of active CPUs
    active_cpus = get_nprocs();

    // Calculate CPU usage in percentage
    return ((float)(active_cpus * (total_time - idle_time)) / total_time) * 100;
}

int main() {
    float cpu_usage;
    struct timeval current_time;

    // Infinite loop to continuously get and print CPU usage
    while(1) {
        // Get current CPU usage
        cpu_usage = get_cpu_usage();
        // Get current time
        gettimeofday(&current_time, NULL);
        // Print CPU usage and current time
        printf("CPU usage: %.2f%% - Current time: %ld.%06ld\n", cpu_usage, current_time.tv_sec, current_time.tv_usec);
        // Sleep for the specified interval
        sleep(INTERVAL);
    }

    return 0;
}