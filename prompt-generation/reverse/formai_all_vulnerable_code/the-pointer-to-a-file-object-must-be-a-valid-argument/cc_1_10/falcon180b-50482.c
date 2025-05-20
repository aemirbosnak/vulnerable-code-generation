//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int **data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csv_reader_create(FILE *fp) {
    char line[1024];
    int rows = 0, cols = 0;
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = NULL;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        rows++;
    }
    reader->rows = rows;
    reader->cols = cols;
    reader->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        reader->data[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            reader->data[i][j] = 0;
        }
    }
    rewind(fp);
    return reader;
}

void csv_reader_destroy(CSVReader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_get_int(CSVReader *reader, int row, int col) {
    return reader->data[row][col];
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSVReader *reader = csv_reader_create(fp);

    int sum = 0;
    for (int i = 0; i < reader->rows; i++) {
        for (int j = 0; j < reader->cols; j++) {
            int num = csv_reader_get_int(reader, i, j);
            sum += num;
        }
    }

    printf("Sum: %d\n", sum);

    csv_reader_destroy(reader);
    fclose(fp);
    return 0;
}