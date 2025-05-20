//FormAI DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Make sure the user provided a file name for analysis
    if (argc != 2) {
        printf("Usage: ./log_analysis <log_file.txt>\n");
        return 1;
    }

    // Open the log file for reading
    FILE *log_file = fopen(argv[1], "r");
    if (!log_file) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    // Prepare variables to store relevant data
    int total_entries = 0;
    int unique_entries = 0;
    int error_count = 0;
    int warn_count = 0;

    char buffer[BUFFER_SIZE];
    char *ip_address;
    char *entry_type;
    char *entry_message;

    // Read the log file line by line
    while (fgets(buffer, BUFFER_SIZE, log_file)) {
        total_entries++;

        // Split the line into its components (IP address, entry type, and entry message)
        ip_address = strtok(buffer, " ");
        entry_type = strtok(NULL, " ");
        entry_message = strtok(NULL, "\n");

        // Count unique IP addresses
        if (strcmp(ip_address, "127.0.0.1") != 0) {
            unique_entries++;
        }

        // Count error and warning entries
        if (strcmp(entry_type, "ERROR") == 0) {
            error_count++;
        } else if (strcmp(entry_type, "WARN") == 0) {
            warn_count++;
        }
    }

    // Close the log file
    fclose(log_file);

    // Print the analysis results
    printf("Total entries: %d\n", total_entries);
    printf("Unique entries: %d\n", unique_entries);
    printf("Error count: %d\n", error_count);
    printf("Warning count: %d\n", warn_count);

    return 0;
}