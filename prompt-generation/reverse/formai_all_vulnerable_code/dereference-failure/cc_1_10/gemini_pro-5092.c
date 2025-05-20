//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a log line
#define MAX_LOG_LINE_LENGTH 1024

// Define the maximum number of log lines to store in memory
#define MAX_LOG_LINES 10000

// Define the structure of a log line
typedef struct log_line {
    time_t timestamp;
    char *message;
} log_line;

// Define the structure of a log buffer
typedef struct log_buffer {
    log_line *lines;
    int num_lines;
} log_buffer;

// Create a new log buffer
log_buffer *log_buffer_new() {
    log_buffer *buffer = malloc(sizeof(log_buffer));
    if (buffer == NULL) {
        return NULL;
    }

    buffer->lines = malloc(sizeof(log_line) * MAX_LOG_LINES);
    if (buffer->lines == NULL) {
        free(buffer);
        return NULL;
    }

    buffer->num_lines = 0;

    return buffer;
}

// Free a log buffer
void log_buffer_free(log_buffer *buffer) {
    if (buffer == NULL) {
        return;
    }

    if (buffer->lines != NULL) {
        free(buffer->lines);
    }

    free(buffer);
}

// Add a log line to a log buffer
int log_buffer_add_line(log_buffer *buffer, log_line *line) {
    if (buffer == NULL || line == NULL) {
        return -1;
    }

    if (buffer->num_lines >= MAX_LOG_LINES) {
        return -1;
    }

    buffer->lines[buffer->num_lines] = *line;
    buffer->num_lines++;

    return 0;
}

// Get a log line from a log buffer
log_line *log_buffer_get_line(log_buffer *buffer, int index) {
    if (buffer == NULL || index < 0 || index >= buffer->num_lines) {
        return NULL;
    }

    return &buffer->lines[index];
}

// Read log lines from a file
int log_buffer_read_file(log_buffer *buffer, const char *filename) {
    if (buffer == NULL || filename == NULL) {
        return -1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        log_line line_struct;
        line_struct.timestamp = time(NULL);
        line_struct.message = strdup(line);

        if (line_struct.message == NULL) {
            fclose(file);
            return -1;
        }

        if (log_buffer_add_line(buffer, &line_struct) != 0) {
            fclose(file);
            return -1;
        }
    }

    fclose(file);

    return 0;
}

// Print a log buffer to stdout
void log_buffer_print(log_buffer *buffer) {
    if (buffer == NULL) {
        return;
    }

    for (int i = 0; i < buffer->num_lines; i++) {
        log_line *line = log_buffer_get_line(buffer, i);
        if (line == NULL) {
            continue;
        }

        printf("%s %s", ctime(&line->timestamp), line->message);
    }
}

// Search a log buffer for a keyword
int log_buffer_search(log_buffer *buffer, const char *keyword) {
    if (buffer == NULL || keyword == NULL) {
        return -1;
    }

    for (int i = 0; i < buffer->num_lines; i++) {
        log_line *line = log_buffer_get_line(buffer, i);
        if (line == NULL) {
            continue;
        }

        if (strstr(line->message, keyword) != NULL) {
            return i;
        }
    }

    return -1;
}

// Main function
int main() {
    // Create a new log buffer
    log_buffer *buffer = log_buffer_new();
    if (buffer == NULL) {
        return EXIT_FAILURE;
    }

    // Read log lines from a file
    if (log_buffer_read_file(buffer, "log.txt") != 0) {
        log_buffer_free(buffer);
        return EXIT_FAILURE;
    }

    // Print the log buffer to stdout
    log_buffer_print(buffer);

    // Search the log buffer for a keyword
    int result = log_buffer_search(buffer, "error");
    if (result == -1) {
        printf("Keyword not found\n");
    } else {
        printf("Keyword found at index %d\n", result);
    }

    // Free the log buffer
    log_buffer_free(buffer);

    return EXIT_SUCCESS;
}