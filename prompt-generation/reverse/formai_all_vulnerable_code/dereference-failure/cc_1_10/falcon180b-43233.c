//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = malloc(MAX_COLUMNS * sizeof(char*));
    for (int i = 0; i < MAX_COLUMNS; i++) {
        csv->data[i] = malloc(MAX_LINE_SIZE);
    }
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_cols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read(CSV *csv, FILE *fp) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        char *token = strtok(line, DELIMITER);
        int col = 0;
        while (token!= NULL) {
            if (col >= csv->num_cols) {
                csv->num_cols++;
                csv->data[col] = malloc(MAX_LINE_SIZE);
            }
            strcpy(csv->data[col], token);
            token = strtok(NULL, DELIMITER);
            col++;
        }
        csv->num_rows++;
    }
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    CSV *csv = csv_create(fp);
    csv_read(csv, fp);
    csv_print(csv);
    csv_destroy(csv);
    fclose(fp);
    return 0;
}