//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100
#define MAX_FIELD_SIZE 256

typedef struct {
    char **fields;
    int num_fields;
    int field_sizes[MAX_FIELDS];
} CsvRow;

typedef struct {
    FILE *fp;
    char delimiter;
    int header_row;
} CsvFile;

CsvRow *read_csv_row(CsvFile *csv_file) {
    CsvRow *row = malloc(sizeof(CsvRow));
    row->num_fields = 0;
    row->fields = malloc(MAX_FIELDS * sizeof(char*));

    char line[MAX_LINE_SIZE];
    fgets(line, MAX_LINE_SIZE, csv_file->fp);

    char *p = line;
    while (*p!= '\0' && row->num_fields < MAX_FIELDS) {
        if (*p == csv_file->delimiter) {
            *p = '\0';
            row->field_sizes[row->num_fields] = p - line;
            row->fields[row->num_fields] = malloc(row->field_sizes[row->num_fields] + 1);
            strncpy(row->fields[row->num_fields], line, row->field_sizes[row->num_fields]);
            row->num_fields++;
            p++;
        } else {
            p++;
        }
    }

    if (csv_file->header_row == 1) {
        csv_file->header_row = 0;
    }

    return row;
}

void free_csv_row(CsvRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

void print_csv_row(CsvRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

int main() {
    CsvFile csv_file;
    csv_file.fp = fopen("data.csv", "r");
    csv_file.delimiter = ',';
    csv_file.header_row = 1;

    while (true) {
        CsvRow *row = read_csv_row(&csv_file);
        if (row == NULL) {
            break;
        }
        print_csv_row(row);
        free_csv_row(row);
    }

    fclose(csv_file.fp);
    return 0;
}