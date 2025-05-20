//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *data; // CSV field data
    int length; // Length of CSV field data
} csv_field;

typedef struct {
    csv_field *fields;  // Pointer to CSV fields array
    int num_fields;     // Number of CSV fields
} csv_row;

typedef struct {
    FILE *file;         // Pointer to CSV file
    char *line;         // Buffer to hold CSV lines
    size_t line_size;   // Line buffer size
} csv_reader;

/**
 * Creates a new CSV reader.
 *
 * @param file_path Path to CSV file
 * @return New CSV reader
 */
csv_reader *csv_reader_new(char *file_path) {
    csv_reader *reader = malloc(sizeof(csv_reader));
    reader->file = fopen(file_path, "r");
    reader->line = NULL;
    reader->line_size = MAX_LINE_SIZE;
    return reader;
}

/**
 * Frees memory used by CSV reader.
 *
 * @param reader CSV reader to free
 */
void csv_reader_free(csv_reader *reader) {
    fclose(reader->file);
    free(reader->line);
    free(reader);
}

/**
 * Reads a CSV row from the CSV reader.
 *
 * @param reader CSV reader to read from
 * @return CSV row
 */
csv_row *csv_reader_read_row(csv_reader *reader) {
    if (getline(&reader->line, &reader->line_size, reader->file) == -1) {
        return NULL; // End of file
    }

    csv_row *row = malloc(sizeof(csv_row));
    char *field = strtok(reader->line, ",");
    row->num_fields = 0;
    while (field != NULL) {
        // Allocate memory for new field
        csv_field *new_field = malloc(sizeof(csv_field));
        int field_length = strlen(field);
        new_field->data = malloc(field_length + 1);
        strncpy(new_field->data, field, field_length);
        new_field->data[field_length] = '\0';
        
        // Add field to row
        row->fields = realloc(row->fields, sizeof(csv_field) * ++row->num_fields);
        row->fields[row->num_fields - 1] = *new_field;
        free(new_field);
        
        field = strtok(NULL, ",");
    }

    return row;
}

/**
 * Prints a CSV row to stdout.
 *
 * @param row CSV row to print
 */
void csv_row_print(csv_row *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i].data);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <csv-file-path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    csv_reader *reader = csv_reader_new(argv[1]);
    csv_row *row;

    while ((row = csv_reader_read_row(reader)) != NULL) {
        csv_row_print(row);
        free(row);
    }

    csv_reader_free(reader);
    exit(EXIT_SUCCESS);
}