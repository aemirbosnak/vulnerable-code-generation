//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 100
#define MAX_COL_SIZE 100

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create() {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_load(CSV *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    char line[MAX_ROW_SIZE];
    int row = 0;
    int col = 0;
    while (fgets(line, MAX_ROW_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            if (col >= csv->cols) {
                csv->cols += 10; // Increase column size by 10 if necessary
                csv->data = (char **)realloc(csv->data, sizeof(char *) * csv->cols);
                for (int i = csv->cols - 10; i < csv->cols; i++) {
                    csv->data[i] = NULL;
                }
            }
            if (row >= csv->rows) {
                csv->rows += 10; // Increase row size by 10 if necessary
                csv->data = (char **)realloc(csv->data, sizeof(char *) * csv->rows);
                for (int i = csv->rows - 10; i < csv->rows; i++) {
                    csv->data[i] = NULL;
                    for (int j = 0; j < csv->cols; j++) {
                        csv->data[i][j] = NULL;
                    }
                }
            }
            csv->data[row][col] = strdup(token); // Copy token to CSV data
            col++;
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    fclose(fp);
    return 1;
}

void csv_print(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            if (csv->data[i][j]!= NULL) {
                printf("%s ", csv->data[i][j]);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_create();
    if (csv_load(csv, "example.csv")) {
        csv_print(csv);
        csv_destroy(csv);
        return 0;
    } else {
        csv_destroy(csv);
        return 1;
    }
}