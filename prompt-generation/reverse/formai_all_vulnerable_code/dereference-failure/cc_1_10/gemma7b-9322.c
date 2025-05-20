//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    char **buffer;
    int size;
    int current_row;
    FILE *file;
} CSVReader;

CSVReader *csv_reader_init(FILE *file) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->buffer = NULL;
    reader->size = 0;
    reader->current_row = 0;
    reader->file = file;

    return reader;
}

void csv_reader_read_next_row(CSVReader *reader) {
    char *line = NULL;
    int line_size = 0;

    getline(reader->file, line, &line_size);

    if (line) {
        reader->buffer = realloc(reader->buffer, (reader->size + 1) * MAX_BUFFER_SIZE);
        reader->buffer[reader->size++] = line;
    }

    reader->current_row++;
}

void csv_reader_finalize(CSVReader *reader) {
    free(reader->buffer);
    fclose(reader->file);
    free(reader);
}

int main() {
    FILE *file = fopen("test.csv", "r");
    CSVReader *reader = csv_reader_init(file);

    csv_reader_read_next_row(reader);
    csv_reader_read_next_row(reader);

    for (int i = 0; i < reader->size; i++) {
        printf("%s\n", reader->buffer[i]);
    }

    csv_reader_finalize(reader);

    return 0;
}