//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10

typedef struct {
    int num_fields;
    char **fields;
} CsvRow;

typedef struct {
    int num_rows;
    CsvRow *rows;
} CsvFile;

CsvRow *readFields(FILE *file) {
    CsvRow *row = (CsvRow*)malloc(sizeof(CsvRow));
    row->fields = (char**)malloc(sizeof(char*) * MAX_FIELDS);
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);
    char *token = strtok(line, ",");
    int i = 0;
    while (token != NULL && i < MAX_FIELDS) {
        row->fields[i] = (char*)malloc(strlen(token) + 1);
        strcpy(row->fields[i], token);
        i++;
        token = strtok(NULL, ",");
    }
    row->num_fields = i;
    return row;
}

CsvFile *readCsvFile(const char *filename) {
    CsvFile *csv = (CsvFile*)malloc(sizeof(CsvFile));
    csv->num_rows = 0;
    csv->rows = NULL;
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        CsvRow *row = readFields(file);
        while (!feof(file) && row->num_fields > 0) {
            csv->num_rows++;
            csv->rows = (CsvRow*)realloc(csv->rows, sizeof(CsvRow) * csv->num_rows);
            csv->rows[csv->num_rows - 1] = *row;
            row = readFields(file);
        }
        fclose(file);
    }
    return csv;
}

void freeCsvRow(CsvRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

void freeCsvFile(CsvFile *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        freeCsvRow(&csv->rows[i]);
    }
    free(csv->rows);
    free(csv);
}

int main() {
    CsvFile *csv = readCsvFile("example.csv");
    for (int i = 0; i < csv->num_rows; i++) {
        CsvRow row = csv->rows[i];
        for (int j = 0; j < row.num_fields; j++) {
            printf("%s\t", row.fields[j]);
        }
        printf("\n");
    }
    freeCsvFile(csv);
    return 0;
}