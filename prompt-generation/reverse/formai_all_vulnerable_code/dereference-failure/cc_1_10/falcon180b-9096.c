//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MEMORY_FILE "/proc/meminfo"
#define BUFFER_SIZE 1024

void print_memory_usage() {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(MEMORY_FILE, "r");

    if (file == NULL) {
        printf("Error: Failed to open %s\n", MEMORY_FILE);
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    fread(buffer, 1, BUFFER_SIZE, file);
    fclose(file);

    char *mem_total = strtok(buffer, "\n");
    char *mem_free = strtok(NULL, "\n");
    char *buffers = strtok(NULL, "\n");
    char *cache = strtok(NULL, "\n");

    printf("Total memory: %s\n", mem_total);
    printf("Free memory: %s\n", mem_free);
    printf("Buffers: %s\n", buffers);
    printf("Cache: %s\n", cache);
}

void monitor_memory_usage(int interval_seconds) {
    while (1) {
        print_memory_usage();
        sleep(interval_seconds);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <interval_seconds>\n", argv[0]);
        return 1;
    }

    int interval_seconds = atoi(argv[1]);
    if (interval_seconds <= 0) {
        printf("Error: Invalid interval_seconds\n");
        return 1;
    }

    monitor_memory_usage(interval_seconds);

    return 0;
}