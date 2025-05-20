//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 50

typedef struct CSV_Reader {
    char **data;
    int num_lines;
    int num_cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int num_lines, int num_cols) {
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->data = malloc(sizeof(char *) * num_lines);
    for (int i = 0; i < num_lines; i++) {
        reader->data[i] = malloc(sizeof(char) * num_cols);
    }
    reader->num_lines = num_lines;
    reader->num_cols = num_cols;
    return reader;
}

void csv_reader_free(CSV_Reader *reader) {
    for (int i = 0; i < reader->num_lines; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_get_num_lines(CSV_Reader *reader) {
    return reader->num_lines;
}

int csv_reader_get_num_cols(CSV_Reader *reader) {
    return reader->num_cols;
}

char **csv_reader_get_data(CSV_Reader *reader) {
    return reader->data;
}

int main() {
    CSV_Reader *reader = csv_reader_init(5, 3);
    reader->data[0][0] = 'a';
    reader->data[0][1] = 'b';
    reader->data[0][2] = 'c';
    reader->data[1][0] = 'd';
    reader->data[1][1] = 'e';
    reader->data[1][2] = 'f';

    printf("Number of lines: %d\n", csv_reader_get_num_lines(reader));
    printf("Number of columns: %d\n", csv_reader_get_num_cols(reader));
    printf("Data: \n");
    for (int i = 0; i < csv_reader_get_num_lines(reader); i++) {
        for (int j = 0; j < csv_reader_get_num_cols(reader); j++) {
            printf("%c ", csv_reader_get_data(reader)[i][j]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return 0;
}