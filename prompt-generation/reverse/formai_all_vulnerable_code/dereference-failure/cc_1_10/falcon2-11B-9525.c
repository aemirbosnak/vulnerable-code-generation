//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char *status = NULL;
    int status_len = 0;

    // Open the /proc/self/status file for reading
    FILE *status_fp = fopen("/proc/self/status", "r");
    if (status_fp == NULL) {
        perror("Error opening /proc/self/status");
        exit(EXIT_FAILURE);
    }

    // Read the entire file into a buffer
    status = (char*)malloc(sizeof(char) * 1024);
    status_len = fread(status, sizeof(char), 1024, status_fp);
    fclose(status_fp);

    // Check for a valid buffer size
    if (status_len == -1) {
        perror("Error reading /proc/self/status");
        exit(EXIT_FAILURE);
    }

    // Find the line containing the percentage of memory currently being used
    char *mem_usage_line = strstr(status, "VmRSS:");
    if (mem_usage_line == NULL) {
        fprintf(stderr, "Unable to find VmRSS: line in /proc/self/status\n");
        exit(EXIT_FAILURE);
    }
    mem_usage_line += 7; // Skip the "VmRSS: " prefix

    // Convert the memory usage value to an integer
    char *endptr;
    int mem_usage = strtol(mem_usage_line, &endptr, 10);
    if (*endptr!= '\0') {
        fprintf(stderr, "Error parsing memory usage from /proc/self/status\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the percentage of memory currently being used
    float mem_usage_pct = (float)mem_usage / 1024.0 * 100.0;
    printf("Memory usage: %.2f%%\n", mem_usage_pct);

    // Free the allocated buffer
    free(status);

    return 0;
}