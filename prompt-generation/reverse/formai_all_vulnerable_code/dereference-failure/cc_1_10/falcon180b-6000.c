//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

int read_csv(const char *filename, int **data, int *rows, int *cols) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_ROW];
    char *token;
    int count = 0;
    int row = 0;
    int col = 0;

    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    *cols = 0;

    while (fgets(line, MAX_ROW, fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            col++;
            if (row >= *rows) {
                *rows += MAX_ROW;
                *data = realloc(*data, sizeof(int) * (*rows) * (*cols));
            }
            if (col >= *cols) {
                *cols += MAX_COL;
                *data = realloc(*data, sizeof(int) * (*rows) * (*cols));
            }
            (*data)[row * (*cols) + col - 1] = atoi(token);
            token = strtok(NULL, ",");
            count++;
        }
        row++;
        count = 0;
    }

    fclose(fp);
    return 0;
}

void print_csv(int *data, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", data[i * cols + j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int *data = NULL;
    int rows = 0;
    int cols = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    read_csv(argv[1], &data, &rows, &cols);

    printf("CSV data:\n");
    print_csv(data, rows, cols);

    free(data);
    return 0;
}