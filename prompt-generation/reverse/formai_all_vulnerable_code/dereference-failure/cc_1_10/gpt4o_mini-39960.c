//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

#define SLEEP_INTERVAL 1
#define BUFFER_SIZE 256

// Function to get RAM usage
void get_ram_usage(float *total, float *free, float *used) {
    struct sysinfo si;
    sysinfo(&si);

    *total = si.totalram / (1024.0 * 1024.0); // Total RAM in MB
    *free = si.freeram / (1024.0 * 1024.0);  // Free RAM in MB
    *used = (*total - *free);                 // Used RAM in MB
}

// Function to display RAM usage
void display_ram_usage(float total, float free, float used) {
    printf("Total RAM: %.2f MB\n", total);
    printf("Free RAM: %.2f MB\n", free);
    printf("Used RAM: %.2f MB\n", used);
    printf("Used RAM Percentage: %.2f%%\n", (used / total) * 100);
}

// Function to log RAM usage to a file
void log_ram_usage_to_file(float total, float free, float used) {
    FILE *file = fopen("ram_usage.log", "a");
    if (file != NULL) {
        fprintf(file, "Total RAM: %.2f MB, Free RAM: %.2f MB, Used RAM: %.2f MB\n", total, free, used);
        fclose(file);
    } else {
        perror("Error opening log file");
    }
}

// Function to monitor RAM usage over time
void monitor_ram_usage(int duration) {
    float total, free, used;
    int iterations = duration / SLEEP_INTERVAL;

    for (int i = 0; i < iterations; i++) {
        get_ram_usage(&total, &free, &used);

        // Display the RAM usage
        display_ram_usage(total, free, used);

        // Log the RAM usage
        log_ram_usage_to_file(total, free, used);

        // Sleep for the specified interval
        sleep(SLEEP_INTERVAL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <duration in seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int duration = atoi(argv[1]);
    if (duration <= 0) {
        fprintf(stderr, "Please provide a valid positive integer for duration.\n");
        return EXIT_FAILURE;
    }

    printf("Starting RAM usage monitor for %d seconds...\n", duration);
    monitor_ram_usage(duration);
    
    printf("Monitoring completed.\n");
    return EXIT_SUCCESS;
}