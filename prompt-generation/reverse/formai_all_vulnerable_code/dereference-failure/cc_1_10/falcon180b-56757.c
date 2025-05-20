//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_CELL_SIZE 1000

typedef struct {
    int rows;
    int cols;
    char **data;
} CSV;

CSV *csv_read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character
        if (csv->rows == 0) {
            int col_count = 0;
            char *token = strtok(line, ",");
            while (token!= NULL) {
                col_count++;
                token = strtok(NULL, ",");
            }
            csv->cols = col_count;
            csv->data = malloc(sizeof(char *) * csv->cols);
            for (int i = 0; i < csv->cols; i++) {
                csv->data[i] = malloc(MAX_CELL_SIZE);
            }
        } else {
            int col_count = 0;
            char *token = strtok(line, ",");
            while (token!= NULL) {
                strcpy(csv->data[col_count], token);
                col_count++;
                token = strtok(NULL, ",");
            }
        }
        csv->rows++;
    }

    fclose(fp);
    return csv;
}

void csv_print_data(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[j]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->cols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_read_file("data.csv");
    csv_print_data(csv);
    csv_free(csv);
    return 0;
}