//FormAI DATASET v1.0 Category: Log analysis ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *logfile = argv[1];
    char *metric = argv[2];
    char *value = argv[3];

    // Open the specified log file for reading
    FILE *log = fopen(logfile, "r");

    if (!log) {
        printf("Unable to read log file: %s\n", logfile);
        exit(1);
    }

    int total_count = 0;
    int relevant_count = 0;

    // Loop through each line of the log and count both the total number of entries and 
    // the number of entries that contain the relevant metric and value
    char line[1024];
    while (fgets(line, 1024, log)) {

        total_count++;

        // Split the line on whitespace to separate out the various log fields
        char *token;
        char *tokens[16];
        int n = 0;

        // Parse the line into individual tokens
        token = strtok(line, " ");
        while (token != NULL) {
            tokens[n++] = token;
            token = strtok(NULL, " ");
        }

        // Check if the current line contains the relevant metric and value
        if (strcmp(metric, tokens[2]) == 0 && strcmp(value, tokens[3]) == 0) {
            relevant_count++;
        }

    }

    // Print out the results
    printf("Total log entries: %d\n", total_count);
    printf("Entries with %s = %s: %d\n", metric, value, relevant_count);

    fclose(log);

    return 0;
}