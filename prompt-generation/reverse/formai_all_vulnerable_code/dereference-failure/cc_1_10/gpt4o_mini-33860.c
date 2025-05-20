//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define MEMORY_INFO_FILE "/proc/meminfo"

void parse_memory_info(const char *line, long *total, long *free, long *available) {
    char key[50];
    long value;
    sscanf(line, "%s %ld", key, &value);
    
    if (strcmp(key, "MemTotal:") == 0) {
        *total = value;
    } else if (strcmp(key, "MemFree:") == 0) {
        *free = value;
    } else if (strcmp(key, "MemAvailable:") == 0) {
        *available = value;
    }
}

void display_memory_usage(long total, long free, long available) {
    long used = total - free;
    double used_percentage = ((double)used / (double)total) * 100;
    double available_percentage = ((double)available / (double)total) * 100;

    printf("\n=== Memory Usage Report ===\n");
    printf("Total Memory: %ld kB\n", total);
    printf("Free Memory: %ld kB\n", free);
    printf("Used Memory: %ld kB (%.2f%%)\n", used, used_percentage);
    printf("Available Memory: %ld kB (%.2f%%)\n", available, available_percentage);
    printf("============================\n");
}

void monitor_memory_usage(int interval) {
    long total = 0, free = 0, available = 0;
    
    while(1) {
        FILE *fp = fopen(MEMORY_INFO_FILE, "r");
        if (!fp) {
            perror("Failed to open memory info file");
            return;
        }

        char line[MAX_LINE_LENGTH];
        while (fgets(line, sizeof(line), fp)) {
            parse_memory_info(line, &total, &free, &available);
        }
        fclose(fp);
        
        display_memory_usage(total, free, available);
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 5;

    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Interval must be a positive integer.\n");
            return EXIT_FAILURE;
        }
    }

    printf("Starting Memory Usage Monitor...\n");
    printf("Monitoring every %d seconds.\n", interval);
    monitor_memory_usage(interval);

    return EXIT_SUCCESS;
}