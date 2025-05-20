//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
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

CSV* csv_create() {
    CSV *csv = (CSV*)malloc(sizeof(CSV));
    csv->data = (char**)malloc(MAX_ROW*sizeof(char*));
    csv->row = 0;
    csv->col = 0;
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
    char line[MAX_COL];
    while (fgets(line, MAX_COL, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token!= NULL) {
            if (csv->row >= MAX_ROW) {
                printf("Error: Too many rows.\n");
                exit(1);
            }
            if (csv->col >= MAX_COL) {
                printf("Error: Too many columns.\n");
                exit(1);
            }
            csv->data[csv->row] = (char*)realloc(csv->data[csv->row], (csv->col+1)*sizeof(char));
            strcpy(csv->data[csv->row]+csv->col, token);
            csv->col++;
            token = strtok(NULL, ",");
            col++;
        }
        csv->row++;
    }
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i]+j);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("test.csv", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    CSV *csv = csv_create();
    csv_read_file(csv, fp);
    csv_print(csv);

    csv_destroy(csv);
    fclose(fp);

    return 0;
}