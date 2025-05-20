//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 100

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        exit(1);
    }

    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = (char **) malloc(MAX_ROW * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token!= NULL) {
            csv->data[csv->rows] = (char *) malloc((strlen(token) + 1) * sizeof(char));
            strcpy(csv->data[csv->rows], token);
            csv->rows++;
            col++;
            token = strtok(NULL, ",");
        }
        csv->cols = col > csv->cols? col : csv->cols;
    }

    fclose(fp);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    CSV *csv = csv_open("data.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}