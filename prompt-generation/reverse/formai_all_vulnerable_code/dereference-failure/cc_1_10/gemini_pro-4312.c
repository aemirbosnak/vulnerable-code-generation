//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a log line
#define MAX_LINE_LENGTH 1024

// Define the maximum number of fields in a log line
#define MAX_FIELDS 32

// Define the maximum length of a field name
#define MAX_FIELD_NAME_LENGTH 64

// Structure to represent a log line
typedef struct {
    char *line;
    int num_fields;
    char *fields[MAX_FIELDS];
} log_line;

// Function to read a log line from a file
log_line *read_log_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read the line from the file
    read = getline(&line, &len, fp);
    if (read == -1) {
        return NULL;
    }

    // Allocate memory for the log line
    log_line *log_line = malloc(sizeof(log_line));
    if (log_line == NULL) {
        free(line);
        return NULL;
    }

    // Initialize the log line
    log_line->line = line;
    log_line->num_fields = 0;

    // Tokenize the line
    char *token = strtok(line, " ");
    while (token != NULL) {
        // Check if the token is a field name
        if (token[0] == '[') {
            // Allocate memory for the field name
            char *field_name = malloc(strlen(token) + 1);
            if (field_name == NULL) {
                free(log_line);
                free(line);
                return NULL;
            }

            // Copy the field name
            strcpy(field_name, token);

            // Add the field name to the log line
            log_line->fields[log_line->num_fields] = field_name;
            log_line->num_fields++;
        }

        // Move to the next token
        token = strtok(NULL, " ");
    }

    // Return the log line
    return log_line;
}

// Function to free a log line
void free_log_line(log_line *log_line) {
    // Free the line
    free(log_line->line);

    // Free the field names
    for (int i = 0; i < log_line->num_fields; i++) {
        free(log_line->fields[i]);
    }

    // Free the log line
    free(log_line);
}

// Function to print a log line
void print_log_line(log_line *log_line) {
    // Print the line
    printf("%s", log_line->line);

    // Print the field names
    for (int i = 0; i < log_line->num_fields; i++) {
        printf("[%s]", log_line->fields[i]);
    }

    // Print a newline
    printf("\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a filename was specified
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the log file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open the log file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Read the log lines
    log_line *log_line;
    while ((log_line = read_log_line(fp)) != NULL) {
        // Print the log line
        print_log_line(log_line);

        // Free the log line
        free_log_line(log_line);
    }

    // Close the log file
    fclose(fp);

    return EXIT_SUCCESS;
}