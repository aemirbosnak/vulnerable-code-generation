//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp;
    CSV *csv;
    char line[MAX_LINE_SIZE];
    char *token;
    int num_rows = 0;
    int num_columns = 0;

    csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_columns = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        free(csv);
        return NULL;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)) {
        num_rows++;
        token = strtok(line, ",");
        while (token!= NULL) {
            num_columns++;
            token = strtok(NULL, ",");
        }
    }

    csv->num_rows = num_rows;
    csv->num_columns = num_columns;
    csv->data = (char **)malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        csv->data[i] = (char *)malloc(sizeof(char) * (MAX_COLUMNS + 1));
    }

    rewind(fp);
    return csv;
}

void csv_close(CSV *csv) {
    int i;

    for (i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_num_rows(CSV *csv) {
    return csv->num_rows;
}

int csv_get_num_columns(CSV *csv) {
    return csv->num_columns;
}

char *csv_get_value(CSV *csv, int row, int column) {
    return csv->data[row][column];
}

int main() {
    CSV *csv;
    int num_rows, num_columns;
    char **data;
    int i, j;

    csv = csv_open("example.csv");
    if (csv == NULL) {
        return 1;
    }

    num_rows = csv_get_num_rows(csv);
    num_columns = csv_get_num_columns(csv);

    printf("Number of Rows: %d\n", num_rows);
    printf("Number of Columns: %d\n", num_columns);

    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_columns; j++) {
            printf("%s ", csv_get_value(csv, i, j));
        }
        printf("\n");
    }

    csv_close(csv);
    return 0;
}