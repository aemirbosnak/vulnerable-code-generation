//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void read_memory_info() {
    FILE *meminfo_file;
    char buffer[BUFFER_SIZE];

    // Open the /proc/meminfo file to read memory details
    meminfo_file = fopen("/proc/meminfo", "r");
    if (meminfo_file == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    printf("Memory Information:\n");
    printf("---------------------------\n");

    // Read and display relevant memory information
    while (fgets(buffer, BUFFER_SIZE, meminfo_file) != NULL) {
        if (strstr(buffer, "MemTotal:") || strstr(buffer, "MemFree:") ||
            strstr(buffer, "Buffers:") || strstr(buffer, "Cached:") ||
            strstr(buffer, "SwapTotal:") || strstr(buffer, "SwapFree:")) {
            printf("%s", buffer);
        }
    }

    // Close the file after reading
    fclose(meminfo_file);
}

void print_usage() {
    printf("Usage: ram_monitor [options]\n");
    printf("Options:\n");
    printf("  -h, --help       Show help message\n");
    printf("  -t, --track      Continuously track RAM usage\n");
    printf("  -i, --interval   Set the interval in seconds for tracking (default is 5 seconds)\n");
}

int main(int argc, char *argv[]) {
    int track = 0;
    int interval = 5;

    // Process command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage();
            return 0;
        } else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--track") == 0) {
            track = 1;
        } else if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--interval") == 0) {
            if (i + 1 < argc) {
                interval = atoi(argv[++i]);
            } else {
                printf("Error: No interval specified\n");
                return 1;
            }
        }
    }

    // Monitor memory usage based on user's command
    while (1) {
        read_memory_info();
        if (!track) {
            break;
        }
        sleep(interval);
        printf("\nRefreshing memory information every %d seconds...\n", interval);
    }

    return 0;
}