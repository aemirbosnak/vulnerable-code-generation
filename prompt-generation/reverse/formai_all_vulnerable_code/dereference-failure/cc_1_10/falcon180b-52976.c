//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1024

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    char line[MAX_CELL_SIZE];
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        char *token = strtok(line, ",");
        while (token!= NULL) {
            col++;
            if (row >= csv->num_rows) {
                csv->num_rows++;
                csv->data = realloc(csv->data, sizeof(char *) * csv->num_rows);
            }

            if (col >= csv->num_cols) {
                csv->num_cols++;
                csv->data[row] = realloc(csv->data[row], sizeof(char *) * csv->num_cols);
            }

            csv->data[row][col] = strdup(token);

            token = strtok(NULL, ",");
        }

        row++;
    }

    fclose(fp);

    return csv;
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

char *csv_get(CSV *csv, int row, int col) {
    if (row < 0 || row >= csv->num_rows || col < 0 || col >= csv->num_cols) {
        return NULL;
    }

    return csv->data[row][col];
}

int main() {
    CSV *csv = csv_open("example.csv");

    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            char *value = csv_get(csv, i, j);
            if (value!= NULL) {
                printf("%s ", value);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}