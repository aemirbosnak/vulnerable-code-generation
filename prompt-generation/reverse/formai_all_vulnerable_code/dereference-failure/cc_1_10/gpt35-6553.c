//FormAI DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./log_analysis <log_file>\n");
        return 1;
    }

    char *log_file_name = argv[1];
    FILE *log_file = fopen(log_file_name, "r");
    if (!log_file) {
        printf("Error opening log file: %s\n", log_file_name);
        return 1;
    }

    // Initialize log analysis variables
    int total_requests = 0;
    int successful_requests = 0;
    int failed_requests = 0;
    float average_response_time = 0;
    int slow_requests = 0;

    // Parse each line of the log file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        char *timestamp = strtok(line, " ");
        char *status_code_str = strtok(NULL, " ");
        char *response_time_str = strtok(NULL, " ");

        // Convert the response time to a float
        float response_time = atof(response_time_str);

        // Update the log analysis variables
        total_requests++;
        if (strcmp(status_code_str, "200") == 0) {
            successful_requests++;
            average_response_time += response_time;
            if (response_time > 1.0) { // Consider 1 second as the threshold for a slow request
                slow_requests++;
            }
        } else {
            failed_requests++;
        }
    }

    // Print out the log analysis results
    printf("Total requests: %d\n", total_requests);
    printf("Successful requests: %d\n", successful_requests);
    printf("Failed requests: %d\n", failed_requests);
    if (successful_requests > 0) {
        printf("Average response time: %.2fms\n", average_response_time / successful_requests);
        printf("Number of slow requests (response time > 1 second): %d\n", slow_requests);
    }

    // Close the log file
    fclose(log_file);

    return 0;
}