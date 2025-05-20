//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
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

CSV* csv_create(void) {
    CSV *csv = (CSV*)malloc(sizeof(CSV));
    csv->data = (char**)malloc(MAX_ROW * sizeof(char*));
    csv->row = 0;
    csv->col = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char*)malloc(MAX_COL * sizeof(char));
        memset(csv->data[i], 0, MAX_COL);
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
        printf("Error: Maximum number of rows reached.\n");
        return;
    }
    csv->data[csv->row] = row;
    csv->row++;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        printf("%s\n", csv->data[i]);
    }
}

int main() {
    FILE *fp;
    char ch;
    CSV *csv = csv_create();

    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            csv_add_row(csv, csv->data[csv->row - 1]);
            csv->col = 0;
        } else if (ch == ',') {
            csv->data[csv->row - 1][csv->col] = '\0';
            csv->col++;
        } else {
            csv->data[csv->row - 1][csv->col++] = ch;
        }
    }

    fclose(fp);
    csv_add_row(csv, csv->data[csv->row - 1]);

    csv_print(csv);

    csv_destroy(csv);

    return 0;
}