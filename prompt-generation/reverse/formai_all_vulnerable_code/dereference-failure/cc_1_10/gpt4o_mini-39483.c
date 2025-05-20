//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_CHARS 256
#define MEMORY_INFO_PATH "/proc/meminfo"

void parse_memory_info(char *line, long long *total, long long *free) {
    char key[MAX_CHARS];
    long long value;

    sscanf(line, "%s %lld", key, &value);
    if (strcmp(key, "MemTotal:") == 0) {
        *total = value;
    }
    if (strcmp(key, "MemFree:") == 0) {
        *free = value;
    }
}

void display_memory_usage(long long total, long long free) {
    long long used = total - free;
    float used_percentage = ((float)used / total) * 100;

    printf("\033[1;34mMemory Usage Report:\033[0m\n");
    printf("Total Memory: \033[1;32m%lld kB\033[0m\n", total);
    printf("Free Memory: \033[1;33m%lld kB\033[0m\n", free);
    printf("Used Memory: \033[1;31m%lld kB (%.2f%% used)\033[0m\n", used, used_percentage);
}

void monitor_memory_usage(int interval) {
    long long total = 0, free = 0;

    while (1) {
        FILE *meminfo = fopen(MEMORY_INFO_PATH, "r");
        if (!meminfo) {
            perror("Failed to open /proc/meminfo");
            exit(EXIT_FAILURE);
        }

        char line[MAX_CHARS];
        while (fgets(line, sizeof(line), meminfo)) {
            parse_memory_info(line, &total, &free);
        }
        fclose(meminfo);

        display_memory_usage(total, free);
        sleep(interval);
        printf("\n\033[1;37mMonitoring...\033[0m\n");
    }
}

int main(int argc, char *argv[]) {
    int interval = 5; // default to 5 seconds if no argument

    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "\033[1;31mError:\033[0m Interval must be a positive integer.\n");
            return EXIT_FAILURE;
        }
    }

    printf("\033[1;36mStarting Memory Usage Monitor with a \033[1;35m%d second\033[1;36m interval...\033[0m\n", interval);

    monitor_memory_usage(interval);

    return 0;
}