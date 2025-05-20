//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

// structure to hold data from CSV file
typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// function to parse CSV file
CSV *parseCSV(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROW * sizeof(char*));
    csv->rows = 0;
    csv->cols = 0;

    char c;
    int row = 0;
    int col = 0;

    while ((c = fgetc(fp))!= EOF) {
        if (c == '\n') {
            row++;
            col = 0;
        } else if (c == ',') {
            col++;
        } else {
            csv->data[row] = realloc(csv->data[row], (col + 1) * sizeof(char));
            csv->data[row][col] = c;
            col++;
        }
    }

    csv->cols = col;
    csv->rows = row;

    return csv;
}

// function to print CSV data
void printCSV(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

// main function
int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    CSV *csv = parseCSV(fp);
    fclose(fp);

    printCSV(csv);

    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);

    return 0;
}