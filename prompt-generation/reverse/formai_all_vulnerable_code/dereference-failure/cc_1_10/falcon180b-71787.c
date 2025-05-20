//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_open(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[1024];
    csv_t *csv = malloc(sizeof(csv_t));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *ptr = strchr(line, '\n');
        if (ptr!= NULL) {
            *ptr = '\0';
        }
        csv->data = realloc(csv->data, sizeof(char *) * (csv->rows + 1));
        csv->data[csv->rows] = strdup(line);
        csv->rows++;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            csv->cols++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    csv->data = realloc(csv->data, sizeof(char *) * csv->rows);
    csv->cols = csv->cols / csv->rows;

    return csv;
}

void csv_close(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_rows(csv_t *csv) {
    return csv->rows;
}

int csv_get_cols(csv_t *csv) {
    return csv->cols;
}

char **csv_get_data(csv_t *csv) {
    return csv->data;
}

int main() {
    csv_t *csv = csv_open("data.csv");
    int rows = csv_get_rows(csv);
    int cols = csv_get_cols(csv);
    char **data = csv_get_data(csv);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", data[i]);
        }
        printf("\n");
    }

    csv_close(csv);
    return 0;
}