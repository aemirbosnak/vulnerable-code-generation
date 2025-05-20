//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct row {
    char** values;
    int num_values;
} Row;

typedef struct csv {
    Row** rows;
    int num_rows;
    int num_cols;
} CSV;

Row* read_row_from_file(FILE* file, const char delimiter) {
    Row* row = (Row*) malloc(sizeof(Row));
    int num_cols = 1;
    char buffer[BUFFER_SIZE];
    char** values = (char**) malloc(sizeof(char*));
    fgets(buffer, BUFFER_SIZE, file);
    values[0] = strtok(buffer, &delimiter);
    while (values[num_cols-1] != NULL) {
        values = (char**) realloc(values, (++num_cols) * sizeof(char*));
        values[num_cols-1] = strtok(NULL, &delimiter);
    }
    row -> values = values;
    row -> num_values = num_cols - 1;
    return row;
}

CSV* read_csv_from_file(const char* filename, const char delimiter) {
    CSV* csv = (CSV*) malloc(sizeof(CSV));
    FILE* file = fopen(filename, "r");
    int num_rows = 1;
    Row** rows = (Row**) malloc(sizeof(Row*));
    rows[0] = read_row_from_file(file, delimiter);
    while (!feof(file)) {
        rows = (Row**) realloc(rows, (++num_rows) * sizeof(Row*));
        rows[num_rows-1] = read_row_from_file(file, delimiter);
    }
    csv -> rows = rows;
    csv -> num_rows = num_rows - 1;
    csv -> num_cols = rows[0] -> num_values;
    fclose(file);
    return csv;
}

void free_row(Row* row) {
    for(int i=0;i<row->num_values; i++)
        free(row->values[i]);
    free(row -> values);
    free(row);
}

void free_csv(CSV* csv) {
    for(int i=0;i<csv->num_rows; i++)
        free_row(csv->rows[i]);
    free(csv -> rows);
    free(csv);
}

int main() {
    CSV* csv = read_csv_from_file("example.csv", ',');
    for(int i=0;i<csv->num_rows; i++) {
        for(int j=0;j<csv->num_cols; j++) {
            printf("%s ", csv->rows[i]->values[j]);
        }
        printf("\n");
    }
    free_csv(csv);
    return 0;
}