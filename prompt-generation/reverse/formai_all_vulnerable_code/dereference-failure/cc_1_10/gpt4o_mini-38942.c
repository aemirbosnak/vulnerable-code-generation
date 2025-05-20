//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LINE_LENGTH 256

void display_memory_usage() {
    FILE *fp;
    char buffer[LINE_LENGTH];

    // Command to get memory info using /proc/meminfo
    fp = popen("cat /proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(EXIT_FAILURE);
    }

    // Read the output a line at a time
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Display just the first 5 lines from meminfo
        if (strstr(buffer, "MemTotal:") || strstr(buffer, "MemFree:") || 
            strstr(buffer, "MemAvailable:") || strstr(buffer, "Buffers:") || 
            strstr(buffer, "Cached:")) {
            printf("%s", buffer);
        }
    }

    // Close the command stream
    pclose(fp);
}

int main(int argc, char *argv[]) {
    int refresh_interval = 1; // Default refresh interval in seconds

    // Check for command-line arguments to set refresh interval
    if (argc > 1) {
        int user_interval = atoi(argv[1]);
        if (user_interval > 0) {
            refresh_interval = user_interval;
        } else {
            fprintf(stderr, "Invalid refresh interval. Using default value of 1 second.\n");
        }
    }

    printf("RAM Usage Monitor\n");
    printf("Refresh Interval: %d seconds\n", refresh_interval);
    printf("Press Ctrl+C to exit.\n\n");

    while (1) {
        // Clear the terminal
        printf("\033[H\033[J");
        // Display memory usage
        display_memory_usage();
        // Sleep for the specified interval
        sleep(refresh_interval);
    }

    return 0;
}