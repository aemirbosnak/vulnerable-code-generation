//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int nrows;
    int ncols;
    char **data;
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

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, fp)) != -1) {
        csv->nrows++;
    }
    rewind(fp);

    csv->data = malloc(sizeof(char *) * csv->nrows);
    if (csv->data == NULL) {
        fclose(fp);
        free(csv);
        return NULL;
    }

    int row = 0;
    while ((nread = getline(&line, &len, fp)) != -1) {
        csv->data[row] = malloc(sizeof(char) * nread);
        if (csv->data[row] == NULL) {
            fclose(fp);
            for (int i = 0; i < row; i++) {
                free(csv->data[i]);
            }
            free(csv->data);
            free(csv);
            return NULL;
        }
        strcpy(csv->data[row], line);
        row++;
    }

    fclose(fp);
    free(line);

    return csv;
}

void csv_free(csv_t *csv) {
    for (int i = 0; i < csv->nrows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    csv_t *csv = csv_read("data.csv");
    if (csv == NULL) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < csv->nrows; i++) {
        for (int j = 0; j < csv->ncols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    csv_free(csv);

    return EXIT_SUCCESS;
}