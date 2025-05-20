//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE *fp;
    char **buffer;
    int buffer_size;
    int current_row;
    int current_column;
} CSVReader;

CSVReader *csv_reader_init(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->buffer = NULL;
    reader->buffer_size = MAX_BUFFER_SIZE;
    reader->current_row = 0;
    reader->current_column = 0;

    return reader;
}

void csv_reader_read_next_row(CSVReader *reader) {
    reader->buffer = realloc(reader->buffer, reader->buffer_size * (reader->current_row + 1));
    reader->buffer[reader->current_row] = malloc(reader->buffer_size);

    char line[MAX_BUFFER_SIZE];
    fgets(line, MAX_BUFFER_SIZE, reader->fp);

    int column_count = 0;
    char *token = strtok(line, ",");
    while (token) {
        reader->buffer[reader->current_row][column_count++] = token;
        token = strtok(NULL, ",");
    }

    reader->current_row++;
}

void csv_reader_finalize(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->buffer);
    free(reader);
}

int main() {
    CSVReader *reader = csv_reader_init("example.csv");

    while (!feof(reader->fp)) {
        csv_reader_read_next_row(reader);
    }

    csv_reader_finalize(reader);

    return 0;
}