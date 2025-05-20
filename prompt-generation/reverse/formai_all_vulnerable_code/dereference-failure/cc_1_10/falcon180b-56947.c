//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

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
    if (csv->row >= MAX_ROW) {
        printf("Error: Maximum number of rows exceeded.\n");
        return;
    }
    csv->data[csv->row] = row;
    csv->row++;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    CSV *csv = csv_create();

    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            csv_add_row(csv, "");
        } else if (ch == ',') {
            csv_add_row(csv, "");
        } else {
            char *row = csv->data[csv->row - 1];
            int len = strlen(row);
            row[len] = ch;
            row[len + 1] = '\0';
        }
    }

    csv_print(csv);

    csv_destroy(csv);
    fclose(fp);

    return 0;
}