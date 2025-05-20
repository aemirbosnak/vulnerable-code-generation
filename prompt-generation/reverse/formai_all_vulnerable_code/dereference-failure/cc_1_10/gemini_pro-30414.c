//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the log file name
#define LOG_FILE "my.log"

// Define the maximum line length
#define MAX_LINE_LENGTH 1024

// Define the number of columns to parse
#define NUM_COLUMNS 5

// Define the column names
char *column_names[] = {
    "timestamp",
    "level",
    "component",
    "message",
    "stacktrace"
};

// Define the column types
enum column_type {
    COLUMN_TYPE_TIMESTAMP,
    COLUMN_TYPE_LEVEL,
    COLUMN_TYPE_COMPONENT,
    COLUMN_TYPE_MESSAGE,
    COLUMN_TYPE_STACKTRACE
};

// Define the column data types
typedef struct column_data {
    enum column_type type;
    char *value;
} column_data;

// Define the log line data type
typedef struct log_line {
    char *line;
    column_data columns[NUM_COLUMNS];
} log_line;

// Parse a log line and populate the column data
log_line *parse_log_line(char *line) {
    log_line *log_line = malloc(sizeof(log_line));
    log_line->line = line;

    // Split the line into columns using a delimiter
    char *columns[NUM_COLUMNS];
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        columns[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    // Populate the column data
    for (i = 0; i < NUM_COLUMNS; i++) {
        column_data *column = &log_line->columns[i];
        column->type = i;
        column->value = columns[i];
    }

    return log_line;
}

// Print the log line data
void print_log_line(log_line *log_line) {
    for (int i = 0; i < NUM_COLUMNS; i++) {
        column_data *column = &log_line->columns[i];
        printf("%s: %s\n", column_names[i], column->value);
    }
    printf("\n");
}

// Free the log line data
void free_log_line(log_line *log_line) {
    free(log_line->line);
    free(log_line);
}

// Main function
int main() {
    // Open the log file
    FILE *log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        return EXIT_FAILURE;
    }

    // Parse the log file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        log_line *log_line = parse_log_line(line);
        print_log_line(log_line);
        free_log_line(log_line);
    }

    // Close the log file
    fclose(log_file);

    return EXIT_SUCCESS;
}