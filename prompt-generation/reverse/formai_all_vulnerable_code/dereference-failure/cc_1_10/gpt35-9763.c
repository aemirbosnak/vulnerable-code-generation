//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 256

int main() {
    long long total_mem, free_mem, used_mem;
    struct sysinfo mem_info;

    while (1) {
        if (sysinfo(&mem_info) != 0) {
            fprintf(stderr, "Error: Failed to obtain system memory usage\n");
            exit(EXIT_FAILURE);
        }

        total_mem = mem_info.totalram;
        total_mem *= mem_info.mem_unit;

        free_mem = mem_info.freeram;
        free_mem *= mem_info.mem_unit;

        used_mem = total_mem - free_mem;

        printf("Total Memory:   %lld kB\n", total_mem / 1024);
        printf("Used Memory:    %lld kB\n", used_mem / 1024);
        printf("Free Memory:    %lld kB\n", free_mem / 1024);

        FILE* fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            fprintf(stderr, "Error: Failed to open /proc/meminfo file\n");
            exit(EXIT_FAILURE);
        }

        char* line = (char*)malloc(BUFFER_SIZE * sizeof(char));
        char* token;
        int mem_available = 0;

        while (fgets(line, BUFFER_SIZE, fp) != NULL) {
            if (strstr(line, "MemAvailable") != NULL) {
                token = strtok(line, " ");
                token = strtok(NULL, " ");
                mem_available = atoi(token);
                break;
            }
        }

        printf("Available Memory: %d kB\n", mem_available);
        printf("--------------------------------------------------\n");

        fclose(fp);

        free(line);

        sleep(1); // wait for 1 second before checking again
    }

    return 0;
}