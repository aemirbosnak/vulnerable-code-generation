//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

// Function to display RAM usage
void display_ram_usage() {
    struct sysinfo memInfo;
    
    // Get memory information
    if (sysinfo(&memInfo) != 0) {
        perror("sysinfo");
        exit(EXIT_FAILURE);
    }

    // Calculate total and free memory
    long totalRAM = memInfo.totalram;
    long freeRAM = memInfo.freeram;
    long usedRAM = totalRAM - freeRAM;

    // Convert bytes to megabytes
    totalRAM /= (1024 * 1024);
    freeRAM /= (1024 * 1024);
    usedRAM /= (1024 * 1024);

    // Display RAM usage
    printf("Total RAM: %ld MB\n", totalRAM);
    printf("Used RAM: %ld MB\n", usedRAM);
    printf("Free RAM: %ld MB\n", freeRAM);
    printf("\n");
}

// Function to monitor RAM usage at intervals
void monitor_ram_usage(int interval) {
    while (1) {
        display_ram_usage();
        printf("Monitoring RAM usage for next %d seconds...\n", interval);
        sleep(interval);
    }
}

// Main function
int main(int argc, char *argv[]) {
    int interval = 5; // Default interval of 5 seconds

    // Check if the user provided a command line argument for interval
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Invalid interval. Using default value of 5 seconds.\n");
            interval = 5;
        } else {
            printf("Monitoring RAM usage every %d seconds...\n", interval);
        }
    } else {
        printf("No interval provided. Using default value of 5 seconds.\n");
    }

    // Start monitoring
    monitor_ram_usage(interval);

    return 0;
}