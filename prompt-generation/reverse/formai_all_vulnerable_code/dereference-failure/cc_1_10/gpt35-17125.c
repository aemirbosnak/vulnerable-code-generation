//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FIELD_SIZE 100

typedef struct {
    int num_fields;
    char **fields;
} CsvRow;

typedef struct {
    int num_rows;
    CsvRow **rows;
} CsvFile;

CsvRow *read_csv_row(FILE *file) {
    CsvRow *row = (CsvRow *) malloc(sizeof(CsvRow));
    row->num_fields = 0;
    row->fields = NULL;

    char line[MAX_LINE_SIZE];
    if (fgets(line, MAX_LINE_SIZE, file)) {
        char *field = strtok(line, ",");
        while (field != NULL) {
            row->num_fields++;
            row->fields = (char **)realloc(row->fields, row->num_fields * sizeof(char *));
            row->fields[row->num_fields - 1] = strdup(field);
            field = strtok(NULL, ",");
        }
    }

    return row;
}

CsvFile *read_csv_file(char *filename) {
    CsvFile *file = (CsvFile *) malloc(sizeof(CsvFile));
    file->num_rows = 0;
    file->rows = NULL;

    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        CsvRow *row = read_csv_row(fp);
        while (row->num_fields > 0) {
            file->num_rows++;
            file->rows = (CsvRow **)realloc(file->rows, file->num_rows * sizeof(CsvRow *));
            file->rows[file->num_rows - 1] = row;
            row = read_csv_row(fp);
        }
        fclose(fp);
    }

    return file;
}

void free_csv_row(CsvRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

void free_csv_file(CsvFile *file) {
    for (int i = 0; i < file->num_rows; i++) {
        free_csv_row(file->rows[i]);
    }
    free(file->rows);
    free(file);
}

int main() {
    CsvFile *file = read_csv_file("example.csv");

    for (int i = 0; i < file->num_rows; i++) {
        CsvRow *row = file->rows[i];
        for (int j = 0; j < row->num_fields; j++) {
            printf("%s ", row->fields[j]);
        }
        printf("\n");
    }

    free_csv_file(file);
    return 0;
}