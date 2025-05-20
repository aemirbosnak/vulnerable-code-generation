//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

/* Structure to hold CSV data */
typedef struct {
    int row;
    int col;
    char **data;
} CSV;

CSV *csv_create(int row, int col) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->row = row;
    csv->col = col;
    csv->data = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++) {
        csv->data[i] = (char *)malloc(col * sizeof(char));
        memset(csv->data[i], '\0', col);
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

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

CSV *csv_read_file(FILE *fp) {
    CSV *csv = csv_create(0, 0);
    char ch;
    int row = 0, col = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            row++;
            col = 0;
        } else if (ch == ',') {
            col++;
        } else {
            if (row >= MAX_ROW || col >= MAX_COL) {
                printf("Error: CSV data exceeds maximum size.\n");
                csv_destroy(csv);
                return NULL;
            }
            csv->data[row][col] = ch;
            col++;
        }
    }

    csv->row = row;
    csv->col = col;

    return csv;
}

int main() {
    FILE *fp;
    CSV *csv;

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    csv = csv_read_file(fp);
    if (csv == NULL) {
        fclose(fp);
        return 1;
    }

    csv_print(csv);

    csv_destroy(csv);
    fclose(fp);

    return 0;
}