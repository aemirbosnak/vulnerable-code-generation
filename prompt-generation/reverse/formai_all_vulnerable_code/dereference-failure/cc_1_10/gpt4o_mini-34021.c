//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define SLEEP_TIME 1

void get_memory_usage(double *total_memory, double *used_memory) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Unable to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }
    
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal: %lf kB", total_memory) == 1) {
            *total_memory /= 1024;  // Convert to MB
        } else if (sscanf(buffer, "MemAvailable: %lf kB", used_memory) == 1) {
            *used_memory /= 1024;  // Convert to MB
            *used_memory = *total_memory - *used_memory; // Calculate used memory
            break;  // Exit after getting our required values
        }
    }
    
    fclose(file);
}

void display_memory_usage(double total_memory, double used_memory) {
    printf("\nMemory Usage:\n");
    printf("================================\n");
    printf("Total Memory: %.2f MB\n", total_memory);
    printf("Used Memory : %.2f MB\n", used_memory);
    printf("Free Memory : %.2f MB\n", total_memory - used_memory);
    printf("================================\n");
}

int main(int argc, char *argv[]) {
    int interval = SLEEP_TIME; // Default interval in seconds

    // Handle command line arguments
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Invalid interval specified. Using default 1 second.\n");
            interval = SLEEP_TIME;
        }
    }

    double total_memory = 0.0;
    double used_memory = 0.0;

    printf("Starting RAM usage monitor...\n");
    printf("Monitoring every %d seconds.\n", interval);
    
    while (1) {
        get_memory_usage(&total_memory, &used_memory);
        display_memory_usage(total_memory, used_memory);

        sleep(interval); // Wait for the specified interval
    }

    return 0;
}