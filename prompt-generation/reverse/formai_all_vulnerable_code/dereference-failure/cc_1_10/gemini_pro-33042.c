//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_new() {
    csv_t *csv = malloc(sizeof(csv_t));
    if (!csv) {
        return NULL;
    }
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_free(csv_t *csv) {
    if (!csv) {
        return;
    }
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_load(csv_t *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return -1;
    }
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        char *ptr = strtok(line, ",");
        int col = 0;
        while (ptr) {
            if (col >= csv->cols) {
                csv->data = realloc(csv->data, (csv->cols + 1) * sizeof(char *));
                if (!csv->data) {
                    fclose(fp);
                    free(line);
                    return -1;
                }
                csv->cols++;
            }
            csv->data[col] = strdup(ptr);
            if (!csv->data[col]) {
                fclose(fp);
                free(line);
                return -1;
            }
            col++;
            ptr = strtok(NULL, ",");
        }
        csv->rows++;
    }
    free(line);
    fclose(fp);
    return 0;
}

void csv_print(const csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s%c", csv->data[i][j], (j == csv->cols - 1) ? '\n' : ',');
        }
    }
}

int main() {
    csv_t *csv = csv_new();
    if (!csv) {
        return -1;
    }
    if (csv_load(csv, "data.csv") == -1) {
        csv_free(csv);
        return -1;
    }
    csv_print(csv);
    csv_free(csv);
    return 0;
}