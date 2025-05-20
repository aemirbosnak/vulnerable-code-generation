//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Reader {
    char ***data;
    int rows;
    int cols;
} CSV_Reader;

CSV_Reader *create_csv_reader(int rows, int cols) {
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->data = malloc(sizeof(char ***) * rows);
    for (int i = 0; i < rows; i++) {
        reader->data[i] = malloc(sizeof(char **) * cols);
        for (int j = 0; j < cols; j++) {
            reader->data[i][j] = malloc(sizeof(char) * 256);
        }
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void free_csv_reader(CSV_Reader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        for (int j = 0; j < reader->cols; j++) {
            free(reader->data[i][j]);
        }
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSV_Reader *reader = create_csv_reader(MAX_ROWS, MAX_COLS);
    reader->data[0][0] = "John Doe";
    reader->data[0][1] = "123 Main St.";
    reader->data[1][0] = "Jane Doe";
    reader->data[1][1] = "456 Oak Ave.";

    printf("Name: %s\n", reader->data[0][0]);
    printf("Address: %s\n", reader->data[0][1]);

    free_csv_reader(reader);

    return 0;
}