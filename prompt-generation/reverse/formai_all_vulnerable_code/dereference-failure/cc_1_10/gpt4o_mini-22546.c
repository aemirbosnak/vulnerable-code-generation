//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 1024

void get_memory_usage(float *used_memory, float *total_memory) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Unable to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, "MemTotal:")) {
            sscanf(buffer, "MemTotal: %f kB", total_memory);
        }
        if (strstr(buffer, "MemAvailable:")) {
            float available_memory;
            sscanf(buffer, "MemAvailable: %f kB", &available_memory);
            *used_memory = *total_memory - available_memory;
            break;
        }
    }

    fclose(file);
}

void display_memory_usage(float used_memory, float total_memory) {
    printf("Memory Usage Report:\n");
    printf("---------------------\n");
    printf("Total Memory: %.2f MB\n", total_memory / 1024);
    printf("Used Memory: %.2f MB\n", used_memory / 1024);
    printf("Free Memory: %.2f MB\n", (total_memory - used_memory) / 1024);
    printf("---------------------\n");
}

void repeat_usage_monitor(int interval) {
    while (1) {
        float used_memory = 0;
        float total_memory = 0;
        get_memory_usage(&used_memory, &total_memory);
        display_memory_usage(used_memory, total_memory);
        sleep(interval);
        printf("\nUpdating memory usage...\n\n");
    }
}

int main(int argc, char *argv[]) {
    int interval = 5; // Default to 5 seconds

    if (argc > 1) {
        int user_interval = atoi(argv[1]);
        if (user_interval > 0) {
            interval = user_interval;
        } else {
            printf("Invalid interval provided, using default: %d seconds.\n", interval);
        }
    } else {
        printf("No interval provided, using default: %d seconds.\n", interval);
    }

    printf("Starting RAM Usage Monitor...\n");
    printf("Press Ctrl+C to exit the monitor.\n");
    repeat_usage_monitor(interval);

    return 0;
}