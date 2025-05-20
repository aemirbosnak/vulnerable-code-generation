//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **fields;
    size_t num_fields;
    size_t capacity;
} CSVRow;

typedef struct {
    CSVRow *rows;
    size_t num_rows;
    size_t capacity;
    char *line_buffer;
    size_t line_buffer_size;
} CSVReader;

CSVReader *csv_reader_new() {
    CSVReader *reader = malloc(sizeof(CSVReader));
    if (reader == NULL) {
        return NULL;
    }

    reader->rows = NULL;
    reader->num_rows = 0;
    reader->capacity = 0;

    reader->line_buffer = NULL;
    reader->line_buffer_size = 0;

    return reader;
}

void csv_reader_free(CSVReader *reader) {
    if (reader == NULL) {
        return;
    }

    for (size_t i = 0; i < reader->num_rows; i++) {
        CSVRow *row = &reader->rows[i];

        for (size_t j = 0; j < row->num_fields; j++) {
            free(row->fields[j]);
        }

        free(row->fields);
    }

    free(reader->rows);
    free(reader->line_buffer);
    free(reader);
}

int csv_reader_load_file(CSVReader *reader, const char *filename) {
    if (reader == NULL || filename == NULL) {
        return -1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    char *line = NULL;
    size_t line_size = 0;

    while (getline(&line, &line_size, file) != -1) {
        csv_reader_add_row(reader, line);
    }

    free(line);
    fclose(file);

    return 0;
}

int csv_reader_add_row(CSVReader *reader, const char *line) {
    if (reader == NULL || line == NULL) {
        return -1;
    }

    size_t line_length = strlen(line);

    // Check if the line buffer is large enough to hold the new line.
    if (reader->line_buffer_size < line_length + 1) {
        // Reallocate the line buffer.
        reader->line_buffer = realloc(reader->line_buffer, line_length + 1);
        if (reader->line_buffer == NULL) {
            return -1;
        }

        reader->line_buffer_size = line_length + 1;
    }

    // Copy the line into the line buffer.
    strcpy(reader->line_buffer, line);

    // Tokenize the line into fields.
    char *field = strtok(reader->line_buffer, ",");
    while (field != NULL) {
        // Check if the CSV row has enough capacity for the new field.
        if (reader->num_rows >= reader->capacity) {
            // Reallocate the CSV row.
            reader->rows = realloc(reader->rows, (reader->capacity + 1) * sizeof(CSVRow));
            if (reader->rows == NULL) {
                return -1;
            }

            reader->capacity += 1;
        }

        // Check if the CSV row has enough capacity for the new field.
        CSVRow *row = &reader->rows[reader->num_rows];
        if (row->num_fields >= row->capacity) {
            // Reallocate the CSV row.
            row->fields = realloc(row->fields, (row->capacity + 1) * sizeof(char *));
            if (row->fields == NULL) {
                return -1;
            }

            row->capacity += 1;
        }

        // Add the field to the CSV row.
        row->fields[row->num_fields] = strdup(field);
        row->num_fields += 1;

        // Get the next field.
        field = strtok(NULL, ",");
    }

    // Increment the number of rows in the CSV reader.
    reader->num_rows += 1;

    return 0;
}

int main() {
    // Create a new CSV reader.
    CSVReader *reader = csv_reader_new();

    // Load the CSV file into the reader.
    int status = csv_reader_load_file(reader, "data.csv");
    if (status != 0) {
        printf("Error loading CSV file: %d\n", status);
        return 1;
    }

    // Print the CSV data to the console.
    for (size_t i = 0; i < reader->num_rows; i++) {
        CSVRow *row = &reader->rows[i];

        for (size_t j = 0; j < row->num_fields; j++) {
            printf("%s", row->fields[j]);
            if (j < row->num_fields - 1) {
                printf(", ");
            }
        }

        printf("\n");
    }

    // Free the CSV reader.
    csv_reader_free(reader);

    return 0;
}