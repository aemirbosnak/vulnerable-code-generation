//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <sys/sysinfo.h>

int main() {
    // Get the system's total physical memory.
    struct sysinfo info;
    sysinfo(&info);
    printf("Total physical memory: %zu MB\n", info.totalram / 1024 / 1024);
    printf("Free physical memory: %zu MB\n", info.freeram / 1024 / 1024);
    printf("Used physical memory: %zu MB\n", (info.totalram - info.freeram) / 1024 / 1024);

    // Allocate a buffer to store the memory usage data.
    size_t buf_size = 1024 * 1024;
    char *buf = malloc(buf_size);
    if (buf == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Open the "/proc/self/smaps" file to get the memory usage data for the current process.
    FILE *fp = fopen("/proc/self/smaps", "r");
    if (fp == NULL) {
        perror("fopen");
        free(buf);
        return EXIT_FAILURE;
    }

    // Read the memory usage data into the buffer.
    size_t bytes_read = fread(buf, 1, buf_size, fp);
    if (bytes_read == 0) {
        perror("fread");
        fclose(fp);
        free(buf);
        return EXIT_FAILURE;
    }

    // Close the "/proc/self/smaps" file.
    fclose(fp);

    // Parse the memory usage data.
    size_t total_rss = 0;
    size_t total_swap = 0;
    char *line = buf;
    while (line != NULL) {
        // Get the next line of the memory usage data.
        char *next_line = strchr(line, '\n');
        if (next_line != NULL) {
            *next_line = '\0';
        }

        // Parse the line of the memory usage data.
        char *key = strtok(line, ":");
        if (key != NULL) {
            char *value = strtok(NULL, ":");
            if (value != NULL) {
                // Get the total RSS memory usage.
                if (strcmp(key, "Rss") == 0) {
                    total_rss += strtoul(value, NULL, 10);
                }
                // Get the total swap memory usage.
                else if (strcmp(key, "Swap") == 0) {
                    total_swap += strtoul(value, NULL, 10);
                }
            }
        }

        // Get the next line of the memory usage data.
        line = next_line + 1;
    }

    // Free the buffer.
    free(buf);

    // Print the memory usage data.
    printf("Total RSS memory usage: %zu kB\n", total_rss / 1024);
    printf("Total swap memory usage: %zu kB\n", total_swap / 1024);

    return EXIT_SUCCESS;
}