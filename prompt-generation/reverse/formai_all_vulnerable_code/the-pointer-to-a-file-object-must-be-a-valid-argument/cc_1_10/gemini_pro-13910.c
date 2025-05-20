//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Define the maximum size of a log line
#define MAX_LOG_LINE_SIZE 1024

// Define the number of log lines to read from the file
#define NUM_LOG_LINES 10

// Define the path to the log file
#define LOG_FILE_PATH "/var/log/syslog"

// Declare the main function
int main(void) {
    // Open the log file for reading
    int fd = open(LOG_FILE_PATH, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the log file line by line
    char line[MAX_LOG_LINE_SIZE];
    int line_count = 0;
    while (fgets(line, MAX_LOG_LINE_SIZE, fd)) {
        // Skip empty lines
        if (strlen(line) == 0) {
            continue;
        }

        // Parse the log line
        struct tm *tm;
        char *date_str, *time_str, *level_str, *message;
        if (sscanf(line, "%s %s %s %[^\n]", date_str, time_str, level_str, message) != 4) {
            fprintf(stderr, "Error parsing log line: %s", line);
            continue;
        }

        // Convert the date and time strings to a time_t value
        if ((tm = strptime(date_str, "%b %d %H:%M:%S", NULL)) == NULL) {
            fprintf(stderr, "Error converting date string: %s", date_str);
            continue;
        }
        time_t timestamp = mktime(tm);

        // Print the log line to the console
        printf("%s %s %s %s\n", date_str, time_str, level_str, message);

        // Increment the line count
        line_count++;

        // Check if we have read the desired number of log lines
        if (line_count >= NUM_LOG_LINES) {
            break;
        }
    }

    // Close the log file
    close(fd);

    return EXIT_SUCCESS;
}