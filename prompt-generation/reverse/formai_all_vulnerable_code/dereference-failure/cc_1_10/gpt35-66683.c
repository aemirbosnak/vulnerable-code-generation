//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_NUM_FIELDS 100

typedef struct {
    char *fields[MAX_NUM_FIELDS];
    int num_fields;
} CsvRow;

typedef struct {
    CsvRow **rows;
    int num_rows;
} CsvFile;

CsvRow* parse_csv_row(char *line) {
    CsvRow *row = (CsvRow*) malloc(sizeof(CsvRow));
    char *field_starts[MAX_NUM_FIELDS];
    char *field_ends[MAX_NUM_FIELDS];
    int i = 0, j = 0;
    field_starts[0] = line;

    while (line[i] != '\0') {
        if (line[i] == ',') {
            line[i] = '\0';
            field_ends[j++] = line + i + 1;
            field_starts[j] = line + i + 1;
        }
        i++;
    }
    field_ends[j] = line + i;

    for (int k = 0; k <= j; k++) {
        row->fields[k] = (char*) malloc(MAX_FIELD_LENGTH);
        strncpy(row->fields[k], field_starts[k], field_ends[k] - field_starts[k]);
        row->fields[k][field_ends[k] - field_starts[k]] = '\0';
    }
    row->num_fields = j + 1;
    return row;
}

CsvFile* parse_csv_file(char *filename) {
    CsvFile *csv = (CsvFile*) malloc(sizeof(CsvFile));
    csv->rows = (CsvRow**) malloc(sizeof(CsvRow*) * MAX_NUM_FIELDS);
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (i >= MAX_NUM_FIELDS) {
            break;
        }
        csv->rows[i++] = parse_csv_row(line);
    }
    csv->num_rows = i;
    fclose(file);
    return csv;
}

void print_csv_file(CsvFile *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        printf("row %d:\n", i);
        CsvRow *row = csv->rows[i];

        for (int j = 0; j < row->num_fields; j++) {
            printf("\t\"%s\"\n", row->fields[j]);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./csv_reader <filename>\n");
        return 1;
    }

    CsvFile *csv = parse_csv_file(argv[1]);
    print_csv_file(csv);
    return 0;
}