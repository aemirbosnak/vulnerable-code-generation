//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1024

typedef struct CSVReader {
    FILE *fp;
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csv_reader_init(char *filename) {
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
    char *filename = "example.csv";
    CSVReader *reader = csv_reader_init(filename);

    if (reader) {
        printf("Number of rows: %d\n", csv_reader_get_num_rows(reader));
        printf("Number of columns: %d\n", csv_reader_get_num_cols(reader));

        char **data = csv_reader_get_data(reader);
        for (int r = 0; r < csv_reader_get_num_rows(reader); r++) {
            for (int c = 0; c < csv_reader_get_num_cols(reader); c++) {
                printf("%s ", data[r][c]);
            }
            printf("\n");
        }

        csv_reader_free(reader);
    }

    return 0;
}