//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LEN 1024
#define MAX_COLUMNS 100
#define MAX_ROWS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    csv->num_rows = 0;
    csv->num_cols = 0;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            csv->num_cols++;
            token = strtok(NULL, DELIMITER);
        }
        csv->num_rows++;
    }

    csv->data = (char **)realloc(csv->data, csv->num_rows * sizeof(char *));
    rewind(fp);
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s", csv->data[i]);
            if (j < csv->num_cols - 1) {
                printf(DELIMITER);
            }
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    CSV *csv = csv_create(fp);
    csv_print(csv);

    csv_destroy(csv);
    fclose(fp);

    return 0;
}