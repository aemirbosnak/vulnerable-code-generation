//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROW 1000
#define MAX_COL 100
#define MAX_LINE 10000

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *csv_create(void) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROW * sizeof(char *));
    csv->row = 0;
    csv->col = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = malloc(MAX_COL * sizeof(char));
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

void csv_add_row(CSV *csv) {
    csv->data = realloc(csv->data, (csv->row + 1) * sizeof(char *));
    csv->data[csv->row] = malloc(MAX_COL * sizeof(char));
    csv->row++;
}

void csv_add_col(CSV *csv, char *value) {
    int len = strlen(value);
    if (csv->col + len >= MAX_COL) {
        csv_add_row(csv);
        csv->col = 0;
    }
    strcat(csv->data[csv->row - 1], value);
    csv->col += len;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        printf("%s\n", csv->data[i]);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE];
    CSV *csv = csv_create();

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            csv_add_col(csv, token);
            token = strtok(NULL, ",");
        }
        csv_add_row(csv);
    }

    csv_print(csv);

    csv_destroy(csv);
    fclose(fp);
    return 0;
}