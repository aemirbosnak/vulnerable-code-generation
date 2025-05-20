//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CsvRow;

typedef struct {
    FILE *file;
    char delimiter;
    CsvRow *row;
} CsvReader;

void csv_reader_init(CsvReader *reader, const char *filename, char delimiter) {
    reader->file = fopen(filename, "r");
    reader->delimiter = delimiter;
    reader->row = NULL;
}

int csv_reader_read_row(CsvReader *reader) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int num_fields = 0;

    if (fgets(line, MAX_LINE_LENGTH, reader->file) == NULL) {
        return 0;
    }

    token = strtok(line, reader->delimiter);
    while (token!= NULL) {
        if (num_fields >= MAX_FIELDS) {
            printf("Error: Too many fields in row.\n");
            return 0;
        }
        reader->row->fields[num_fields++] = strdup(token);
        token = strtok(NULL, reader->delimiter);
    }

    if (num_fields == 0) {
        return 0;
    }

    return 1;
}

void csv_reader_destroy(CsvReader *reader) {
    if (reader->row!= NULL) {
        for (int i = 0; i < reader->row->num_fields; i++) {
            free(reader->row->fields[i]);
        }
        free(reader->row->fields);
        free(reader->row);
    }

    fclose(reader->file);
}

int main() {
    CsvReader reader;
    CsvRow row;

    csv_reader_init(&reader, "example.csv", ',');

    while (csv_reader_read_row(&reader)) {
        printf("Row:\n");
        for (int i = 0; i < reader.row->num_fields; i++) {
            printf("%s\n", reader.row->fields[i]);
        }
    }

    csv_reader_destroy(&reader);

    return 0;
}