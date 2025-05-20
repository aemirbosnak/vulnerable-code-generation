//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_PER_LINE 1024
#define MAX_NUM_FIELDS 20

typedef struct {
    char *fields[MAX_NUM_FIELDS];
    int num_fields;
} CSVRow;

typedef struct {
    CSVRow *rows;
    int num_rows;
    int max_rows;
} CSVReader;

CSVReader *csv_open(char *filename, char *delim) {
    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));
    reader->rows = (CSVRow *)malloc(sizeof(CSVRow) * 10);
    reader->num_rows = 0;
    reader->max_rows = 10;
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: could not open file %s.\n", filename);
        exit(1);
    }
    char line[MAX_CHAR_PER_LINE];
    while (fgets(line, MAX_CHAR_PER_LINE, f)) {
        if (reader->num_rows == reader->max_rows) {
            reader->max_rows *= 2;
            reader->rows = (CSVRow *)realloc(reader->rows, sizeof(CSVRow) * reader->max_rows);
        }
        CSVRow *row = &(reader->rows[reader->num_rows]);
        row->num_fields = 0;
        char *token = strtok(line, delim);
        while (token != NULL) {
            row->fields[row->num_fields++] = strdup(token);
            token = strtok(NULL, delim);
        }
        reader->num_rows++;
    }
    fclose(f);
    return reader;
}

void csv_close(CSVReader *reader) {
    for (int i = 0; i < reader->num_rows; i++) {
        CSVRow *row = &(reader->rows[i]);
        for (int j = 0; j < row->num_fields; j++) {
            free(row->fields[j]);
        }
    }
    free(reader->rows);
    free(reader);
}

int main() {
    CSVReader *reader = csv_open("data.csv", ",");
    for (int i = 0; i < reader->num_rows; i++) {
        CSVRow *row = &(reader->rows[i]);
        for (int j = 0; j < row->num_fields; j++) {
            printf("%s ", row->fields[j]);
        }
        printf("\n");
    }
    csv_close(reader);
    return 0;
}