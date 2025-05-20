//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(char *filename) {
    FILE *file = fopen(filename, "r");
    CSV *csv = malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;
    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        if (cols > csv->cols) {
            csv->cols = cols;
        }
        csv->rows++;
    }
    rewind(file);
    csv->data = malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(csv->cols * sizeof(char *));
    }
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < csv->rows; i++) {
        fgets(line, sizeof(line), file);
        char *token = strtok(line, ",");
        for (int j = 0; j < csv->cols; j++) {
            csv->data[i][j] = strdup(token);
            token = strtok(NULL, ",");
        }
    }
    fclose(file);
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_create("example.csv");
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
    csv_destroy(csv);
    return 0;
}