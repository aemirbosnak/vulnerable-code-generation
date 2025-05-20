//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 1000
#define MAX_ROWS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_create() {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = (char **) malloc(MAX_ROWS * sizeof(char *));
    csv->num_rows = 0;
    csv->num_columns = 0;

    for (int i = 0; i < MAX_ROWS; i++) {
        csv->data[i] = (char *) malloc(MAX_CELL_SIZE * sizeof(char));
        memset(csv->data[i], '\0', MAX_CELL_SIZE);
    }

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_parse_line(CSV *csv, char *line) {
    char *token = strtok(line, ",");
    int col = 0;

    while (token!= NULL) {
        if (col >= csv->num_columns) {
            csv->num_columns++;
        }

        int len = strlen(token);
        if (len > MAX_CELL_SIZE - 1) {
            printf("Warning: Cell value truncated.\n");
            len = MAX_CELL_SIZE - 1;
        }

        strncpy(csv->data[csv->num_rows - 1] + (col * MAX_CELL_SIZE), token, len);
        col++;

        token = strtok(NULL, ",");
    }

    csv->num_rows++;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[i] + (j * MAX_CELL_SIZE));
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_create();

    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        csv_parse_line(csv, line);
    }

    fclose(fp);
    csv_print(csv);
    csv_destroy(csv);

    return 0;
}