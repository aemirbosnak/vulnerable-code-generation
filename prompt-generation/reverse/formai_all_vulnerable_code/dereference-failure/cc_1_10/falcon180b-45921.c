//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_CELL_SIZE 1024

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            col++;
            if (row >= csv->rows) {
                csv->rows += 10;
                csv->data = realloc(csv->data, sizeof(char *) * csv->rows);
            }
            if (col >= csv->cols) {
                csv->cols += 10;
                for (int i = 0; i < csv->rows; i++) {
                    csv->data[i] = realloc(csv->data[i], sizeof(char) * csv->cols);
                }
            }
            if (csv->data[row] == NULL) {
                csv->data[row] = malloc(sizeof(char) * csv->cols);
            }
            strcpy(csv->data[row], token);
            token = strtok(NULL, ",");
            row++;
        }
    }

    csv->data[row] = NULL;
    csv->cols = col;

    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

char *csv_get(CSV *csv, int row, int col) {
    if (row < 0 || row >= csv->rows || col < 0 || col >= csv->cols) {
        return NULL;
    }
    return csv->data[row][col];
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_open(fp);

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv_get(csv, i, j));
        }
        printf("\n");
    }

    csv_close(csv);
    fclose(fp);

    return 0;
}