//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char line[256];
    char* token;
    long int total_memory, free_memory, used_memory, cache_memory;
    FILE* file = fopen("/proc/meminfo", "r");

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, " ");
        if (!token) {
            continue;
        }
        if (strcmp(token, "MemTotal:") == 0) {
            token = strtok(NULL, " ");
            if (!token) {
                continue;
            }
            total_memory = (long int) atoi(token);
        }
        else if (strcmp(token, "MemFree:") == 0) {
            token = strtok(NULL, " ");
            if (!token) {
                continue;
            }
            free_memory = (long int) atoi(token);
        }
        else if (strcmp(token, "Cached:") == 0) {
            token = strtok(NULL, " ");
            if (!token) {
                continue;
            }
            cache_memory = (long int) atoi(token);
        }
    }

    used_memory = total_memory - (free_memory + cache_memory);
    float used_percentage = ((float) used_memory / (float) total_memory) * 100;

    printf("Total memory: %ld kB\n", total_memory);
    printf("Used memory: %ld kB\n", used_memory);
    printf("Free memory: %ld kB\n", free_memory);
    printf("Cache memory: %ld kB\n", cache_memory);
    printf("Used percentage: %.2f%%\n", used_percentage);

    fclose(file);
    return 0;
}