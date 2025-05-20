//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 100

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp;
    CSV *csv;
    char line[1024];
    char *token;
    int row = 0;
    int col = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    csv->row = 0;
    csv->col = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            if (row >= MAX_ROW) {
                printf("Error: Too many rows in file %s\n", filename);
                exit(1);
            }
            if (col >= MAX_COL) {
                printf("Error: Too many columns in file %s\n", filename);
                exit(1);
            }
            csv->data[row][col] = strdup(token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    fclose(fp);

    return csv;
}

void csv_close(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            printf("%s\t", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv;

    csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}