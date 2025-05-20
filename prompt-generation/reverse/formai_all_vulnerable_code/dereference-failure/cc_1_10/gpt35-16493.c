//FormAI DATASET v1.0 Category: Log analysis ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *log_file_path;

    // Check if log file path is provided as command line argument
    if (argc > 1) {
        log_file_path = argv[1];
    } else {
        printf("Please provide path to the log file as command line argument!\n");
        return 0;
    }

    // Open log file
    FILE *log_file = fopen(log_file_path, "r");

    if (!log_file) {
        printf("Error opening log file!\n");
        return 0;
    }

    // Define variables to store log analysis data
    int total_requests = 0;
    int successful_requests = 0;
    int failed_requests = 0;
    int total_bytes_sent = 0;

    // Read log file line by line
    char log_entry[500];
    char *method, *url, *status_code, *bytes_sent;

    while (fgets(log_entry, 500, log_file)) {

        // Parse log entry
        method = strtok(log_entry, " ");
        url = strtok(NULL, " ");
        strtok(NULL, " "); // Ignore HTTP version
        status_code = strtok(NULL, " ");
        bytes_sent = strtok(NULL, " ");

        // Count total requests
        total_requests++;

        // Check if request was successful
        if (strncmp(status_code, "2", 1) == 0) {
            successful_requests++;
            total_bytes_sent += atoi(bytes_sent);
        } else {
            failed_requests++;
        }
    }

    // Close log file
    fclose(log_file);

    // Print log analysis data
    printf("Total requests: %d\n", total_requests);
    printf("Successful requests: %d\n", successful_requests);
    printf("Failed requests: %d\n", failed_requests);
    printf("Total bytes sent in successful requests: %d\n", total_bytes_sent);

    return 0;
}