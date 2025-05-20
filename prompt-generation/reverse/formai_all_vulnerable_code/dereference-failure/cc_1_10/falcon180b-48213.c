//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_LINE 10000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV* read_csv(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_LINE];
    char *token = NULL;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        row++;

        token = strtok(line, ",");
        while (token!= NULL) {
            col++;

            if (row == 1) {
                csv->cols = col;
                csv->data = malloc(sizeof(char *) * csv->cols);
                for (int i = 0; i < csv->cols; i++) {
                    csv->data[i] = malloc(MAX_LINE);
                }
            }

            strncpy(csv->data[col - 1], token, strlen(token));

            token = strtok(NULL, ",");
        }
    }

    csv->rows = row;

    return csv;
}

void print_csv(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[j]);
        }
        printf("\n");
    }
}

void free_csv(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSV *csv = read_csv(fp);
    if (csv == NULL) {
        printf("Error reading file.\n");
        return 1;
    }

    print_csv(csv);

    free_csv(csv);

    return 0;
}