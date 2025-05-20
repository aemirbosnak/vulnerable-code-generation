//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void print_ram_usage() {
    FILE *fp;
    char path[MAX_LINE_LENGTH];
    long total_memory, free_memory, available_memory, used_memory;

    // Open the file containing memory info
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read total memory
    while (fgets(path, sizeof(path), fp) != NULL) {
        if (sscanf(path, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(path, "MemFree: %ld kB", &free_memory) == 1) {
            continue;
        }
        if (sscanf(path, "MemAvailable: %ld kB", &available_memory) == 1) {
            continue;
        }
    }
    fclose(fp);

    used_memory = total_memory - free_memory;
    
    // Print memory usage information
    printf("Total Memory: %.2f GB\n", total_memory / 1024.0 / 1024.0);
    printf("Memory Used: %.2f GB\n", used_memory / 1024.0 / 1024.0);
    printf("Free Memory: %.2f GB\n", free_memory / 1024.0 / 1024.0);
    printf("Available Memory: %.2f GB\n\n", available_memory / 1024.0 / 1024.0);
    
    // Add a separator
    printf("--------------------------------------------------\n");
}

void monitor_ram_usage(int interval) {
    while (1) {
        print_ram_usage();
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 5;

    // Check if user provided an argument
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval < 1) {
            fprintf(stderr, "Interval must be greater than 0. Using default interval of 5 seconds.\n");
            interval = 5;
        }
    }

    printf("Starting RAM usage monitor...\n");
    printf("Press Ctrl+C to exit.\n\n");
    
    // Start the RAM usage monitoring
    monitor_ram_usage(interval);
    
    return 0;
}