//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        if (csv->num_rows >= MAX_ROWS) {
            printf("Error: too many rows in file %s\n", filename);
            exit(1);
        }

        char **row = malloc(sizeof(char *) * MAX_COLS);
        int num_cols = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            row[num_cols] = strdup(token);
            num_cols++;
            token = strtok(NULL, ",");
        }
        row[num_cols] = NULL;

        csv->data = realloc(csv->data, sizeof(char *) * (csv->num_rows + 1));
        csv->data[csv->num_rows] = row;
        csv->num_rows++;

        if (num_cols > csv->num_cols) {
            csv->num_cols = num_cols;
        }
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}