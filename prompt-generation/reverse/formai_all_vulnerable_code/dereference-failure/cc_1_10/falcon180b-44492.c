//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_CSV_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CsvRow;

CsvRow *csv_read(FILE *fp) {
    CsvRow *row = malloc(sizeof(CsvRow));
    row->num_fields = 0;
    row->fields = malloc(MAX_CSV_FIELDS * sizeof(char *));

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;

        while (token!= NULL) {
            row->fields[i] = strdup(token);
            i++;
            token = strtok(NULL, ",");
        }

        row->num_fields = i;
    }

    return row;
}

void csv_print_row(CsvRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void csv_free_row(CsvRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    CsvRow *row = csv_read(fp);
    csv_print_row(row);

    csv_free_row(row);
    fclose(fp);

    return 0;
}