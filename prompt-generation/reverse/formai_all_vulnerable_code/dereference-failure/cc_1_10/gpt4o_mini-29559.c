//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_memory_info() {
    FILE *fp;
    char buffer[256];

    // Open the meminfo file
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    printf("\n✨ Memory Usage Information ✨\n");
    printf("--------------------------------\n");

    // Read and print memory information
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, "MemTotal") || strstr(buffer, "MemFree") || strstr(buffer, "MemAvailable")) {
            printf("%s", buffer);
        }
    }

    fclose(fp);
}

void print_ram_usage(int interval) {
    while (1) {
        // Clear the screen
        printf("\033[H\033[J");

        // Print memory info
        print_memory_info();

        // Sleep for the specified interval
        printf("\n🕒 Waiting for %d seconds...\n", interval);
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 5; // Default interval for monitoring

    // If the user specifies an interval, ensure it's a positive integer
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            printf("⛔ Invalid interval! Using default of 5 seconds.\n");
            interval = 5;
        } else {
            printf("🛠️ Monitoring memory usage every %d seconds.\n", interval);
        }
    }

    printf("🌟 Welcome to the RAM Usage Monitor! 🌟\n");
    printf("Press Ctrl+C to exit the program at any time.\n");

    // Start monitoring
    print_ram_usage(interval);
    
    return 0;
}