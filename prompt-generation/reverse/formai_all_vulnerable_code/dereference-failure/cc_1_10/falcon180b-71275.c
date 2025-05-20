//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000

typedef struct {
    char **fields;
    int num_fields;
} CsvRow;

CsvRow *csv_read_row(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    CsvRow *row = malloc(sizeof(CsvRow));
    row->num_fields = 0;
    row->fields = malloc(sizeof(char *) * MAX_FIELDS);

    fgets(line, MAX_LINE_LENGTH, fp);
    char *token = strtok(line, ",");

    while (token!= NULL) {
        row->fields[row->num_fields++] = token;
        token = strtok(NULL, ",");
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
        printf("Error: could not open file.\n");
        return 1;
    }

    CsvRow *row;

    while ((row = csv_read_row(fp))!= NULL) {
        csv_print_row(row);
        csv_free_row(row);
    }

    fclose(fp);
    return 0;
}