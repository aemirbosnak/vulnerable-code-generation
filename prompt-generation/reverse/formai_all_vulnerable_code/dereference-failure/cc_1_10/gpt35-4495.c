//FormAI DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 80
#define MAX_LINES 100

int main(void) {
    FILE *log_file;
    char line[LINE_SIZE];
    char *lines[MAX_LINES];
    int line_count = 0;
    float total_time = 0.0;
    int success_count = 0;
    int warning_count = 0;
    int error_count = 0;
    
    // Open log file and read each line
    log_file = fopen("example_log_file.txt", "r");
    if (log_file == NULL) {
        printf("Failed to open log file.");
        exit(1);
    }
    while (fgets(line, LINE_SIZE, log_file) != NULL && line_count < MAX_LINES) {
        // Store each line in an array
        lines[line_count] = (char*) malloc(sizeof(char) * (strlen(line) + 1));
        strcpy(lines[line_count], line);
        
        // Parse line for relevant info
        char status[10];
        float time;
        sscanf(line, "%s %f", status, &time);
        
        // Update counters based on status
        if (strcmp(status, "SUCCESS") == 0) {
            success_count++;
        } else if (strcmp(status, "WARNING") == 0) {
            warning_count++;
        } else if (strcmp(status, "ERROR") == 0) {
            error_count++;
        }
        total_time += time;
        
        line_count++;
    }
    fclose(log_file);
    
    // Print analysis summary
    printf("Log file analysis summary:\n\n");
    printf("Total lines: %d\n", line_count);
    printf("Total time: %.2f\n", total_time);
    printf("Success count: %d\n", success_count);
    printf("Warning count: %d\n", warning_count);
    printf("Error count: %d\n", error_count);
    
    // Print each line in reverse order
    printf("\nReverse order of lines:\n");
    for (int i = line_count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
        free(lines[i]);
    }
    
    return 0;
}