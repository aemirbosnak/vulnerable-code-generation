//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Custom data structure to represent a log event
typedef struct {
    char *timestamp;
    char *message;
    char *level;
} LogEvent;

// Function to parse a log line and populate the LogEvent structure
LogEvent parse_log_line(char *line) {
    LogEvent event;

    // Parse the timestamp
    event.timestamp = strtok(line, " ");

    // Parse the message
    event.message = strtok(NULL, "\n");

    // Parse the level
    event.level = strtok(NULL, ": ");

    return event;
}

// Function to print the LogEvent structure
void print_log_event(LogEvent event) {
    printf("Timestamp: %s\n", event.timestamp);
    printf("Message: %s\n", event.message);
    printf("Level: %s\n\n", event.level);
}

// Function to analyze the log file and print interesting information
void analyze_log_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening log file: %s\n", filename);
        return;
    }

    // Initialize the counters for different levels
    int info_count = 0;
    int warning_count = 0;
    int error_count = 0;

    // Initialize the timestamp for the latest error
    char *latest_error_timestamp = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        LogEvent event = parse_log_line(line);

        // Increment the counter for the corresponding level
        if (strcmp(event.level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(event.level, "WARNING") == 0) {
            warning_count++;
        } else if (strcmp(event.level, "ERROR") == 0) {
            error_count++;

            // Update the timestamp for the latest error
            latest_error_timestamp = event.timestamp;
        }

        // Print the log event
        // print_log_event(event);
    }

    fclose(file);

    // Print the summary of the log analysis
    printf("Log Analysis Summary:\n");
    printf("Number of INFO messages: %d\n", info_count);
    printf("Number of WARNING messages: %d\n", warning_count);
    printf("Number of ERROR messages: %d\n", error_count);
    printf("Timestamp of the latest ERROR message: %s\n", latest_error_timestamp);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    analyze_log_file(argv[1]);

    return 0;
}