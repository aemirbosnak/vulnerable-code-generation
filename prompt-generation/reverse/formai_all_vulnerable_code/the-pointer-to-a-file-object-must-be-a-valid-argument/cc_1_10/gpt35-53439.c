//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FIELDS 20
#define DELIMITER ","

typedef struct csv_row {
    char **fields;
    int field_count;
} CSVRow;

typedef struct csv_reader {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char *cursor;
} CSVReader;

CSVRow *csv_parse_row(char *row_str) {
    CSVRow *row = (CSVRow*) malloc(sizeof(CSVRow));
    row->fields = (char**) malloc(sizeof(char*) * MAX_FIELDS);

    char *delim_ptr = row_str;
    int field_count = 0;

    // parse fields
    while (delim_ptr) {
        char *end_ptr = strstr(delim_ptr, DELIMITER);

        if (end_ptr) {
            *end_ptr = '\0';
        }

        row->fields[field_count++] = strdup(delim_ptr);
        delim_ptr = end_ptr ? end_ptr + 1 : NULL;
    }

    row->field_count = field_count;
    return row;
}

CSVReader *csv_new_reader(char *filename) {
    CSVReader *reader = (CSVReader*) malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->cursor = reader->buffer;
    return reader;
}

void csv_close_reader(CSVReader *reader) {
    fclose(reader->file);
    free(reader);
}

int csv_read_row(CSVReader *reader, CSVRow **row) {
    // check for end of file
    if (feof(reader->file)) {
        return 0;
    }

    // read a line from the file
    char *line = fgets(reader->buffer, BUFFER_SIZE, reader->file);

    if (!line) {
        return 0;
    }

    // parse the row
    *row = csv_parse_row(line);
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    CSVReader *reader = csv_new_reader(argv[1]);

    if (!reader) {
        printf("Error opening file %s.\n", argv[1]);
        return 1;
    }

    CSVRow *row = NULL;
    int line_count = 0;

    while (csv_read_row(reader, &row)) {
        printf("Line %d: ", ++line_count);

        for (int i = 0; i < row->field_count; i++) {
            printf("%s%s", row->fields[i], i == row->field_count - 1 ? "\n" : ", ");
        }

        free(row);
    }

    csv_close_reader(reader);
    return 0;
}