//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    char line[1024];
    while (fgets(line, 1024, file)!= NULL) {
        if (csv->data == NULL) {
            int count = 0;
            char *token = strtok(line, ",");
            while (token!= NULL) {
                count++;
                token = strtok(NULL, ",");
            }
            csv->cols = count;
            csv->data = malloc(csv->cols * sizeof(char*));
            memset(csv->data, 0, csv->cols * sizeof(char*));
        } else {
            int count = 0;
            char *token = strtok(line, ",");
            while (token!= NULL) {
                count++;
                token = strtok(NULL, ",");
            }
            if (count!= csv->cols) {
                printf("Error: number of columns does not match\n");
                exit(1);
            }
        }
        csv->rows++;
    }
    fclose(file);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

char *csv_get(CSV *csv, int row, int col) {
    return csv->data[row][col];
}

int main() {
    CSV *csv = csv_open("example.csv");
    int rows = csv->rows;
    int cols = csv->cols;
    printf("Number of rows: %d\n", rows);
    printf("Number of columns: %d\n", cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char *value = csv_get(csv, i, j);
            printf("%s ", value);
        }
        printf("\n");
    }
    csv_close(csv);
    return 0;
}