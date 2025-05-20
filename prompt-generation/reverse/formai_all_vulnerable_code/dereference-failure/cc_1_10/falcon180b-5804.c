//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
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

CSV *csv_create(void) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    csv->row = 0;
    csv->col = 0;

    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char *)malloc(MAX_COL * sizeof(char));
    }

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_add_row(CSV *csv, char *row) {
    csv->data[csv->row] = row;
    csv->row++;
}

int csv_get_col_count(CSV *csv) {
    int col_count = 0;
    char *row = csv->data[0];

    while (*row!= '\0') {
        if (*row == ',') {
            col_count++;
        }
        row++;
    }

    return col_count;
}

char *csv_get_cell(CSV *csv, int row, int col) {
    char *cell = csv->data[row];
    int i = 0;

    while (i < col) {
        if (*cell == ',') {
            cell++;
            i++;
        } else {
            cell++;
        }
    }

    return cell;
}

int main() {
    CSV *csv = csv_create();

    FILE *fp = fopen("example.csv", "r");
    char line[MAX_COL];

    while (fgets(line, MAX_COL, fp)!= NULL) {
        csv_add_row(csv, line);
    }

    fclose(fp);

    int col_count = csv_get_col_count(csv);

    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < col_count; j++) {
            char *cell = csv_get_cell(csv, i, j);
            printf("%s ", cell);
        }
        printf("\n");
    }

    csv_destroy(csv);

    return 0;
}