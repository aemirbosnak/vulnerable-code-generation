//FormAI DATASET v1.0 Category: Log analysis ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    // Opening the log file for processing
    FILE *log_file = fopen("example.log", "r");

    // Check if the file was opened successfully
    if (log_file == NULL) {
        printf("Failed to open the log file!\n");
        return 1;
    }

    // Initializing variables to store data from each line
    char line[100];
    char timestamp[25];
    char action[15];
    char message[50];

    // Initializing variables to store data for the analysis
    int error_count = 0;
    int warn_count = 0;
    int info_count = 0;
    int total_count = 0;

    // Reading each line from the log file
    while (fgets(line, sizeof(line), log_file)) {

        // Getting the timestamp from the line
        char *tok = strtok(line, " ");
        strcpy(timestamp, tok);

        // Getting the action from the line
        tok = strtok(NULL, " ");
        strcpy(action, tok);

        // Getting the message from the line
        tok = strtok(NULL, "\n");
        strcpy(message, tok);

        // Adding to the relevant counters based on the action
        if (strcmp(action, "ERROR") == 0) {
            error_count++;
        } else if (strcmp(action, "WARN") == 0) {
            warn_count++;
        } else if (strcmp(action, "INFO") == 0) {
            info_count++;
        }

        // Incrementing the total counter
        total_count++;
    }

    // Closing the log file
    fclose(log_file);

    // Printing the analysis results
    printf("Total lines processed: %d\n", total_count);
    printf("Number of errors: %d\n", error_count);
    printf("Number of warnings: %d\n", warn_count);
    printf("Number of information messages: %d\n", info_count);

    return 0;
}