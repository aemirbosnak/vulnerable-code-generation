//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

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
    int row = 0, col = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file '%s'\n", filename);
        exit(1);
    }

    csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(sizeof(char *) * MAX_ROW);
    csv->row = 0;
    csv->col = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            if (row >= MAX_ROW) {
                printf("Error: too many rows in file '%s'\n", filename);
                exit(1);
            }
            if (col >= MAX_COL) {
                printf("Error: too many columns in file '%s'\n", filename);
                exit(1);
            }
            csv->data[row] = (char *)realloc(csv->data[row], strlen(token) + 1);
            strcpy(csv->data[row], token);
            row++;
            col++;
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    if (csv->row == 0) {
        printf("Error: file '%s' is empty\n", filename);
        exit(1);
    }

    fclose(fp);
    return csv;
}

void csv_close(CSV *csv) {
    int i;

    for (i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_row(CSV *csv) {
    return csv->row;
}

int csv_get_col(CSV *csv) {
    return csv->col;
}

char *csv_get_cell(CSV *csv, int row, int col) {
    if (row >= csv->row || col >= csv->col) {
        return NULL;
    }
    return csv->data[row][col];
}

void csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    CSV *csv;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    csv = csv_open(argv[1]);
    csv_print(csv);
    csv_close(csv);

    return 0;
}