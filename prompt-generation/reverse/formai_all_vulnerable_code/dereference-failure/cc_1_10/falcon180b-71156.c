//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_read(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_columns = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (csv->num_rows == 0) {
            csv->num_columns = count_columns(line);
            csv->data = malloc(csv->num_columns * sizeof(char *));
        }

        char **row_data = csv->data;
        char *token = strtok(line, DELIMITER);
        int i = 0;

        while (token!= NULL) {
            row_data[i] = strdup(token);
            i++;
            token = strtok(NULL, DELIMITER);
        }

        csv->num_rows++;
    }

    return csv;
}

int count_columns(char *line) {
    int count = 0;
    char *token = strtok(line, DELIMITER);

    while (token!= NULL) {
        count++;
        token = strtok(NULL, DELIMITER);
    }

    return count;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[i * csv->num_columns + j]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            free(csv->data[i * csv->num_columns + j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    CSV *csv = csv_read(fp);
    if (csv == NULL) {
        printf("Error: Could not read CSV data.\n");
        return 1;
    }

    csv_print(csv);

    csv_free(csv);
    fclose(fp);

    return 0;
}