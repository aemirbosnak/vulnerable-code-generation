//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100
#define DELIMITER ","

typedef struct {
    char **data;
    int num_columns;
    int num_rows;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->num_columns = 0;
    csv->num_rows = 0;
    csv->data = NULL;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            csv->num_columns++;
            token = strtok(NULL, DELIMITER);
        }
        csv->num_rows++;
    }

    csv->data = malloc(csv->num_columns * sizeof(char *));
    for (int i = 0; i < csv->num_columns; i++) {
        csv->data[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    rewind(file);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_columns; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_num_columns(CSV *csv) {
    return csv->num_columns;
}

int csv_get_num_rows(CSV *csv) {
    return csv->num_rows;
}

char *csv_get_data(CSV *csv, int row, int column) {
    if (row >= csv->num_rows || column >= csv->num_columns) {
        return NULL;
    }

    return csv->data[column][row];
}

int main() {
    CSV *csv = csv_open("example.csv");

    printf("Number of columns: %d\n", csv_get_num_columns(csv));
    printf("Number of rows: %d\n", csv_get_num_rows(csv));

    for (int i = 0; i < csv_get_num_columns(csv); i++) {
        printf("Column %d:\n", i + 1);
        for (int j = 0; j < csv_get_num_rows(csv); j++) {
            char *data = csv_get_data(csv, j, i);
            printf("%s\n", data);
        }
    }

    csv_close(csv);

    return 0;
}