//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100

typedef struct CSVReader {
    FILE *fp;
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csv_reader_init(const char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->data = NULL;
    reader->rows = 0;
    reader->cols = 0;
    return reader;
}

void csv_reader_free(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->data);
    free(reader);
}

int csv_reader_get_num_rows(CSVReader *reader) {
    return reader->rows;
}

int csv_reader_get_num_cols(CSVReader *reader) {
    return reader->cols;
}

char **csv_reader_get_data(CSVReader *reader) {
    return reader->data;
}

int main() {
    CSVReader *reader = csv_reader_init("example.csv");
    int num_rows = csv_reader_get_num_rows(reader);
    int num_cols = csv_reader_get_num_cols(reader);
    char **data = csv_reader_get_data(reader);

    printf("Number of rows: %d\n", num_rows);
    printf("Number of columns: %d\n", num_cols);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s, ", data[i][j]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}