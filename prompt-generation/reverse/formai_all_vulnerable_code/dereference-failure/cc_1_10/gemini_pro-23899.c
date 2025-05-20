//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
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
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        csv->rows++;

        char *data = strdup(line);
        char *saveptr;
        char *token = strtok_r(data, ",", &saveptr);
        while (token != NULL) {
            csv->cols++;
            csv->data = realloc(csv->data, csv->rows * csv->cols * sizeof(char *));
            csv->data[csv->rows * csv->cols - csv->cols] = strdup(token);
            token = strtok_r(NULL, ",", &saveptr);
        }
        free(data);
    }

    fclose(fp);

    return csv;
}

void csv_free(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i * csv->cols + j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main(void) {
    csv_t *csv = csv_read("data.csv");
    if (csv == NULL) {
        return -1;
    }

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }

    csv_free(csv);

    return 0;
}