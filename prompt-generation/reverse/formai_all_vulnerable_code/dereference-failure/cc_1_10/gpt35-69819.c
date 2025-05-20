//FormAI DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Open the log file
    FILE *log_file = fopen("server_logs.txt", "r");

    // Check if file exists
    if (log_file == NULL)
    {
        printf("Error: Failed to open the log file. Make sure the file exists.\n");
        return 1;
    }

    // Initialize variables
    int total_requests = 0;
    int successful_requests = 0;
    int failed_requests = 0;
    int average_response_time = 0;

    char buffer[200];
    char *request_type;
    int response_time;

    // Read each line of the log file
    while (fgets(buffer, 200, log_file) != NULL)
    {
        total_requests++;

        // Get the request type and response time from the log entry
        request_type = strtok(buffer, " ");
        response_time = atoi(strtok(NULL, " "));

        // Check if request was successful or failed
        if (response_time < 400)
        {
            successful_requests++;
        }
        else
        {
            failed_requests++;
        }

        // Update the average response time
        average_response_time += response_time;
    }

    // Calculate the average response time
    if (total_requests > 0)
    {
        average_response_time /= total_requests;
    }

    // Close the log file
    fclose(log_file);

    // Print the analysis results
    printf("Total Requests: %d\n", total_requests);
    printf("Successful Requests: %d\n", successful_requests);
    printf("Failed Requests: %d\n", failed_requests);
    printf("Average Response Time: %dms\n", average_response_time);

    return 0;
}