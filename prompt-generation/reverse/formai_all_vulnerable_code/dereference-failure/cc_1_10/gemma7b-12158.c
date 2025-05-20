//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 20

typedef struct CSV_Reader {
    char ***data;
    int rows;
    int cols;
} CSV_Reader;

CSV_Reader* csv_reader_init() {
    CSV_Reader* reader = malloc(sizeof(CSV_Reader));
    reader->data = NULL;
    reader->rows = 0;
    reader->cols = 0;
    return reader;
}

void csv_reader_free(CSV_Reader* reader) {
    free(reader->data);
    free(reader);
}

void csv_reader_read(CSV_Reader* reader, char* csv_file) {
    FILE* file = fopen(csv_file, "r");
    if (file == NULL) {
        return;
    }

    reader->rows = 0;
    reader->cols = 0;

    char line[MAX_ROWS][MAX_COLS];
    char* token;
    int i, j;

    while (fgets(line[reader->rows], MAX_COLS, file) != NULL) {
        reader->rows++;
        token = strtok(line[reader->rows - 1], ",");
        reader->cols = 0;
        while (token) {
            reader->cols++;
            line[reader->rows - 1][reader->cols - 1] = token;
            token = strtok(NULL, ",");
        }
    }

    fclose(file);
}

int main() {
    CSV_Reader* reader = csv_reader_init();
    csv_reader_read(reader, "example.csv");

    int i, j;
    for (i = 0; i < reader->rows; i++) {
        for (j = 0; j < reader->cols; j++) {
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}