//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_LINE_SIZE 10000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp = fopen(filename, "r");
    CSV *csv = NULL;

    if (fp == NULL) {
        printf("Error: failed to open %s\n", filename);
        return NULL;
    }

    csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_LINE_SIZE];
    char *token;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        row++;
        csv->rows = row;

        token = strtok(line, ",");

        while (token!= NULL) {
            col++;
            csv->cols = col;

            if (csv->data == NULL) {
                csv->data = (char **)malloc(sizeof(char *) * csv->rows);
                for (int i = 0; i < csv->rows; i++) {
                    csv->data[i] = (char *)malloc(sizeof(char) * csv->cols);
                }
            }

            strcpy(csv->data[row - 1], token);

            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    if (csv == NULL) {
        return 1;
    }

    csv_print(csv);

    csv_close(csv);

    return 0;
}