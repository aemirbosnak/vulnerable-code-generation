//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void get_ram_usage(float* total_ram, float* used_ram) {
    FILE* file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %f kB", total_ram) == 1) {
            *total_ram /= 1024; // Convert to MB
        }
        if (sscanf(line, "MemAvailable: %f kB", used_ram) == 1) {
            *used_ram = *total_ram - (*used_ram / 1024); // Convert to MB
        }
    }

    fclose(file);
}

void display_ram_usage(float total_ram, float used_ram) {
    printf("Total RAM: %.2f MB\n", total_ram);
    printf("Used RAM: %.2f MB\n", used_ram);
    printf("Free RAM: %.2f MB\n", total_ram - used_ram);
}

void monitor_ram_usage(int duration, int interval) {
    float total_ram = 0.0, used_ram = 0.0;

    for (int i = 0; i < duration / interval; i++) {
        get_ram_usage(&total_ram, &used_ram);
        display_ram_usage(total_ram, used_ram);
        printf("Monitoring... (Interval: %d seconds)\n", interval);
        sleep(interval);
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <duration in seconds> <interval in seconds>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int duration = atoi(argv[1]);
    int interval = atoi(argv[2]);

    if (duration <= 0 || interval <= 0) {
        fprintf(stderr, "Both duration and interval must be positive integers.\n");
        exit(EXIT_FAILURE);
    }

    printf("Starting RAM usage monitor...\n");
    monitor_ram_usage(duration, interval);
    printf("Monitoring completed.\n");

    return 0;
}