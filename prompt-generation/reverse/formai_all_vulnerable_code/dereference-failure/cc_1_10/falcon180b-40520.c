//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_CSV_COLUMNS 1000

typedef struct {
    char **values;
    int num_columns;
} CSVRow;

CSVRow *read_csv_file(FILE *fp) {
    char line[MAX_LINE_SIZE];
    CSVRow *row = NULL;
    int num_columns = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;

        if (row == NULL) {
            row = malloc(sizeof(CSVRow));
            row->values = calloc(MAX_CSV_COLUMNS, sizeof(char*));
            row->num_columns = 0;
        }

        while (token!= NULL) {
            row->values[i] = strdup(token);
            i++;

            if (i >= MAX_CSV_COLUMNS) {
                printf("Error: too many columns in row\n");
                exit(1);
            }

            if (num_columns == 0) {
                num_columns = i;
            }

            token = strtok(NULL, ",");
        }

        if (num_columns == 0) {
            num_columns = i;
        }
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    int i;

    for (i = 0; i < row->num_columns; i++) {
        printf("%s ", row->values[i]);
    }

    printf("\n");
}

void free_csv_row(CSVRow *row) {
    int i;

    for (i = 0; i < row->num_columns; i++) {
        free(row->values[i]);
    }

    free(row->values);
    free(row);
}

int main() {
    FILE *fp;
    CSVRow *row;

    fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    row = read_csv_file(fp);

    if (row == NULL) {
        printf("Error: no data in file\n");
        exit(1);
    }

    print_csv_row(row);

    free_csv_row(row);

    fclose(fp);

    return 0;
}