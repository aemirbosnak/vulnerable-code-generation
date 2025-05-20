//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the maximum length for line input
#define MAX_LINE_LENGTH 1024

// Define the file path for memory information
#define MEM_INFO_PATH "/proc/meminfo"

// Define the memory unit size
#define MEMORY_UNIT_SIZE 1024

// Define the refresh interval in seconds
#define REFRESH_INTERVAL 5

// Define the main entry point for the program
int main(int argc, char* argv[]) {

    // Define the memory usage variables
    long total_memory = -1;
    long free_memory = -1;
    long used_memory = -1;
    float memory_usage_percentage = 0.0;

    // Define the loop variables
    int i = 0;
    int j = 0;

    // Define the buffer variables
    char line[MAX_LINE_LENGTH];
    char* token = NULL;

    // Define the configuration variables
    int show_total_memory = 1;
    int show_free_memory = 1;
    int show_used_memory = 1;
    int show_memory_usage_percentage = 1;

    // Parse the command line arguments
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--no-total-memory") == 0) {
            show_total_memory = 0;
        } else if (strcmp(argv[i], "--no-free-memory") == 0) {
            show_free_memory = 0;
        } else if (strcmp(argv[i], "--no-used-memory") == 0) {
            show_used_memory = 0;
        } else if (strcmp(argv[i], "--no-memory-usage-percentage") == 0) {
            show_memory_usage_percentage = 0;
        } else if (strcmp(argv[i], "--help") == 0) {
            printf("Usage: %s [--no-total-memory] [--no-free-memory] [--no-used-memory] [--no-memory-usage-percentage] [--help]\n", argv[0]);
            return 0;
        }
    }

    // Define the infinite loop for monitoring memory usage
    while(1) {

        // Open the memory information file
        FILE* fp = fopen(MEM_INFO_PATH, "r");
        if (fp == NULL) {
            printf("Error: failed to open file: %s\n", MEM_INFO_PATH);
            return 1;
        }

        // Initialize the memory usage variables
        total_memory = -1;
        free_memory = -1;
        used_memory = -1;

        // Read each line of the memory information file
        while(fgets(line, MAX_LINE_LENGTH, fp)) {

            // Remove the newline from the line
            line[strcspn(line, "\n")] = '\0';

            // Extract the key and value from the line
            token = strtok(line, " ");
            if (token == NULL) {
                continue;
            }
            long value = strtol(strtok(NULL, " "), NULL, 10);

            // Determine the memory usage information based on the key
            if (strcmp(token, "MemTotal:") == 0) {
                total_memory = value;
            } else if (strcmp(token, "MemFree:") == 0) {
                free_memory = value;
            } else if (strcmp(token, "Buffers:") == 0) {
                used_memory += value;
            } else if (strcmp(token, "Cached:") == 0) {
                used_memory += value;
            }

        }

        // Close the memory information file
        fclose(fp);

        // Check that the memory usage variables have been initialized
        if (total_memory == -1 || free_memory == -1 || used_memory == -1) {
            printf("Error: failed to read memory information from file: %s\n", MEM_INFO_PATH);
            return 1;
        }

        // Calculate the memory usage percentage
        memory_usage_percentage = ((float) used_memory / total_memory) * 100.0f;

        // Print the memory usage information
        printf("Memory usage: ");
        if (show_total_memory) {
            printf("%ld MB total, ", total_memory / MEMORY_UNIT_SIZE);
        }
        if (show_free_memory) {
            printf("%ld MB free, ", free_memory / MEMORY_UNIT_SIZE);
        }
        if (show_used_memory) {
            printf("%ld MB used, ", used_memory / MEMORY_UNIT_SIZE);
        }
        if (show_memory_usage_percentage) {
            printf("%.1f%% used\n", memory_usage_percentage);
        } else {
            printf("\n");
        }

        // Wait for the refresh interval
        sleep(REFRESH_INTERVAL);

    }

    // Return success
    return 0;

}