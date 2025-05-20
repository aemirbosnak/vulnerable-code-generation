//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    char *token = NULL;
    int count = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        count++;
        if (count == 1) { // header row
            token = strtok(line, ",");
            while (token!= NULL) {
                csv->cols++;
                token = strtok(NULL, ",");
            }
        }
    }

    csv->data = (char **)malloc(csv->rows * sizeof(char *));
    csv->rows = count - 1;
    csv->cols = csv->cols;

    rewind(fp);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_col_index(CSV *csv, char *col_name) {
    for (int i = 0; i < csv->cols; i++) {
        if (strcmp(csv->data[0][i], col_name) == 0) {
            return i;
        }
    }
    return -1;
}

int csv_get_row_count(CSV *csv) {
    return csv->rows;
}

int csv_get_col_count(CSV *csv) {
    return csv->cols;
}

char *csv_get_value(CSV *csv, int row, int col) {
    return csv->data[row][col];
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_open(fp);

    int row_count = csv_get_row_count(csv);
    int col_count = csv_get_col_count(csv);

    printf("Number of rows: %d\n", row_count);
    printf("Number of columns: %d\n", col_count);

    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            char *value = csv_get_value(csv, i, j);
            printf("%s ", value);
        }
        printf("\n");
    }

    csv_close(csv);
    fclose(fp);
    return 0;
}