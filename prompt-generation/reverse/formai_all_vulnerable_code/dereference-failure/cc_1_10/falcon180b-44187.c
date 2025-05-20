//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    char *token = strtok(line, DELIMITER);
    while (token!= NULL) {
        csv->cols++;
        token = strtok(NULL, DELIMITER);
    }
    csv->data = malloc(csv->cols * sizeof(char *));

    rewind(fp);
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int i = 0;
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            csv->data[i] = strdup(token);
            i++;
            token = strtok(NULL, DELIMITER);
        }
        csv->rows++;
    }

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i * csv->cols + j]);
        }
    }
    free(csv->data);
    free(csv);
}

int csv_get_rows(CSV *csv) {
    return csv->rows;
}

int csv_get_cols(CSV *csv) {
    return csv->cols;
}

char **csv_get_data(CSV *csv) {
    return csv->data;
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }

    CSV *csv = csv_create(fp);

    int rows = csv_get_rows(csv);
    int cols = csv_get_cols(csv);
    char **data = csv_get_data(csv);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", data[i * cols + j]);
        }
        printf("\n");
    }

    csv_destroy(csv);
    fclose(fp);

    return 0;
}