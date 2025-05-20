//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
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
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        csv->rows++;

        char *token = strtok(line, ",");
        while (token != NULL) {
            csv->cols++;
            token = strtok(NULL, ",");
        }
    }

    csv->data = malloc(sizeof(char *) * csv->rows);
    if (csv->data == NULL) {
        fclose(fp);
        free(line);
        free(csv);
        return NULL;
    }

    rewind(fp);

    int row = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        csv->data[row] = malloc(sizeof(char) * csv->cols);
        if (csv->data[row] == NULL) {
            fclose(fp);
            free(line);
            for (int i = 0; i < row; i++) {
                free(csv->data[i]);
            }
            free(csv->data);
            free(csv);
            return NULL;
        }

        char *token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            strcpy(csv->data[row][col], token);
            col++;
            token = strtok(NULL, ",");
        }

        row++;
    }

    fclose(fp);
    free(line);

    return csv;
}

void csv_free(csv_t *csv) {
    if (csv == NULL) {
        return;
    }

    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    csv_t *csv = csv_read("data.csv");
    if (csv == NULL) {
        printf("Error reading CSV file.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    csv_free(csv);

    return EXIT_SUCCESS;
}