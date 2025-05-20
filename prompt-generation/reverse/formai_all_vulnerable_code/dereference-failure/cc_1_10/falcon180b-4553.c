//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_read(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int rows = 0, cols = 0;
    char **data = NULL;
    char line[1024];

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            printf("Error: malformed CSV data\n");
            exit(1);
        }

        rows++;
        cols = 0;

        while (token!= NULL) {
            char *copy = strdup(token);
            data = realloc(data, sizeof(char *) * (rows * cols + 1));
            data[rows * cols] = copy;
            cols++;

            token = strtok(NULL, ",");
        }
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = data;
    csv->rows = rows;
    csv->cols = cols;

    fclose(file);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i * csv->cols + j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_read("example.csv");
    csv_print(csv);
    csv_free(csv);

    return 0;
}