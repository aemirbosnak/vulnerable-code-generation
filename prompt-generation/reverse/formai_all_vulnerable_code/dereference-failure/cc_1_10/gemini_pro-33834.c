//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a log line
#define MAX_LOG_LINE_LENGTH 1024

// Define the maximum number of log lines to store in memory
#define MAX_LOG_LINES 1000

// Define the structure of a log line
typedef struct {
    char *line;
    size_t length;
} log_line;

// Define the structure of a log file
typedef struct {
    FILE *file;
    log_line *lines;
    size_t num_lines;
} log_file;

// Create a new log file
log_file *log_file_new(const char *filename) {
    log_file *log = malloc(sizeof(log_file));
    if (log == NULL) {
        return NULL;
    }

    log->file = fopen(filename, "r");
    if (log->file == NULL) {
        free(log);
        return NULL;
    }

    log->lines = NULL;
    log->num_lines = 0;

    return log;
}

// Free a log file
void log_file_free(log_file *log) {
    if (log == NULL) {
        return;
    }

    if (log->lines != NULL) {
        for (size_t i = 0; i < log->num_lines; i++) {
            free(log->lines[i].line);
        }
        free(log->lines);
    }

    if (log->file != NULL) {
        fclose(log->file);
    }

    free(log);
}

// Read a log file into memory
int log_file_read(log_file *log) {
    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, MAX_LOG_LINE_LENGTH, log->file) != NULL) {
        size_t length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            length--;
            line[length] = '\0';
        }

        log_line *new_line = malloc(sizeof(log_line));
        if (new_line == NULL) {
            return -1;
        }

        new_line->line = malloc(length + 1);
        if (new_line->line == NULL) {
            free(new_line);
            return -1;
        }

        strcpy(new_line->line, line);
        new_line->length = length;

        if (log->num_lines >= MAX_LOG_LINES) {
            log->lines = realloc(log->lines, (log->num_lines + 1) * sizeof(log_line));
            if (log->lines == NULL) {
                free(new_line->line);
                free(new_line);
                return -1;
            }
        }

        log->lines[log->num_lines++] = *new_line;
        free(new_line);
    }

    return 0;
}

// Print a log file to the console
void log_file_print(log_file *log) {
    for (size_t i = 0; i < log->num_lines; i++) {
        printf("%s\n", log->lines[i].line);
    }
}

// Search a log file for a specific string
int log_file_search(log_file *log, const char *substring) {
    for (size_t i = 0; i < log->num_lines; i++) {
        if (strstr(log->lines[i].line, substring) != NULL) {
            return i;
        }
    }

    return -1;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        return 1;
    }

    log_file *log = log_file_new(argv[1]);
    if (log == NULL) {
        printf("Error opening log file: %s\n", argv[1]);
        return 1;
    }

    if (log_file_read(log) != 0) {
        printf("Error reading log file: %s\n", argv[1]);
        log_file_free(log);
        return 1;
    }

    // Print the log file to the console
    log_file_print(log);

    // Search the log file for a specific string
    int index = log_file_search(log, "ERROR");
    if (index >= 0) {
        printf("Found error at line %d: %s\n", index + 1, log->lines[index].line);
    } else {
        printf("No errors found in log file.\n");
    }

    // Free the log file
    log_file_free(log);

    return 0;
}