//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

// Define the maximum command-line length
#define CMD_MAX_LENGTH 100

// Define the maximum number of lines to read from /proc/meminfo
#define MAX_LINES 4

// Define the maximum length of each line in /proc/meminfo
#define LINE_MAX_LENGTH 50

int main(void) {
    // Define a string to hold the command to execute
    char command[CMD_MAX_LENGTH];

    // Define an array to hold the lines from /proc/meminfo
    char lines[MAX_LINES][LINE_MAX_LENGTH];

    // Define variables to hold the memory information
    long long total = 0, free = 0, used = 0;

    // Build the command to execute
    snprintf(command, CMD_MAX_LENGTH, "cat /proc/meminfo | head -n %d", MAX_LINES);

    // Execute the command
    FILE* procMemInfo = popen(command, "r");

    // Read the output of the command into the lines array
    for (int i = 0; i < MAX_LINES && fgets(lines[i], LINE_MAX_LENGTH, procMemInfo); i++);

    // Close the file pointer to /proc/meminfo
    pclose(procMemInfo);

    // Parse the memory information from the lines array
    for (int i = 0; i < MAX_LINES; i++) {
        char* value = strchr(lines[i], ':');
        if (value) {
            value++;
            while (*value && isspace(*value)) value++;
            if (strstr(lines[i], "MemTotal")) total = atoll(value) * 1024;
            else if (strstr(lines[i], "MemFree")) free = atoll(value) * 1024;
            else if (strstr(lines[i], "Buffers") || strstr(lines[i], "Cached")) used += atoll(value) * 1024;
        }
    }

    // Calculate the used memory
    used = total - free - used;

    // Print the memory usage information
    printf("RAM Usage\n");
    printf("  Total: %lld bytes\n", total);
    printf("  Used: %lld bytes\n", used);
    printf("  Free: %lld bytes\n", free);

    return 0;
}