//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the CSV reader struct
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t buffer_used;
    FILE *file;
} csv_reader_t;

// Create a new CSV reader
csv_reader_t *csv_reader_new(FILE *file) {
    csv_reader_t *reader = malloc(sizeof(csv_reader_t));
    if (!reader) {
        return NULL;
    }

    reader->buffer = NULL;
    reader->buffer_size = 0;
    reader->buffer_used = 0;
    reader->file = file;

    return reader;
}

// Free the CSV reader
void csv_reader_free(csv_reader_t *reader) {
    if (!reader) {
        return;
    }

    if (reader->buffer) {
        free(reader->buffer);
    }

    free(reader);
}

// Read a line from the CSV file
char *csv_reader_readline(csv_reader_t *reader) {
    if (!reader) {
        return NULL;
    }

    // If the buffer is full, reallocate it
    if (reader->buffer_used == reader->buffer_size) {
        reader->buffer_size *= 2;
        reader->buffer = realloc(reader->buffer, reader->buffer_size);
        if (!reader->buffer) {
            return NULL;
        }
    }

    // Read a line from the file
    size_t bytes_read = getline(&reader->buffer, &reader->buffer_size, reader->file);
    if (bytes_read == -1) {
        return NULL;
    }

    // Remove the newline character from the end of the line
    if (reader->buffer[bytes_read - 1] == '\n') {
        reader->buffer[bytes_read - 1] = '\0';
    }

    // Return the line
    return reader->buffer;
}

// Split a line into fields
char **csv_reader_split(char *line) {
    if (!line) {
        return NULL;
    }

    // Count the number of fields in the line
    size_t field_count = 0;
    for (char *p = line; *p; p++) {
        if (*p == ',') {
            field_count++;
        }
    }

    // Allocate memory for the fields
    char **fields = malloc((field_count + 1) * sizeof(char *));
    if (!fields) {
        return NULL;
    }

    // Split the line into fields
    size_t field_index = 0;
    char *field_start = line;
    for (char *p = line; *p; p++) {
        if (*p == ',') {
            *p = '\0';
            fields[field_index++] = field_start;
            field_start = p + 1;
        }
    }

    // Add the last field to the array
    fields[field_index++] = field_start;

    // Return the fields
    return fields;
}

// Print the fields of a line
void csv_reader_print_fields(char **fields) {
    if (!fields) {
        return;
    }

    // Print each field
    for (char **field = fields; *field; field++) {
        printf("%s", *field);
        if (*(field + 1)) {
            printf(", ");
        }
    }

    // Print a newline character
    printf("\n");
}

// Read a CSV file and print the fields of each line
int main() {
    // Open the CSV file
    FILE *file = fopen("data.csv", "r");
    if (!file) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Create a CSV reader
    csv_reader_t *reader = csv_reader_new(file);
    if (!reader) {
        perror("csv_reader_new");
        return EXIT_FAILURE;
    }

    // Read each line from the CSV file
    char *line;
    while ((line = csv_reader_readline(reader))) {
        // Split the line into fields
        char **fields = csv_reader_split(line);
        if (!fields) {
            perror("csv_reader_split");
            return EXIT_FAILURE;
        }

        // Print the fields of the line
        csv_reader_print_fields(fields);

        // Free the fields
        free(fields);
    }

    // Free the CSV reader
    csv_reader_free(reader);

    // Close the CSV file
    fclose(file);

    return EXIT_SUCCESS;
}