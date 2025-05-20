//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void print_memory_info() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    // Open the /proc/meminfo file to read memory details
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    printf("******* Memory Information *******\n");
    printf("          Total Memory:          \n");
    
    // Read and print relevant Memory details
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        if (strncmp(buffer, "MemTotal:", 8) == 0) {
            printf("%s", buffer);
        } else if (strncmp(buffer, "MemFree:", 8) == 0) {
            printf("%s", buffer);
        } else if (strncmp(buffer, "MemAvailable:", 13) == 0) {
            printf("%s", buffer);
        } else if (strncmp(buffer, "Buffers:", 8) == 0) {
            printf("%s", buffer);
        } else if (strncmp(buffer, "Cached:", 7) == 0) {
            printf("%s", buffer);
        }
    }
    
    fclose(fp);
    printf("**********************************\n");
}

void memory_usage_over_time(int seconds) {
    printf("Monitoring memory usage every %d seconds...\n", seconds);
    
    while (1) {
        print_memory_info();
        printf("Waiting for %d seconds...\n", seconds);
        sleep(seconds);
    }
}

int main(int argc, char *argv[]) {
    int interval = 5; // Default interval of 5 seconds
    
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            printf("Interval must be a positive integer. Defaulting to 5 seconds.\n");
            interval = 5;
        }
    }
    
    printf("Welcome to the RAM Usage Monitor!\n");
    printf("This program will show you the RAM usage of your system in real-time!\n");
    memory_usage_over_time(interval);
    
    return 0;
}