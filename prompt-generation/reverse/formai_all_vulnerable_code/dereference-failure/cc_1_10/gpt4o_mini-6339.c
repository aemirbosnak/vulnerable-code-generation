//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to read the CPU usage from the /proc/stat file
void read_cpu_usage(double *cpu_usage) {
    char buffer[256];
    unsigned long idle_time, total_time;
    unsigned long user_time, nice_time, system_time, irq_time, softirq_time, total;

    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line which contains CPU usage information
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu",
           &user_time,
           &nice_time,
           &system_time,
           &idle_time,
           &irq_time,
           &softirq_time);

    // Calculate total time and idle time
    total = user_time + nice_time + system_time + idle_time + irq_time + softirq_time;
    idle_time += idle_time; // Include idle time correctly for calculations

    total_time = total;
    *cpu_usage = 100.0 * (1.0 - (double)idle_time / total_time);

    fclose(fp);
}

// Function to check CPU usage and display it in a mathematical format
void monitor_cpu_usage(int interval) {
    double prev_usage = 0.0, current_usage = 0.0;

    // Loop indefinitely to monitor CPU usage
    while (1) {
        read_cpu_usage(&current_usage);
        
        printf("Current CPU Usage: %.2f%%\n", current_usage);
        
        // Display difference with previous usage
        if (prev_usage != 0.0) {
            double usage_change = current_usage - prev_usage;
            printf("Change in CPU Usage: %.2f%%\n", usage_change);
            printf("Mathematical Representation: U(t) = U(t-1) + ΔU\n", current_usage, usage_change);
        }
        
        prev_usage = current_usage;
        
        // Sleep for the specified interval
        sleep(interval);
    }
}

// Main function to execute the CPU monitoring
int main(int argc, char *argv[]) {
    int interval = 1; // Default interval of 1 second

    // Check if a custom interval is provided
    if (argc == 2) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Interval must be a positive integer.\n");
            return EXIT_FAILURE;
        }
    }
    
    printf("Starting CPU Usage Monitor...\n");
    printf("Monitoring CPU usage every %d seconds:\n", interval);
    
    // Call the CPU usage monitoring function
    monitor_cpu_usage(interval);

    return EXIT_SUCCESS;
}