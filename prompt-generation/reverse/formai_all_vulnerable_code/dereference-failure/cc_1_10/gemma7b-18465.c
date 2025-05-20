//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: happy
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

CSV_Reader* csv_reader_init(int rows, int cols) {
    CSV_Reader* reader = malloc(sizeof(CSV_Reader));
    reader->data = malloc(sizeof(char ***) * rows);
    for (int r = 0; r < rows; r++) {
        reader->data[r] = malloc(sizeof(char**) * cols);
        for (int c = 0; c < cols; c++) {
            reader->data[r][c] = NULL;
        }
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_free(CSV_Reader* reader) {
    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            free(reader->data[r][c]);
        }
        free(reader->data[r]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSV_Reader* reader = csv_reader_init(5, 3);

    reader->data[0][0] = "John Doe";
    reader->data[0][1] = "New York";
    reader->data[0][2] = "123 Main St";

    reader->data[1][0] = "Jane Doe";
    reader->data[1][1] = "Los Angeles";
    reader->data[1][2] = "456 Oak Ave";

    reader->data[2][0] = "Bill Smith";
    reader->data[2][1] = "Chicago";
    reader->data[2][2] = "789 Park Ave";

    reader->data[3][0] = "Mary Johnson";
    reader->data[3][1] = "San Francisco";
    reader->data[3][2] = "912 California St";

    reader->data[4][0] = "Bob White";
    reader->data[4][1] = "Boston";
    reader->data[4][2] = "654 Washington St";

    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s ", reader->data[r][c]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}