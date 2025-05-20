//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function to extract and display the RAM usage information
void display_ram_usage() {
    FILE *file;
    char buffer[BUFFER_SIZE];

    // Open the /proc/meminfo file for reading
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read and print the relevant memory information
    printf("\n=== RAM Usage Monitor ===\n");

    while (fgets(buffer, BUFFER_SIZE, file)) {
        // Check for the Memory lines we are interested in
        if (strstr(buffer, "MemTotal") || strstr(buffer, "MemFree") ||
            strstr(buffer, "Buffers") || strstr(buffer, "Cached")) {
            printf("%s", buffer);
        }
    }

    fclose(file);
}

// Function to perform periodic checking
void monitor_ram_usage(int interval) {
    while (1) {
        printf("\nChecking RAM usage...\n");
        display_ram_usage();
        printf("========================================\n");
        sleep(interval); // Wait for specified interval before next check
    }
}

// Main function where the magic begins
int main(int argc, char *argv[]) {
    int interval = 5; // Default interval set to 5 seconds

    // Parse command-line arguments for custom interval
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Invalid time interval. Please enter a positive integer.\n");
            return EXIT_FAILURE;
        }
    }

    printf("Welcome to the Awesome RAM Usage Monitor!\n");
    printf("We're excited to help you keep track of your memory usage.\n");
    printf("Checking RAM usage every %d seconds...\n", interval);
    printf("Press Ctrl+C to exit the monitor anytime.\n");

    // Start monitoring RAM usage
    monitor_ram_usage(interval);

    return EXIT_SUCCESS;
}