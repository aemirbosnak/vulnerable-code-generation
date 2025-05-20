//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Reader {
    char **data;
    int rows;
    int cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int rows, int cols) {
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        reader->data[i] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_free(CSV_Reader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_read(CSV_Reader *reader, char *line) {
    int i = 0;
    char **parts = NULL;
    char *ptr = line;
    while (ptr && *ptr) {
        parts = realloc(parts, (i + 1) * sizeof(char *));
        parts[i++] = strdup(ptr);
        ptr += strcspn(ptr, ",") + 1;
    }
    reader->data[reader->rows - 1] = parts;
    return i;
}

int main() {
    CSV_Reader *reader = csv_reader_init(MAX_ROWS, MAX_COLS);
    char line[] = "John Doe,123 Main St,New York,NY 10001";
    csv_reader_read(reader, line);
    printf("%s, %s, %s, %s\n", reader->data[0][0], reader->data[0][1], reader->data[0][2], reader->data[0][3]);
    csv_reader_free(reader);
    return 0;
}