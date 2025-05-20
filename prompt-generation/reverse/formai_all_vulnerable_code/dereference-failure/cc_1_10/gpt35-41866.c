//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LEN 1024

typedef struct {
    char** data;
    int num_fields;
} CsvRow;

typedef struct {
    CsvRow* rows;
    int num_rows;
} CsvFile;

CsvFile* csv_reader(char* filename) {
    CsvFile* csv = (CsvFile*) malloc(sizeof(CsvFile));
    csv->rows = NULL;
    csv->num_rows = 0;

    char line[MAX_FIELD_LEN];
    char* field;

    FILE* fp = fopen(filename, "r");

    if(fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return csv;
    }

    while(fgets(line, MAX_FIELD_LEN, fp) != NULL) {
        CsvRow row;
        row.data = NULL;
        row.num_fields = 0;

        field = strtok(line, ",");

        while(field != NULL) {
            row.data = (char**) realloc(row.data, sizeof(char*) * (row.num_fields + 1));
            row.data[row.num_fields] = strdup(field);
            row.num_fields++;
            field = strtok(NULL, ",");
        }

        csv->rows = (CsvRow*) realloc(csv->rows, sizeof(CsvRow) * (csv->num_rows + 1));
        csv->rows[csv->num_rows] = row;
        csv->num_rows++;
    }

    fclose(fp);
    return csv;
}

void csv_free(CsvFile* csv) {
    for(int i = 0; i < csv->num_rows; i++) {
        for(int j = 0; j < csv->rows[i].num_fields; j++) {
            free(csv->rows[i].data[j]);
        }
        free(csv->rows[i].data);
    }
    free(csv->rows);
    free(csv);
}

int main() {
    CsvFile* csv = csv_reader("example.csv");

    for(int i = 0; i < csv->num_rows; i++) {
        for(int j = 0; j < csv->rows[i].num_fields; j++) {
            printf("%s ", csv->rows[i].data[j]);
        }
        printf("\n");
    }

    csv_free(csv);
    return 0;
}