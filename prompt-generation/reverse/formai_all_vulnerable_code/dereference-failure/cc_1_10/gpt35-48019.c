//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_BUF_SIZE 1024

typedef struct {
    char **data;
    int num_cols;
} CsvRow;

typedef struct {
    CsvRow **rows;
    int num_rows;
} CsvFile;

CsvRow* csv_row_new(int num_cols) {
    CsvRow *row = (CsvRow*) malloc(sizeof(CsvRow));
    row->data = (char**) calloc(num_cols, sizeof(char*));
    row->num_cols = num_cols;

    return row;
}

void csv_row_set_data(CsvRow *row, char *data, int col) {
    row->data[col] = (char*) malloc(strlen(data) + 1);
    strcpy(row->data[col], data);
}

CsvFile* csv_file_new() {
    CsvFile *csv = (CsvFile*) malloc(sizeof(CsvFile));
    csv->rows = NULL;
    csv->num_rows = 0;

    return csv;
}

void csv_file_add_row(CsvFile *csv, CsvRow *row) {
    csv->rows = (CsvRow**) realloc(csv->rows, (csv->num_rows + 1) * sizeof(CsvRow*));
    csv->rows[csv->num_rows++] = row;
}

CsvFile* csv_file_read(const char *filename) {
    CsvFile *csv = csv_file_new();
    FILE *fp = fopen(filename, "r");
    char line_buf[LINE_BUF_SIZE];

    while (fgets(line_buf, LINE_BUF_SIZE, fp)) {
        CsvRow *row = csv_row_new(10);
        int col_idx = 0;

        char *value = strtok(line_buf, ",");
        while (value) {
            csv_row_set_data(row, value, col_idx++);
            value = strtok(NULL, ",");
        }

        csv_file_add_row(csv, row);
    }

    fclose(fp);

    return csv;
}

void csv_file_free(CsvFile *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i]->num_cols; j++) {
            free(csv->rows[i]->data[j]);
        }
        free(csv->rows[i]->data);
        free(csv->rows[i]);
    }
    free(csv->rows);
    free(csv);
}

int main() {
    CsvFile *csv = csv_file_read("example.csv");

    for (int i = 0; i < csv->num_rows; i++) {
        CsvRow *row = csv->rows[i];
        for (int j = 0; j < row->num_cols; j++) {
            printf("%s, ", row->data[j]);
        }
        printf("\n");
    }

    csv_file_free(csv);

    return 0;
}