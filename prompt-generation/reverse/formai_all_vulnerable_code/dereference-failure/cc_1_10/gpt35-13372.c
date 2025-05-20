//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FIELD_COUNT 10

typedef struct {
    char** fields;
    int num_fields;
} CsvRow;

typedef struct {
    CsvRow** rows;
    int num_rows;
} CsvFile;

CsvRow* csv_parse_row(char* line) {
    CsvRow* row = malloc(sizeof(CsvRow));
    row->fields = malloc(sizeof(char*) * MAX_FIELD_COUNT);
    row->num_fields = 0;

    char* token = strtok(line, ",");
    while (token) {
        row->fields[row->num_fields++] = token;
        token = strtok(NULL, ",");
    }

    return row;
}

CsvFile* csv_parse_file(const char* filename) {
    CsvFile* file = malloc(sizeof(CsvFile));
    file->rows = malloc(sizeof(CsvRow*) * MAX_FIELD_COUNT);
    file->num_rows = 0;

    FILE* fp = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        file->rows[file->num_rows++] = csv_parse_row(line);
    }

    fclose(fp);
    return file;
}

void csv_free_row(CsvRow* row) {
    free(row->fields);
    free(row);
}

void csv_free_file(CsvFile* file) {
    for (int i = 0; i < file->num_rows; ++i) {
        csv_free_row(file->rows[i]);
    }
    free(file->rows);
    free(file);
}

int main() {
    CsvFile* file = csv_parse_file("example.csv");

    printf("Read %d rows from CSV file.\n", file->num_rows);

    // Print the contents of each row
    for (int i = 0; i < file->num_rows; ++i) {
        CsvRow* row = file->rows[i];
        printf("Row %d:\n", i + 1);
        for (int j = 0; j < row->num_fields; ++j) {
            printf("  Field %d: %s\n", j + 1, row->fields[j]);
        }
    }

    csv_free_file(file);
    return 0;
}