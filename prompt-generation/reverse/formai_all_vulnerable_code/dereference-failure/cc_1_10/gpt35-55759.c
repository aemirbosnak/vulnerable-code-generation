//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 30
#define MAX_ROWS 1000
#define MAX_FIELD_LEN 50

typedef struct CSVRow {
    char fields[MAX_COLS][MAX_FIELD_LEN];
    int num_cols;
} CSVRow;

typedef struct CSVReader {
    char* file_path;
    char field_sep;
    CSVRow rows[MAX_ROWS];
    int num_rows;
    int max_cols;
} CSVReader;

CSVReader* create_csv_reader(char* file_path, char field_sep) {
    CSVReader* reader = (CSVReader*) malloc(sizeof(CSVReader));
    reader->file_path = file_path;
    reader->field_sep = field_sep;
    reader->num_rows = 0;
    reader->max_cols = 0;
    return reader;
}

void destroy_csv_reader(CSVReader* reader) {
    free(reader);
}

void print_csv_row(CSVRow* row) {
    for (int i = 0; i < row->num_cols; i++) {
        printf("%s", row->fields[i]);
        if (i != row->num_cols - 1) {
            printf(",");
        }
    }
    printf("\n");
}

void print_csv_reader(CSVReader* reader) {
    for (int i = 0; i < reader->num_rows; i++) {
        print_csv_row(&reader->rows[i]);
    }
}

void parse_csv_line(CSVReader* reader, char* line) {
    CSVRow* row = &reader->rows[reader->num_rows];
    char* field = strtok(line, &reader->field_sep);
    row->num_cols = 0;
    while (field != NULL) {
        strncpy(row->fields[row->num_cols], field, MAX_FIELD_LEN);
        row->num_cols++;
        field = strtok(NULL, &reader->field_sep);
    }
    if (row->num_cols > reader->max_cols) {
        reader->max_cols = row->num_cols;
    }
    reader->num_rows++;
}

void read_csv_file(CSVReader* reader) {
    FILE* fp = fopen(reader->file_path, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", reader->file_path);
        return;
    }
    char line[MAX_COLS * MAX_FIELD_LEN] = "";
    while (fgets(line, MAX_COLS * MAX_FIELD_LEN, fp) != NULL) {
        parse_csv_line(reader, line);
    }
    fclose(fp);
}

int main() {
    CSVReader* reader = create_csv_reader("example.csv", ',');
    read_csv_file(reader);
    print_csv_reader(reader);
    destroy_csv_reader(reader);
    return 0;
}