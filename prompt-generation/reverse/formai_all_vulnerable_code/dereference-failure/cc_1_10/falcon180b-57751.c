//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_COLUMN 1000

typedef struct {
    int row;
    int column;
} Cell;

typedef struct {
    char **data;
    int row;
    int column;
} CSV;

CSV *createCSV(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROW_COLUMN * sizeof(char *));
    csv->row = 0;
    csv->column = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            csv->data[csv->row][i] = token;
            i++;
            token = strtok(NULL, ",");
        }
        csv->row++;
    }

    fclose(fp);
    return csv;
}

void printCSV(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->column; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

void freeCSV(CSV *csv) {
    int i;
    for (i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = createCSV("example.csv");
    printCSV(csv);
    freeCSV(csv);

    return 0;
}