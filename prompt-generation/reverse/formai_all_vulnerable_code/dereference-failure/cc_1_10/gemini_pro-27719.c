//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a log line
#define MAX_LOG_LINE_SIZE 1024

// Define the maximum number of log lines to store in memory
#define MAX_LOG_LINES 1000

// Define the structure of a log line
typedef struct log_line {
    char *line;
    int line_number;
} log_line;

// Define the structure of a log file
typedef struct log_file {
    FILE *file;
    log_line *lines;
    int num_lines;
} log_file;

// Read a log file into memory
log_file *read_log_file(const char *filename) {
    // Open the log file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Create a new log file struct
    log_file *log_file = malloc(sizeof(log_file));
    if (log_file == NULL) {
        fclose(file);
        return NULL;
    }

    // Initialize the log file struct
    log_file->file = file;
    log_file->lines = NULL;
    log_file->num_lines = 0;

    // Read the log file line by line
    char line[MAX_LOG_LINE_SIZE];
    while (fgets(line, MAX_LOG_LINE_SIZE, file) != NULL) {
        // Allocate memory for the log line
        log_line *log_line = malloc(sizeof(log_line));
        if (log_line == NULL) {
            fclose(file);
            free(log_file);
            return NULL;
        }

        // Copy the log line into the log line struct
        log_line->line = strdup(line);
        if (log_line->line == NULL) {
            fclose(file);
            free(log_file);
            free(log_line);
            return NULL;
        }

        // Set the log line number
        log_line->line_number = log_file->num_lines + 1;

        // Add the log line to the log file struct
        log_file->lines = realloc(log_file->lines, (log_file->num_lines + 1) * sizeof(log_line));
        if (log_file->lines == NULL) {
            fclose(file);
            free(log_file);
            free(log_line->line);
            free(log_line);
            return NULL;
        }
        log_file->lines[log_file->num_lines] = *log_line;
        log_file->num_lines++;
    }

    // Close the log file
    fclose(file);

    // Return the log file struct
    return log_file;
}

// Free the memory allocated for a log file
void free_log_file(log_file *log_file) {
    // Free the memory allocated for each log line
    for (int i = 0; i < log_file->num_lines; i++) {
        free(log_file->lines[i].line);
    }

    // Free the memory allocated for the log file struct
    free(log_file->lines);
    free(log_file);
}

// Print the log file to the console
void print_log_file(log_file *log_file) {
    // Print each log line to the console
    for (int i = 0; i < log_file->num_lines; i++) {
        printf("%d: %s", log_file->lines[i].line_number, log_file->lines[i].line);
    }
}

// Search for a string in a log file
int search_log_file(log_file *log_file, const char *string) {
    // Search each log line for the string
    for (int i = 0; i < log_file->num_lines; i++) {
        if (strstr(log_file->lines[i].line, string) != NULL) {
            return log_file->lines[i].line_number;
        }
    }

    // Return -1 if the string was not found
    return -1;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a log file
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    // Read the log file into memory
    log_file *log_file = read_log_file(argv[1]);
    if (log_file == NULL) {
        printf("Error: could not read log file %s\n", argv[1]);
        return 1;
    }

    // Print the log file to the console
    print_log_file(log_file);

    // Search for a string in the log file
    char *string = "ERROR";
    int line_number = search_log_file(log_file, string);
    if (line_number == -1) {
        printf("Error: could not find string %s in log file %s\n", string, argv[1]);
    } else {
        printf("Found string %s on line %d of log file %s\n", string, line_number, argv[1]);
    }

    // Free the memory allocated for the log file
    free_log_file(log_file);

    return 0;
}