//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            csv->cols++;
            csv->rows++;
            if (csv->data == NULL) {
                csv->data = malloc(csv->rows * sizeof(char *));
                for (int i = 0; i < csv->rows; i++) {
                    csv->data[i] = malloc(csv->cols * sizeof(char));
                }
            }
            strcpy(csv->data[csv->rows - 1], token);
            csv->data[csv->rows - 1][cols] = '\0';
            token = strtok(NULL, ",");
            cols++;
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