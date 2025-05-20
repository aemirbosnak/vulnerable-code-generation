//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_LINE 10000

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *csv_create() {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    csv->row = 0;
    csv->col = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_append(CSV *csv, char *line) {
    char **data = csv->data;
    int row = csv->row;
    int col = csv->col;

    if (row >= MAX_ROW) {
        printf("Error: Maximum number of rows exceeded.\n");
        return;
    }

    if (col >= MAX_COL) {
        printf("Error: Maximum number of columns exceeded.\n");
        return;
    }

    int len = strlen(line);
    if (len > MAX_LINE) {
        printf("Error: Line too long.\n");
        return;
    }

    data[row] = (char *)malloc(len + 1);
    strcpy(data[row], line);
    csv->row++;
}

void csv_print(CSV *csv) {
    char **data = csv->data;
    int row = csv->row;
    int col = csv->col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s ", data[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    CSV *csv = csv_create();

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        csv_append(csv, line);
    }

    fclose(fp);

    csv_print(csv);

    csv_destroy(csv);

    return 0;
}