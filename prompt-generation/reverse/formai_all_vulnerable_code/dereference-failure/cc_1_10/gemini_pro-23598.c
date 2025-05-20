//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// RAM usage monitor
// by your friendly neighborhood RAM monitor

int main() {

    // Initialize some variables
    long int total_ram, available_ram, free_ram, used_ram, buffer_ram, cached_ram;
    char *filename = "/proc/meminfo";
    FILE *file = fopen(filename, "r");

    // Check if the file exists
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Read the file
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Convert the value to a long int
        long int value_int = atol(value);

        // Store the value in the appropriate variable
        if (strcmp(key, "MemTotal") == 0) {
            total_ram = value_int;
        } else if (strcmp(key, "MemAvailable") == 0) {
            available_ram = value_int;
        } else if (strcmp(key, "MemFree") == 0) {
            free_ram = value_int;
        } else if (strcmp(key, "MemUsed") == 0) {
            used_ram = value_int;
        } else if (strcmp(key, "Buffers") == 0) {
            buffer_ram = value_int;
        } else if (strcmp(key, "Cached") == 0) {
            cached_ram = value_int;
        }
    }

    // Calculate some additional values
    long int total_used_ram = used_ram + buffer_ram + cached_ram;
    long int total_free_ram = free_ram + available_ram;

    // Print the results
    printf("Total RAM: %ld kB\n", total_ram);
    printf("Available RAM: %ld kB\n", available_ram);
    printf("Free RAM: %ld kB\n", free_ram);
    printf("Used RAM: %ld kB\n", total_used_ram);
    printf("Buffers: %ld kB\n", buffer_ram);
    printf("Cached: %ld kB\n", cached_ram);
    printf("Total free RAM: %ld kB\n", total_free_ram);

    // Close the file
    fclose(file);

    // Return success
    return 0;
}