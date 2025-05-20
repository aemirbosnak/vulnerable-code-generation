//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_LINE_LEN 1024

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

void csv_read_file(CSV *csv, FILE *fp) {
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token!= NULL) {
            if (col >= csv->col) {
                csv->col += 10;
                csv->data[csv->row] = (char *)realloc(csv->data[csv->row], csv->col * sizeof(char));
            }
            strcpy(csv->data[csv->row][col], token);
            col++;
            token = strtok(NULL, ",");
        }
        csv->row++;
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
    CSV *csv = csv_create();
    FILE *fp = fopen("example.csv", "r");
    csv_read_file(csv, fp);
    fclose(fp);
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}