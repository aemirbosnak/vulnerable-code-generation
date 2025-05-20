//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        if (cols > csv->cols) {
            csv->cols = cols;
        }
        if (csv->rows >= MAX_ROWS || csv->cols >= MAX_COLS) {
            fprintf(stderr, "Error: CSV file is too large.\n");
            exit(1);
        }
        csv->rows++;
    }

    csv->data = malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(csv->cols * sizeof(char));
    }

    rewind(fp);
    int row = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token!= NULL) {
            strcpy(csv->data[row], token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    CSV *csv = csv_open(argv[1]);
    csv_print(csv);
    csv_close(csv);

    return 0;
}