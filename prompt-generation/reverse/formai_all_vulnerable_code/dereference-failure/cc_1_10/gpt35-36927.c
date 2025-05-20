//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256
#define MAX_NUM_FIELDS 10

typedef struct {
    char **fields;
    int num_fields;
} CsvRow;

typedef struct {
    FILE *file;
    char separator;
} CsvReader;

void error(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

void free_csv_row(CsvRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
}

CsvRow *read_csv_row(CsvReader *reader) {
    char line[MAX_LINE_SIZE];
    if (fgets(line, MAX_LINE_SIZE, reader->file) == NULL) {
        return NULL;
    }

    CsvRow *row = (CsvRow *) malloc(sizeof(CsvRow));
    row->fields = (char **) malloc(MAX_NUM_FIELDS * sizeof(char *));
    row->num_fields = 0;

    char *field = strtok(line, &reader->separator);
    while (field != NULL && row->num_fields < MAX_NUM_FIELDS) {
        row->fields[row->num_fields++] = strdup(field);
        field = strtok(NULL, &reader->separator);
    }

    return row;
}

CsvReader *open_csv(char *filename, char separator) {
    CsvReader *reader = (CsvReader *) malloc(sizeof(CsvReader));
    reader->file = fopen(filename, "r");
    reader->separator = separator;

    if (reader->file == NULL) {
        error("Failed to open CSV file");
    }

    return reader;
}

void close_csv(CsvReader *reader) {
    fclose(reader->file);
    free(reader);
}

int main() {
    CsvReader *reader = open_csv("data.csv", ',');
    CsvRow *row = read_csv_row(reader);
    while (row != NULL) {
        for (int i = 0; i < row->num_fields; i++) {
            printf("%s,", row->fields[i]);
        }
        printf("\n");

        free_csv_row(row);
        row = read_csv_row(reader);
    }

    close_csv(reader);
    return 0;
}