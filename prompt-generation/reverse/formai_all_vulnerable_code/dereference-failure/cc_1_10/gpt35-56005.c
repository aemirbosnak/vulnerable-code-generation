//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LOGS 1000000 // Maximum number of log entries
#define MAX_LINE_LENGTH 1024 // Maximum length of a log line

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *logs[MAX_LOGS];
    int log_count = 0;
    int error_count = 0;
    int warning_count = 0;
    int info_count = 0;
    int debug_count = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s log_file_path\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        exit(1);
    }

    // Read log file and store log entries in an array
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        logs[log_count] = (char *) malloc(strlen(line) + 1);
        strcpy(logs[log_count], line);
        log_count++;
    }
    fclose(fp);

    // Count log entries by level (error, warning, info, debug)
    for (i = 0; i < log_count; i++) {
        if (strstr(logs[i], "ERROR")) {
            error_count++;
        } else if (strstr(logs[i], "WARNING")) {
            warning_count++;
        } else if (strstr(logs[i], "INFO")) {
            info_count++;
        } else if (strstr(logs[i], "DEBUG")) {
            debug_count++;
        }
    }

    // Print log analysis summary
    printf("Log Analysis Summary\n");
    printf("--------------------\n");
    printf("Total log entries: %d\n", log_count);
    printf("Error count: %d\n", error_count);
    printf("Warning count: %d\n", warning_count);
    printf("Info count: %d\n", info_count);
    printf("Debug count: %d\n", debug_count);

    // Free memory used by log entries
    for (i = 0; i < log_count; i++) {
        free(logs[i]);
    }

    return 0;
}