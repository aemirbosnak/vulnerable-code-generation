//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LEN 1024
#define MAX_LOG_SIZE 100000

int main(void) {
    // Open the log file
    FILE *log_file = fopen("retro_log.txt", "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    // Check the log file size
    long log_size = ftell(log_file);
    if (log_size > MAX_LOG_SIZE) {
        printf("Log file is too large! Max size is %ld bytes\n", MAX_LOG_SIZE);
        return 1;
    }

    // Read the log file line by line
    char line[MAX_LINE_LEN];
    int line_num = 0;
    while (fgets(line, MAX_LINE_LEN, log_file) != NULL) {
        // Increment the line number
        line_num++;

        // Check for interesting lines
        if (strstr(line, "ERROR") != NULL) {
            printf("Error found at line %d: %s\n", line_num, line);
        } else if (strstr(line, "WARNING") != NULL) {
            printf("Warning found at line %d: %s\n", line_num, line);
        } else if (strstr(line, "INFO") != NULL) {
            printf("Info found at line %d: %s\n", line_num, line);
        }
    }

    // Close the log file
    fclose(log_file);

    // Print some fun facts about the log file
    printf("Log file contained %ld lines\n", line_num);
    printf("Longest line was %d characters long\n", strcspn(line, "\n"));
    printf("Average line length was %d characters\n", (line_num > 0) ? (int)((double)strlen(line) / line_num) : 0);

    return 0;
}