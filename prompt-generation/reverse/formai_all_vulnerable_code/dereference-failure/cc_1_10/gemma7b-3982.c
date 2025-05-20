//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSV_Reader {
    FILE *fp;
    char **buffer;
    int buffer_size;
    int current_row;
    int current_column;
} CSV_Reader;

CSV_Reader *csv_reader_init(char *filename) {
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));

    reader->fp = fopen(filename, "r");
    if (reader->fp == NULL) {
        return NULL;
    }

    reader->buffer = NULL;
    reader->buffer_size = MAX_BUFFER_SIZE;
    reader->current_row = 0;
    reader->current_column = 0;

    return reader;
}

void csv_reader_read_next_row(CSV_Reader *reader) {
    char *line = NULL;
    size_t len = 0;

    getline(reader->fp, line, &len);

    if (line) {
        reader->current_row++;
        reader->buffer = realloc(reader->buffer, reader->buffer_size * reader->current_row);
        reader->buffer[reader->current_row - 1] = strdup(line);
    }
}

void csv_reader_close(CSV_Reader *reader) {
    fclose(reader->fp);
    free(reader->buffer);
    free(reader);
}

int main() {
    CSV_Reader *reader = csv_reader_init("data.csv");

    csv_reader_read_next_row(reader);

    printf("%s, %s, %s\n", reader->buffer[0], reader->buffer[1], reader->buffer[2]);

    csv_reader_close(reader);

    return 0;
}