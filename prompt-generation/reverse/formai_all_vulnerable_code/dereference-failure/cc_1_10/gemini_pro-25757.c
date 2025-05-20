//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_read(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    csv_t *csv = malloc(sizeof(csv_t));
    if (csv == NULL) {
        fclose(fp);
        return NULL;
    }

    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, fp)) != -1) {
        csv->rows++;

        char *p = line;
        while (*p != '\0') {
            if (*p == ',') {
                csv->cols++;
            }
            p++;
        }
    }

    csv->data = malloc(csv->rows * sizeof(char *));
    if (csv->data == NULL) {
        fclose(fp);
        free(csv);
        return NULL;
    }

    rewind(fp);
    int row = 0;
    while ((nread = getline(&line, &len, fp)) != -1) {
        csv->data[row] = malloc(csv->cols * sizeof(char));
        if (csv->data[row] == NULL) {
            fclose(fp);
            for (int i = 0; i < row; i++) {
                free(csv->data[i]);
            }
            free(csv->data);
            free(csv);
            return NULL;
        }

        char *p = line;
        int col = 0;
        while (*p != '\0') {
            if (*p == ',') {
                csv->data[row][col] = '\0';
                col++;
            } else {
                csv->data[row][col] = *p;
            }
            p++;
        }
        csv->data[row][col] = '\0';

        row++;
    }

    fclose(fp);
    free(line);

    return csv;
}

void csv_free(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    csv_t *csv = csv_read("data.csv");
    if (csv == NULL) {
        fprintf(stderr, "Error reading CSV file\n");
        return 1;
    }

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    csv_free(csv);

    return 0;
}