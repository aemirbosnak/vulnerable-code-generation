//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    CSV *csv = NULL;
    char line[MAX_LINE_LENGTH];
    char **data = NULL;
    int num_rows = 0;
    int num_columns = 0;

    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return NULL;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_rows == 0) {
            // Count number of columns in first row
            char *token = strtok(line, ",");
            while (token!= NULL) {
                num_columns++;
                token = strtok(NULL, ",");
            }
        }
        num_rows++;
    }

    data = malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        data[i] = malloc(num_columns * sizeof(char));
    }

    rewind(fp);
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        int column = 0;
        while (token!= NULL) {
            strcpy(data[num_rows - 1], token);
            token = strtok(NULL, ",");
            column++;
        }
        num_rows--;
    }

    csv = malloc(sizeof(CSV));
    csv->data = data;
    csv->num_rows = num_rows;
    csv->num_columns = num_columns;

    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}