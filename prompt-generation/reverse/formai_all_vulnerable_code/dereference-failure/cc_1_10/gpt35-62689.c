//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LEN 50
#define MAX_CSV_LINE_LEN 1024

typedef struct {
    char *fields[MAX_FIELDS];
    int num_fields;
} CsvRow;

typedef struct {
    FILE *file;
    char *delim;
} CsvReader;

CsvReader* CsvReader_new(FILE *file, const char *delim) {
    CsvReader *csv = malloc(sizeof(CsvReader));
    csv->file = file;
    csv->delim = strdup(delim);
    return csv;
}

void CsvReader_destroy(CsvReader *csv) {
    free(csv->delim);
    free(csv);
}

CsvRow* CsvRow_new() {
    CsvRow *row = malloc(sizeof(CsvRow));
    row->num_fields = 0;
    return row;
}

void CsvRow_destroy(CsvRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row);
}

char* CsvRow_get_field(CsvRow *row, int field_num) {
    if (field_num < 0 || field_num >= row->num_fields) {
        return NULL;
    } else {
        return row->fields[field_num];
    }
}

CsvRow* CsvReader_get_row(CsvReader *csv) {
    char line[MAX_CSV_LINE_LEN];
    if (fgets(line, MAX_CSV_LINE_LEN, csv->file)) {
        CsvRow *row = CsvRow_new();
        char *field = strtok(line, csv->delim);
        while (field) {
            if (row->num_fields == MAX_FIELDS) {
                fprintf(stderr, "Too many fields in row\n");
                CsvRow_destroy(row);
                return NULL;
            }
            row->fields[row->num_fields++] = strdup(field);
            field = strtok(NULL, csv->delim);
        }
        return row;
    } else {
        return NULL;
    }
}

int main() {
    CsvReader *csv = CsvReader_new(stdin, ",");
    CsvRow *row;
    while ((row = CsvReader_get_row(csv))) {
        for (int i = 0; i < row->num_fields; i++) {
            printf("%s\t", CsvRow_get_field(row, i));
        }
        printf("\n");
        CsvRow_destroy(row);
    }
    CsvReader_destroy(csv);
    return 0;
}