//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to get the log analysis
void getLogAnalysis(char* logFilePath) {
    // Open the log file
    FILE* file = fopen(logFilePath, "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return;
    }

    // Read the log file
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Process the log line
        int errorCode = atoi(strtok(line, " "));
        if (errorCode == 404) {
            printf("Error: Resource not found\n");
        } else if (errorCode == 500) {
            printf("Error: Internal server error\n");
        } else if (errorCode == 403) {
            printf("Error: Access denied\n");
        } else if (errorCode == 200) {
            printf("Success: Resource found\n");
        }
    }

    // Close the log file
    fclose(file);
}

// Function to write the log analysis to a file
void writeLogAnalysis(char* outputFilePath) {
    // Open the output file
    FILE* file = fopen(outputFilePath, "w");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return;
    }

    // Write the log analysis to the output file
    fprintf(file, "Log Analysis\n");
    fprintf(file, "-------------------------\n");
    fprintf(file, "Total errors: %d\n", getTotalErrors());
    fprintf(file, "Total successful requests: %d\n", getTotalSuccesses());
    fprintf(file, "-------------------------\n");

    // Close the output file
    fclose(file);
}

// Function to get the total number of errors in the log file
int getTotalErrors() {
    // Open the log file
    FILE* file = fopen("log.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 0;
    }

    // Count the number of errors
    int totalErrors = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int errorCode = atoi(strtok(line, " "));
        if (errorCode == 404 || errorCode == 500 || errorCode == 403) {
            totalErrors++;
        }
    }

    // Close the log file
    fclose(file);

    return totalErrors;
}

// Function to get the total number of successful requests in the log file
int getTotalSuccesses() {
    // Open the log file
    FILE* file = fopen("log.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 0;
    }

    // Count the number of successful requests
    int totalSuccesses = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int errorCode = atoi(strtok(line, " "));
        if (errorCode == 200) {
            totalSuccesses++;
        }
    }

    // Close the log file
    fclose(file);

    return totalSuccesses;
}

int main() {
    // Get the log file path from the command line argument
    char* logFilePath = getenv("LOG_FILE");
    if (logFilePath == NULL) {
        printf("Error: LOG_FILE environment variable not set\n");
        return 1;
    }

    // Get the output file path from the command line argument
    char* outputFilePath = getenv("OUTPUT_FILE");
    if (outputFilePath == NULL) {
        printf("Error: OUTPUT_FILE environment variable not set\n");
        return 1;
    }

    // Get the log analysis
    getLogAnalysis(logFilePath);

    // Write the log analysis to the output file
    writeLogAnalysis(outputFilePath);

    return 0;
}