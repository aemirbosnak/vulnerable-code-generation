//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: safe
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
    CSV *csv = malloc(sizeof(CSV));
    csv->row = 0;
    csv->col = 0;
    csv->data = malloc(MAX_ROW * sizeof(char *));
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

void csv_read(CSV *csv, FILE *fp) {
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (csv->row >= MAX_ROW) {
            printf("Error: row limit reached.\n");
            break;
        }
        if (csv->col >= MAX_COL) {
            printf("Error: column limit reached.\n");
            break;
        }
        int len = strlen(line);
        if (len == 0) {
            csv->data[csv->row][csv->col] = '\0';
            csv->col++;
        } else if (line[len - 1] == '\n') {
            csv->data[csv->row][csv->col] = '\0';
            csv->col = 0;
            csv->row++;
        } else {
            strcat(csv->data[csv->row][csv->col], line);
            csv->col += strlen(line) - 1;
        }
    }
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        return 1;
    }
    CSV *csv = csv_create();
    csv_read(csv, fp);
    csv_print(csv);
    csv_destroy(csv);
    fclose(fp);
    return 0;
}