//FormAI DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables
    char log[500], *token;
    int line_count = 0, error_count = 0, warning_count = 0;

    // Open the log file
    FILE *file = fopen("sample_log.txt", "r");

    // Loop through each line in the log file
    while (fgets(log, 500, file)) {
        // Increment the line count
        line_count++;

        // Check for errors
        if (strstr(log, "ERROR")) {
            error_count++;
            printf("Error on line %d: %s\n", line_count, log);
        }

        // Check for warnings
        if (strstr(log, "WARNING")) {
            warning_count++;
            printf("Warning on line %d: %s\n", line_count, log);
        }
        
        // Tokenize the log line and print out the first three elements
        char *token;
        int count = 0;
        token = strtok(log, " ");
        while (token != NULL && count < 3) {
            printf("%s ", token);
            token = strtok(NULL, " ");
            count++;
        }
        printf("\n");
    }

    // Print out the final results
    printf("Total number of lines: %d\n", line_count);
    printf("Number of errors: %d\n", error_count);
    printf("Number of warnings: %d\n", warning_count);

    // Close the file
    fclose(file);

    return 0;
}