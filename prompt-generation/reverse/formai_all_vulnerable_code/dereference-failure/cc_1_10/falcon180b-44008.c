//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define DELIM ","

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp = fopen(filename, "r");
    CSV *csv = NULL;
    char line[1024];
    int i, j;

    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return NULL;
    }

    csv = (CSV *) malloc(sizeof(CSV));
    csv->data = (char **) malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        j = 0;
        for (i = 0; line[i]!= '\n'; i++) {
            if (line[i] == DELIM) {
                csv->data[csv->rows] = (char *) malloc((i - j + 1) * sizeof(char));
                memcpy(csv->data[csv->rows], &(line[j]), i - j);
                csv->data[csv->rows][i - j] = '\0';
                j = i + 1;
                csv->cols++;
            }
        }
        csv->data[csv->rows] = (char *) malloc((i - j + 1) * sizeof(char));
        memcpy(csv->data[csv->rows], &(line[j]), i - j);
        csv->data[csv->rows][i - j] = '\0';
        csv->rows++;
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            printf("%s%c", csv->data[i], DELIM);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    int i;

    for (i = 0; i < csv->rows; i++) {
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