//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a few constants
#define MAX_LOG_LINE_LENGTH 1024
#define MAX_LOG_LINES 1000

// Define a struct to store a log line
typedef struct {
    char *line;
    int length;
} LogLine;

// Define a function to read a log line from a file
LogLine read_log_line(FILE *file) {
    LogLine log_line;

    // Allocate memory for the log line
    log_line.line = malloc(MAX_LOG_LINE_LENGTH);
    if (log_line.line == NULL) {
        perror("malloc");
        exit(1);
    }

    // Read the log line from the file
    if (fgets(log_line.line, MAX_LOG_LINE_LENGTH, file) == NULL) {
        log_line.length = 0;
    } else {
        // Remove the newline character from the log line
        log_line.length = strlen(log_line.line);
        if (log_line.line[log_line.length - 1] == '\n') {
            log_line.line[log_line.length - 1] = '\0';
            log_line.length--;
        }
    }

    return log_line;
}

// Define a function to parse a log line
void parse_log_line(LogLine log_line) {
    // Split the log line into fields
    char *fields[10];
    int num_fields = 0;
    char *field = strtok(log_line.line, " ");
    while (field != NULL) {
        fields[num_fields++] = field;
        field = strtok(NULL, " ");
    }

    // Parse the fields
    char *timestamp = fields[0];
    char *level = fields[1];
    char *component = fields[2];
    char *message = fields[3];

    // Print the parsed fields
    printf("Timestamp: %s\n", timestamp);
    printf("Level: %s\n", level);
    printf("Component: %s\n", component);
    printf("Message: %s\n\n", message);
}

// Define a function to analyze a log file
void analyze_log_file(char *filename) {
    // Open the log file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Read the log lines from the file
    LogLine log_lines[MAX_LOG_LINES];
    int num_log_lines = 0;
    while (1) {
        LogLine log_line = read_log_line(file);
        if (log_line.length == 0) {
            break;
        }
        log_lines[num_log_lines++] = log_line;
    }

    // Close the log file
    fclose(file);

    // Parse the log lines
    for (int i = 0; i < num_log_lines; i++) {
        parse_log_line(log_lines[i]);
    }

    // Free the memory allocated for the log lines
    for (int i = 0; i < num_log_lines; i++) {
        free(log_lines[i].line);
    }
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check the command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
        exit(1);
    }

    // Analyze the log file
    analyze_log_file(argv[1]);

    return 0;
}