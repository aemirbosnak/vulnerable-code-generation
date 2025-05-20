//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom CSV reader struct
typedef struct csv_reader {
    FILE *file;  // File pointer
    char *line;  // Buffer for current line
    size_t line_len;  // Length of current line
    size_t line_cap;  // Capacity of current line buffer
    char delim;  // Delimiter character
} csv_reader_t;

// Create a new CSV reader
csv_reader_t *csv_reader_new(FILE *file, char delim) {
    csv_reader_t *reader = malloc(sizeof(csv_reader_t));
    if (!reader) {
        return NULL;
    }

    reader->file = file;
    reader->line = NULL;
    reader->line_len = 0;
    reader->line_cap = 0;
    reader->delim = delim;

    return reader;
}

// Free the resources associated with a CSV reader
void csv_reader_free(csv_reader_t *reader) {
    if (reader) {
        if (reader->line) {
            free(reader->line);
        }
        free(reader);
    }
}

// Read the next line from a CSV file
char *csv_reader_next(csv_reader_t *reader) {
    // Read a line from the file
    ssize_t len = getline(&reader->line, &reader->line_cap, reader->file);
    if (len == -1) {
        return NULL;
    }

    // Trim the newline character from the end of the line
    if (reader->line[len - 1] == '\n') {
        reader->line[len - 1] = '\0';
    }

    // Return the line
    return reader->line;
}

// Split a CSV line into fields
char **csv_reader_split(csv_reader_t *reader, char *line) {
    // Allocate an array of pointers to fields
    size_t num_fields = 0;
    char **fields = malloc(sizeof(char *) * num_fields);
    if (!fields) {
        return NULL;
    }

    // Split the line into fields
    char *field = strtok(line, &reader->delim);
    while (field) {
        // Allocate memory for the field
        field = strdup(field);
        if (!field) {
            // Free the allocated fields
            for (size_t i = 0; i < num_fields; i++) {
                free(fields[i]);
            }
            free(fields);
            return NULL;
        }

        // Add the field to the array
        fields = realloc(fields, sizeof(char *) * ++num_fields);
        fields[num_fields - 1] = field;

        // Get the next field
        field = strtok(NULL, &reader->delim);
    }

    // Return the array of fields
    return fields;
}

int main() {
    // Open the CSV file
    FILE *file = fopen("data.csv", "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Create a CSV reader
    csv_reader_t *reader = csv_reader_new(file, ',');
    if (!reader) {
        perror("Error creating CSV reader");
        return EXIT_FAILURE;
    }

    // Read the CSV file line by line
    char *line;
    while ((line = csv_reader_next(reader)) != NULL) {
        // Split the line into fields
        char **fields = csv_reader_split(reader, line);
        if (!fields) {
            perror("Error splitting line");
            return EXIT_FAILURE;
        }

        // Process the fields
        for (size_t i = 0; i < fields[i] != NULL; i++) {
            printf("%s\n", fields[i]);
        }

        // Free the allocated fields
        for (size_t i = 0; i < fields[i] != NULL; i++) {
            free(fields[i]);
        }
        free(fields);
    }

    // Free the CSV reader
    csv_reader_free(reader);

    // Close the CSV file
    fclose(file);

    return EXIT_SUCCESS;
}