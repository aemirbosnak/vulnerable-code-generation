//FormAI DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check if the log file path was provided
    if (argc < 2)
    {
        printf("Please provide the path to the log file as argument!\n");
        return 1;
    }

    // Open the log file
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL)
    {
        perror("Error opening log file");
        return 1;
    }

    // Statistics variables
    int n_requests = 0;
    int n_successes = 0;
    int n_failures = 0;
    double total_time = 0.0;

    // Process log file line by line
    char line[1024];
    while (fgets(line, sizeof(line), log_file))
    {
        // Extract the request status and time
        char *status_str = strtok(line, " ");
        char *time_str = strtok(NULL, " ");

        // Update statistics based on request status
        if (strcmp(status_str, "SUCCESS") == 0)
        {
            n_successes++;
        }
        else if (strcmp(status_str, "FAILURE") == 0)
        {
            n_failures++;
        }
        else
        {
            printf("Unrecognized status: %s\n", status_str);
        }

        // Update statistics based on request time
        double time = atof(time_str);
        total_time += time;
        n_requests++;
    }

    // Calculate other statistics
    double avg_time = total_time / n_requests;
    double success_rate = (double)n_successes / (double)n_requests * 100;
    double failure_rate = (double)n_failures / (double)n_requests * 100;

    // Print statistics
    printf("Total requests: %d\n", n_requests);
    printf("Successes: %d (%.2f%%)\n", n_successes, success_rate);
    printf("Failures: %d (%.2f%%)\n", n_failures, failure_rate);
    printf("Average request time: %.2f seconds\n", avg_time);

    // Close log file
    fclose(log_file);

    return 0;
}