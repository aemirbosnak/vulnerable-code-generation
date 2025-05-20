//FormAI DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line;
    size_t len = MAX_LINE_LENGTH;
    ssize_t read;
    int line_num = 0, info_count = 0, error_count = 0, debug_count = 0;

    // Open the log file specified as command line argument
    if (argc != 2) {
        printf("Error: Invalid number of arguments.\n");
        printf("Usage: %s [log_file_path]\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "r"); // Open the file for reading
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read each line in the file and analyze the log level
    while ((read = getline(&line, &len, fp)) != -1) {
        line_num++;
        if (strstr(line, "INFO") != NULL) {
            info_count++;
        } else if (strstr(line, "ERROR") != NULL) {
            error_count++;
        } else if (strstr(line, "DEBUG") != NULL) {
            debug_count++;
        } else {
            printf("Warning: Unknown log level at line %d\n", line_num);
        }
    }

    // Print the results of the analysis
    printf("Log file analysis results:\n");
    printf("Total lines: %d\n", line_num);
    printf("INFO count: %d\n", info_count);
    printf("ERROR count: %d\n", error_count);
    printf("DEBUG count: %d\n", debug_count);

    // Cleanup
    fclose(fp);
    if (line) {
        free(line);
    }
    return 0;
}