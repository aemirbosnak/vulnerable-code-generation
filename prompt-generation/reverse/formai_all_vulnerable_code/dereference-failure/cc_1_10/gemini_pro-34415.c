//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a log line.
#define MAX_LINE_LENGTH 1024

// Define the number of fields in a log line.
#define NUM_FIELDS 5

// Define the format of a log line.
#define LOG_LINE_FORMAT "%s %s %s %s %s"

// Define the names of the fields in a log line.
#define FIELD_NAMES "timestamp", "level", "logger", "message", "stack_trace"

// Define the types of the fields in a log line.
#define FIELD_TYPES "char *", "char *", "char *", "char *", "char *"

// Define the structure of a log line.
typedef struct log_line {
    char *timestamp;
    char *level;
    char *logger;
    char *message;
    char *stack_trace;
} log_line;

// Define the function to parse a log line.
log_line *parse_log_line(char *line) {
    // Allocate memory for the log line.
    log_line *log_line = malloc(sizeof(log_line));

    // Parse the log line.
    sscanf(line, LOG_LINE_FORMAT, log_line->timestamp, log_line->level, log_line->logger, log_line->message, log_line->stack_trace);

    // Return the log line.
    return log_line;
}

// Define the function to print a log line.
void print_log_line(log_line *log_line) {
    // Print the log line.
    printf("%s %s %s %s %s\n", log_line->timestamp, log_line->level, log_line->logger, log_line->message, log_line->stack_trace);
}

// Define the function to free a log line.
void free_log_line(log_line *log_line) {
    // Free the memory for the log line.
    free(log_line);
}

// Define the main function.
int main(int argc, char **argv) {
    // Check if the user has specified a log file.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the log file.
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Read the log file line by line.
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        // Parse the log line.
        log_line *log_line = parse_log_line(line);

        // Print the log line.
        print_log_line(log_line);

        // Free the log line.
        free_log_line(log_line);
    }

    // Close the log file.
    fclose(log_file);

    return EXIT_SUCCESS;
}