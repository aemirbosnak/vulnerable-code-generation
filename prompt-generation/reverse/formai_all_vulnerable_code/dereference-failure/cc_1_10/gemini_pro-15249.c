//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a log line.
#define MAX_LOG_LINE_LENGTH 1024

// Define the maximum number of log lines to store in memory.
#define MAX_LOG_LINES 100

// Define the structure of a log line.
typedef struct {
    char *line;
    size_t length;
} log_line;

// Define the structure of a log.
typedef struct {
    log_line *lines;
    size_t size;
    size_t capacity;
} log;

// Create a new log.
log *log_new() {
    log *l = malloc(sizeof(log));
    l->lines = malloc(MAX_LOG_LINES * sizeof(log_line));
    l->size = 0;
    l->capacity = MAX_LOG_LINES;
    return l;
}

// Free the memory allocated for a log.
void log_free(log *l) {
    for (size_t i = 0; i < l->size; i++) {
        free(l->lines[i].line);
    }
    free(l->lines);
    free(l);
}

// Add a new line to a log.
void log_add_line(log *l, char *line) {
    if (l->size == l->capacity) {
        l->lines = realloc(l->lines, (l->capacity + MAX_LOG_LINES) * sizeof(log_line));
        l->capacity += MAX_LOG_LINES;
    }
    l->lines[l->size].line = strdup(line);
    l->lines[l->size].length = strlen(line);
    l->size++;
}

// Print a log to the console.
void log_print(log *l) {
    for (size_t i = 0; i < l->size; i++) {
        printf("%s", l->lines[i].line);
    }
}

// Parse a log line and extract the fields.
int log_parse_line(log_line *line, char *fields[]) {
    char *field = strtok(line->line, " ");
    int field_count = 0;
    while (field) {
        fields[field_count] = field;
        field_count++;
        field = strtok(NULL, " ");
    }
    return field_count;
}

// Find all log lines that match a given filter.
log *log_filter(log *l, char *filter) {
    log *filtered_log = log_new();
    for (size_t i = 0; i < l->size; i++) {
        char *fields[MAX_LOG_LINE_LENGTH];
        int field_count = log_parse_line(&l->lines[i], fields);
        for (int j = 0; j < field_count; j++) {
            if (strstr(fields[j], filter)) {
                log_add_line(filtered_log, l->lines[i].line);
                break;
            }
        }
    }
    return filtered_log;
}

// Count the number of occurrences of a given pattern in a log.
int log_count_pattern(log *l, char *pattern) {
    int count = 0;
    for (size_t i = 0; i < l->size; i++) {
        if (strstr(l->lines[i].line, pattern)) {
            count++;
        }
    }
    return count;
}

// Find the most common pattern in a log.
char *log_find_most_common_pattern(log *l) {
    char *most_common_pattern = NULL;
    int max_count = 0;
    for (size_t i = 0; i < l->size; i++) {
        char *pattern = strtok(l->lines[i].line, " ");
        while (pattern) {
            int count = log_count_pattern(l, pattern);
            if (count > max_count) {
                max_count = count;
                most_common_pattern = pattern;
            }
            pattern = strtok(NULL, " ");
        }
    }
    return most_common_pattern;
}

int main() {
    // Create a new log.
    log *l = log_new();

    // Add some lines to the log.
    log_add_line(l, "INFO: This is an information message.");
    log_add_line(l, "WARNING: This is a warning message.");
    log_add_line(l, "ERROR: This is an error message.");

    // Print the log to the console.
    log_print(l);

    // Parse a log line and extract the fields.
    char *fields[MAX_LOG_LINE_LENGTH];
    int field_count = log_parse_line(&l->lines[0], fields);

    // Find all log lines that match a given filter.
    log *filtered_log = log_filter(l, "ERROR");

    // Count the number of occurrences of a given pattern in a log.
    int count = log_count_pattern(l, "message");

    // Find the most common pattern in a log.
    char *most_common_pattern = log_find_most_common_pattern(l);

    // Free the memory allocated for the log.
    log_free(l);

    return 0;
}