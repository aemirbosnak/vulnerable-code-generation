//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv(FILE *fp) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->fields = NULL;
    row->num_fields = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            row->num_fields++;
            if (row->num_fields == 1) {
                row->fields = malloc(sizeof(char *));
            } else {
                row->fields = realloc(row->fields, sizeof(char *) * row->num_fields);
            }
            row->fields[row->num_fields - 1] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
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
        return 1;
    }

    CSVRow *row = read_csv(fp);
    print_csv_row(row);

    free_csv_row(row);
    fclose(fp);

    return 0;
}