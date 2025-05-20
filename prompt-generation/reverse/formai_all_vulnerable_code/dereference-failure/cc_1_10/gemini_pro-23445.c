//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CSV Reader struct
typedef struct {
    FILE *file;
    char *line;
    size_t line_len;
    size_t line_pos;
    char delimiter;
    char quote;
    int escape;
} CSVReader;

// CSV Reader functions
CSVReader *csv_reader_init(FILE *file, char delimiter, char quote, int escape) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = file;
    reader->line = NULL;
    reader->line_len = 0;
    reader->line_pos = 0;
    reader->delimiter = delimiter;
    reader->quote = quote;
    reader->escape = escape;
    return reader;
}

void csv_reader_free(CSVReader *reader) {
    free(reader->line);
    free(reader);
}

int csv_reader_next_line(CSVReader *reader) {
    // Read a line from the file
    ssize_t len = getline(&reader->line, &reader->line_len, reader->file);
    if (len == -1) {
        return 0;
    }

    // Remove the newline character
    if (reader->line[len - 1] == '\n') {
        reader->line[len - 1] = '\0';
    }

    // Reset the line position
    reader->line_pos = 0;

    return 1;
}

int csv_reader_next_field(CSVReader *reader, char **field) {
    // Skip any leading whitespace
    while (reader->line_pos < reader->line_len && isspace(reader->line[reader->line_pos])) {
        reader->line_pos++;
    }

    // If we're at the end of the line, return 0
    if (reader->line_pos == reader->line_len) {
        return 0;
    }

    // Check if we're starting a quoted field
    if (reader->line[reader->line_pos] == reader->quote) {
        return csv_reader_next_quoted_field(reader, field);
    } else {
        return csv_reader_next_unquoted_field(reader, field);
    }
}

int csv_reader_next_quoted_field(CSVReader *reader, char **field) {
    // Skip the opening quote
    reader->line_pos++;

    // Find the closing quote
    size_t start_pos = reader->line_pos;
    while (reader->line_pos < reader->line_len && reader->line[reader->line_pos] != reader->quote) {
        if (reader->line[reader->line_pos] == reader->escape) {
            reader->line_pos++;  // Skip the escaped character
        }
        reader->line_pos++;
    }

    // If we didn't find the closing quote, return an error
    if (reader->line_pos == reader->line_len) {
        return -1;
    }

    // Copy the field into the output buffer
    *field = malloc(reader->line_pos - start_pos + 1);
    strncpy(*field, reader->line + start_pos, reader->line_pos - start_pos);
    (*field)[reader->line_pos - start_pos] = '\0';

    // Skip the closing quote
    reader->line_pos++;

    return 1;
}

int csv_reader_next_unquoted_field(CSVReader *reader, char **field) {
    // Find the next delimiter
    size_t start_pos = reader->line_pos;
    while (reader->line_pos < reader->line_len && reader->line[reader->line_pos] != reader->delimiter) {
        reader->line_pos++;
    }

    // Copy the field into the output buffer
    *field = malloc(reader->line_pos - start_pos + 1);
    strncpy(*field, reader->line + start_pos, reader->line_pos - start_pos);
    (*field)[reader->line_pos - start_pos] = '\0';

    // Skip the delimiter
    reader->line_pos++;

    return 1;
}

// Main function
int main() {
    // Open the CSV file
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Create a CSV reader
    CSVReader *reader = csv_reader_init(file, ',', '"', 1);

    // Read the CSV file line by line
    while (csv_reader_next_line(reader)) {
        // Read the fields in the current line
        char *field;
        while (csv_reader_next_field(reader, &field)) {
            printf("%s ", field);
            free(field);
        }
        printf("\n");
    }

    // Free the CSV reader
    csv_reader_free(reader);

    // Close the CSV file
    fclose(file);

    return EXIT_SUCCESS;
}