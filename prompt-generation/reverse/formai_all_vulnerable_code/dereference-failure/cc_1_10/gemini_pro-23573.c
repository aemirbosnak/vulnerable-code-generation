//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Declare our mighty steed, a pointer to a file
    FILE *fp;

    // Open the gates of /proc/meminfo, a tome of memory secrets
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        // Woe is me! The gates are barred!
        perror("Error opening /proc/meminfo");
        return EXIT_FAILURE;
    }

    // Let us delve into the tome and gather its wisdom
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into its components, like a knight parsing a royal decree
        char *key, *value;
        key = strtok(line, ":");
        value = strtok(NULL, ":");

        // Remove the trailing newline, a pesky squire
        value[strcspn(value, "\n")] = '\0';

        // Convert the value to a more manageable form
        long long num_value = atoll(value);

        // Now, let us forge a proclamation for each line
        if (strcmp(key, "MemTotal") == 0) {
            printf("Total memory: %lld MB\n", num_value / 1024 / 1024);
        } else if (strcmp(key, "MemFree") == 0) {
            printf("Free memory: %lld MB\n", num_value / 1024 / 1024);
        } else if (strcmp(key, "MemAvailable") == 0) {
            printf("Available memory: %lld MB\n", num_value / 1024 / 1024);
        } else if (strcmp(key, "Buffers") == 0) {
            printf("Buffers: %lld MB\n", num_value / 1024 / 1024);
        } else if (strcmp(key, "Cached") == 0) {
            printf("Cached: %lld MB\n", num_value / 1024 / 1024);
        }
    }

    // Close the tome, for our quest is complete
    fclose(fp);

    return EXIT_SUCCESS;
}