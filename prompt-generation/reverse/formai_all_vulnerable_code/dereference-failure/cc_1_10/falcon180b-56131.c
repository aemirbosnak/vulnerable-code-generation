//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_LINE_LEN 10000

typedef struct {
    int rows;
    int cols;
    char **data;
} CSV;

CSV *read_csv(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char line[MAX_LINE_LEN];
    char *token;
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        csv->rows++;
        int cols = 0;
        char *row_data = strdup(line);
        token = strtok(row_data, ",");
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        csv->cols = cols;
        if (cols > 0) {
            csv->data = realloc(csv->data, sizeof(char *) * csv->cols);
            int i = 0;
            token = strtok(row_data, ",");
            while (token!= NULL) {
                csv->data[i] = strdup(token);
                i++;
                token = strtok(NULL, ",");
            }
        }
        free(row_data);
    }
    return csv;
}

void print_csv(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }
}

void free_csv(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i * csv->cols + j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    CSV *csv = read_csv(fp);
    fclose(fp);

    print_csv(csv);

    free_csv(csv);

    return 0;
}